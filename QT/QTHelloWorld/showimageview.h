#ifndef SHOWIMAGEVIEW_H
#define SHOWIMAGEVIEW_H

#include <QWidget>
#include "ui_showimageview.h"

class ShowImageView : public QWidget
{
	Q_OBJECT

public:
	ShowImageView(QWidget *parent = 0);
	~ShowImageView();

private:
	Ui::ShowImageView ui;
};

#endif // SHOWIMAGEVIEW_H
