#ifndef DRAWTTEXTEDITTOMYBOOK_H
#define DRAWTTEXTEDITTOMYBOOK_H

#include <QtWidgets/QMainWindow>
#include "ui_drawttextedittomybook.h"

class DrawTtextEditToMyBook : public QMainWindow
{
	Q_OBJECT

public:
	DrawTtextEditToMyBook(QWidget *parent = 0);
	~DrawTtextEditToMyBook();

private:
	Ui::DrawTtextEditToMyBookClass ui;
};



// 绘制QTextDocument中的指定区域
void drawDocument(QPainter* painter, 
	const QTextDocument* doc,
	const QRectF& r,
	const QBrush& brush = Qt::NoBrush/*brush to draw all content.used for shadow draw*/);
// 绘制Block及其内容
void drawTextLayout(QPainter* painter, 
	const QTextBlock& block, 
	const QSizeF& sizeToFill,
	const QBrush& brush);
// 绘制文本及其内外边
void drawText(QPainter* painter, 
	QPointF& p, 
	QString& text, 
	const QTextCharFormat& fmt,  
	const QBrush& brush);
qreal alignPos(Qt::Alignment a, 
	const qreal& width, 
	const qreal& textWidth);
bool needDrawText(const QTextCharFormat& chf);
void clearLetterSpacing(QTextDocument* doc, int* blockNum = NULL);
void adjustAlignJustify(QTextDocument* doc, qreal DocWidth, int* blockNum = NULL);


#endif // DRAWTTEXTEDITTOMYBOOK_H
