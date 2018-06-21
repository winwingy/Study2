#ifndef LABELMULTILINE_H
#define LABELMULTILINE_H

#include <QtWidgets/QMainWindow>
#include "ui_labelmultiline.h"
#include <QLabel>
#include <QLayout>
#include <QMouseEvent>

class CXsText : public QLabel
{
public:
	CXsText(QWidget* par = nullptr);
	~CXsText();
	virtual void setText(const QString& text);

private:
	void reset();
	void getLineText(const QString& strText, const QFontMetrics& fm, 
		const QRect& rcText, std::vector<QString>* textList);
	void generalLabelList(const std::vector<QString>& textList, const QRect& rcText);
	std::vector<QLabel*> m_labelList;
};

class LabelMultiLine : public QMainWindow
{
	Q_OBJECT

public:
	LabelMultiLine(QWidget *parent = 0);
	~LabelMultiLine();

private:
	virtual void mousePressEvent(QMouseEvent *ev) override;
	Ui::LabelMultiLineClass ui;
	CXsText* m_pLabel;
};

#endif // LABELMULTILINE_H
