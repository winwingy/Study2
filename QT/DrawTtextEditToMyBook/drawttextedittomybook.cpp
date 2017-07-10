#include "drawttextedittomybook.h"

DrawTtextEditToMyBook::DrawTtextEditToMyBook(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

DrawTtextEditToMyBook::~DrawTtextEditToMyBook()
{

}



// ��һ�� ���� Document
void drawDocument(QPainter* painter, 
	const QTextDocument* doc,
	const QRectF& r,
	const QBrush& brush)
{
	if(doc->isEmpty())
		return;

	painter->save();
	// ���������
	if (r.isValid())
		painter->setClipRect(r, Qt::IntersectClip);

	QSizeF size = doc->size();
	QTextFrameFormat fmt = doc->rootFrame()->frameFormat();
	size.setWidth(size.width() - fmt.leftMargin() - fmt.rightMargin());
	for (QTextBlock bl = doc->begin(); bl != doc->end(); bl = bl.next())
	{
		// ��Ϊÿ��QTextBlock �а���һ��QTextLayout
		drawTextLayout(painter, bl, size , brush);
	}
	painter->restore();
}

//�ڶ��� ���� Layout 
void drawTextLayout(QPainter* painter, const QTextBlock& block, const QSizeF& sizeToFill, const QBrush& brush)
{
	if (!block.isValid())
		return;
	QTextLayout* layout = block.layout();
	if(!layout)
		return;
	if (layout->lineCount() < 1)
		return;

	// ���ߣ�ÿ����һ����Y����һ�е�λ�ã�X����
	QPointF baseLine = layout->position();
	baseLine.setY(baseLine.y() + layout->lineAt(0).ascent());

	// ���λ�ã��Ի���PosΪ�����������ƶ���ÿ�λ��У�����Xλ��
	QPointF outPos = baseLine;

	// QTextLayout ��һ���� QTextBlock..
	// QTextBlock ����һ������QTextFragment..
	QTextBlock::iterator it;
	for (it = block.begin(); !(it.atEnd()); ++it) 
	{	
		QTextFragment fragment = it.fragment();
		if (!fragment.isValid())
			continue;
		// ��ȡ�ı�
		QString text = fragment.text();
		if (text.isEmpty())
			continue;
		// ��ȡ�ı���ʽ
		QTextCharFormat chf = fragment.charFormat();
		int lineNoBegin = layout->lineForTextPosition(fragment.position() - 
			block.position()).lineNumber();
		int lineNoEnd = layout->lineForTextPosition(fragment.position() + 
			fragment.length() - 1 - block.position()).lineNumber();
		int j = fragment.position();
		for (int i = lineNoBegin; i <= lineNoEnd; i++)
		{
			QTextLine line = layout->lineAt(i);
			// �������λ��X
			qreal offset = alignPos(layout->textOption().alignment(), sizeToFill.width(), line.naturalTextWidth());
			outPos.setX(outPos.x() + offset);
			outPos.setY(baseLine.y());
			// ��ȡ���ڱ��е��ı�
			QString textOnLine;
			while(j < fragment.position() + fragment.length())
			{
				int c = block.position();
				int d = line.textStart() + line.textLength();
				if (j < c + d)
					textOnLine.append(text[j - fragment.position()]);
				else
					break;
				j++;
			}
			// �������ڱ��е�Fragment�е��ı�
			drawText(painter, outPos, textOnLine, chf, brush);
			// �л��еĻ���Ҫ����BaseLine��Y��outPos��X
			if(i < lineNoEnd)
			{
				// ���»���λ��Y
				baseLine.setY(baseLine.y() + line.height());
				outPos.setX(baseLine.x());
			}
		}
	}
}

// ������ ��������
void drawText(QPainter* painter, QPointF& p, QString& text, const QTextCharFormat& fmt,  const QBrush& brush)
{
	painter->setRenderHint(QPainter::Antialiasing, true);
	painter->setRenderHint(QPainter::TextAntialiasing, true);
	QFont f = fmt.font();
	f.resolve(QFont::AllPropertiesResolved);

	// ��õڸ����ֵĴ�С����
	QFontMetricsF fm(f);
	QRectF textBoundingRect = fm.boundingRect(text);
	// draw text
	if(needDrawText(fmt) || brush.style() != Qt::NoBrush)
	{		
		painter->setFont(f);
		QPen pen;
		if(brush.style() == Qt::NoBrush)
		{
			QBrush t = fmt.foreground();
			if (t.style() == Qt::NoBrush)
				pen.setBrush(QBrush(QColor(255,255,255)));
			else if(t.style() != Qt::SolidPattern)
				pen = QPen(t,0);
			else
			{
				QColor c = t.color();
				QColor cc = c.toRgb();
				pen.setBrush(QBrush(cc));
			}
		}
		else
		{
			if (brush.style() != Qt::SolidPattern)
				pen = QPen(brush, 0);
			else
			{	
				pen.setBrush(brush);
			}
		}
		painter->setPen(pen);
		// draw text.
		painter->drawText(p, text);
	}

	p += QPointF(textBoundingRect.width(), 0);
}
qreal alignPos(Qt::Alignment a, const qreal& width, const qreal& textWidth)
{
	if(a & Qt::AlignRight)
		return  width - textWidth;
	else if(!(a & Qt::AlignLeft))
		return (width - textWidth) / 2;
	return 0;
}
bool needDrawText(const QTextCharFormat& chf)
{
	return true;
}

void clearLetterSpacing(QTextDocument* doc, int* blockNum)
{
	bool bAllBlock = !blockNum ? true : false;
	QVector<QTextBlock> blocks;
	if (bAllBlock)
	{
		for(QTextBlock block = doc->begin(); block != doc->end(); block = block.next())
			blocks.push_back(block);
	}
	else
	{
		blocks.push_back(doc->findBlockByNumber(*blockNum));
	}
	// ����������ֵ��ּ��
	for(int idx = 0; idx < blocks.size(); idx++)	
	{
		QTextCursor cursor(blocks[idx]);
		for (int i = 0; i < blocks[idx].layout()->lineCount(); i++)
		{
			cursor.select(QTextCursor::LineUnderCursor);
			QTextCharFormat fmt;
			fmt.setFontLetterSpacing(100);
			cursor.mergeCharFormat(fmt);
			cursor.movePosition(QTextCursor::Down);
		}
	}
}
// ��QTextDocument�е�ָ��Block��Ϊ��ɢ���䷽ʽ��DocWidthΪ�޶����,ע�Ȿ�������ƻ�ԭ�е��ַ����
void adjustAlignJustify(QTextDocument* doc, qreal DocWidth, int* blockNum)
{
	// ������ֵ��ּ��
	clearLetterSpacing(doc, blockNum);
	// ��ȡҪ��ɢ�����Block
	bool bAllBlock = !blockNum ? true : false;
	QVector<QTextBlock> blocks;
	if (bAllBlock)
	{
		for(QTextBlock block = doc->begin(); block != doc->end(); block = block.next())
			blocks.push_back(block);
	}
	else
	{
		blocks.push_back(doc->findBlockByNumber(*blockNum));
	}
	// ��ȡLayout��Margin
	QTextFrameFormat frame = doc->rootFrame()->frameFormat();
	// ��ɢ����,�����ּ��
	for(int idx = 0; idx < blocks.size(); idx++)	
	{
		QTextCursor cursor(blocks[idx]);
		for (int i = 0; i < blocks[idx].layout()->lineCount(); i++)
		{
			QTextLine line = blocks[idx].layout()->lineAt(i);
			// �������һ���ֵĿ��
			cursor.setPosition(blocks[idx].position() + line.textStart() + line.textLength() - 1);
			cursor.setPosition(cursor.position() + 1, QTextCursor::KeepAnchor);
			QString text = cursor.selectedText();
			if (text.isEmpty())
			{
				cursor.movePosition(QTextCursor::Down);
				continue;
			}
			QFontMetricsF m(cursor.charFormat().font());
			qreal lastCharWidth = m.width(text[0]);
			// 	�����ַ����
			qreal widthOfLayout = DocWidth - (frame.leftMargin() + frame.rightMargin()) - lastCharWidth;
			qreal widthOfText = line.naturalTextRect().width() - lastCharWidth; 
			qreal percentOfSpacing = widthOfLayout / widthOfText * 100;
			if (percentOfSpacing > 100.0f)
			{
				// ѡ���һ���ֵ����һ���ֵ�ǰһ���֣�������Щ�ֵ��ּ��
				cursor.setPosition(blocks[idx].position());
				int pos = blocks[idx].position() + line.textStart() + line.textLength() - 1;
				cursor.setPosition(pos,  QTextCursor::KeepAnchor);
				QTextCharFormat fmt;
				fmt.setFontLetterSpacing(percentOfSpacing);
				cursor.mergeCharFormat(fmt);
			}
			cursor.movePosition(QTextCursor::Down);
		}
	}
}