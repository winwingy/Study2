#include "labelmultiline.h"
#include <QFontMetrics>
#include <QVBoxLayout>

#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif


CXsText::CXsText(QWidget* par /*= nullptr*/)
{

}

CXsText::~CXsText()
{

}

void CXsText::getLineText(const QString& strTextOrc, const QFontMetrics& fm, 
	const QRect& rcText, std::vector<QString>* textList)
{	
	QString strText(strTextOrc);
	strText.replace("\r\n", "\r");
	strText.replace("\n", "\r");
	strText.replace("\r", "\r\n");
	QStringList newLineList = strText.split("\n");

	foreach(const QString& perNewLine, newLineList)
	{
		int posLast = 0;
		while(1)
		{
			QString lineText(perNewLine.mid(posLast, -1));
			bool hasAdd = false;
			for (int pos = 0; pos < lineText.length(); ++pos)
			{
				QString perText(lineText.mid(0, pos + 1));
				QRect rcLine = fm.boundingRect(rcText, Qt::TextSingleLine, perText);
				int wid = rcLine.width();
				if (wid > rcText.width())
				{
					QString perText = lineText.mid(0, pos);
					textList->push_back(perText);
					posLast += pos;
					hasAdd = true;
					break;
				}
			}
			if (!hasAdd)
			{
				textList->push_back(lineText);
				break;
			}
		}
	}	

	for (auto iter = textList->begin(); iter != textList->end();)
	{
		if (iter->size() == 0)
			iter = textList->erase(iter);
		else
			++iter;
	}

	int textHeight = 0;
	QString lastStr;
	for (auto iter = textList->begin(); iter != textList->end(); ++iter)
	{
		QRect rcLine = fm.boundingRect(rcText, Qt::TextSingleLine, *iter);
		textHeight += rcLine.height();
		if (textHeight > rcText.height())
		{
			auto iterCp = iter;
			for (; iter != textList->end(); ++iter)
			{
				lastStr += *iter;
			}
			textList->erase(iterCp, textList->end());
			break;
		}
		textHeight += fm.leading();
	}
	if (textList->empty())
	{
		textList->push_back(lastStr);
	}
	else
	{
		*(textList->end() - 1) += lastStr;
	}
}

void CXsText::generalLabelList(const std::vector<QString>& textList, const QRect& rcText)
{
	QVBoxLayout* pLayout = static_cast<QVBoxLayout*>(layout());
	QFontMetrics fm = fontMetrics();
	if (!pLayout)
	{
		pLayout = new QVBoxLayout(this);
		pLayout->setMargin(margin());
		pLayout->setSpacing(0);
		//pLayout->setSpacing(fm.lineSpacing());
	}

	reset();

	for (auto iter2 = textList.begin(); iter2 != textList.end(); ++iter2)
	{
		QLabel* pLabel = new QLabel;
		pLabel->setObjectName(this->objectName());
		if (iter2 == textList.end() -1)
		{
			QString elideText = fm.elidedText(*iter2, Qt::ElideRight, rcText.width());
			pLabel->setText(elideText);
		}
		else
		{
			pLabel->setText(*iter2);
		}
		pLayout->addWidget(pLabel);
		m_labelList.push_back(pLabel);
	}
}

void CXsText::setText(const QString& str)
{
	reset();
	bool hasMutiElide = false;
	do 
	{
		if (!wordWrap() || hasScaledContents())
			break;

		QFontMetrics fm = fontMetrics();
		QRect rcText = rect();
		int mar = margin();
		rcText.adjust(mar, mar, -mar, -mar);
		QRect rcNew = fm.boundingRect(rcText, Qt::TextWordWrap, str);
		if (rcNew.height() <= rcText.height())
			break;

		std::vector<QString> textList;
		getLineText(str, fm, rcText, &textList);
		generalLabelList(textList, rcText);
		hasMutiElide = true;
	} while (0);

	if (!hasMutiElide)
	{
		__super::setText(str);
	}
	else
	{
		__super::setText("");
	}
}

void CXsText::reset()
{
	QLayout* pLayout = layout();
	if (pLayout)
	{
		for (auto iter = m_labelList.begin(); iter != m_labelList.end(); ++iter)
		{
			pLayout->removeWidget(*iter);
			(*iter)->deleteLater();
		}
		m_labelList.clear();
	}
}

LabelMultiLine::LabelMultiLine(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_pLabel = new CXsText;
	m_pLabel->setFixedSize(100, 40);
	m_pLabel->setStyleSheet("background:#ff0000;");
	m_pLabel->setWordWrap(true);
	
	layout()->addWidget(m_pLabel);
}

LabelMultiLine::~LabelMultiLine()
{

}

void LabelMultiLine::mousePressEvent(QMouseEvent *ev)
{
	m_pLabel->setText("Qt动态添加删除控件的方法_百度经验 qt中删除布局内的子控件-CSDN问答");
	m_pLabel->setText("Qt动态添加");
}
