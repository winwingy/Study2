#ifndef STRETCHBITMAP_H
#define STRETCHBITMAP_H

#include <QtWidgets/QMainWindow>
#include "ui_stretchbitmap.h"

class stretchBitmap : public QMainWindow
{
	Q_OBJECT

public:
	stretchBitmap(QWidget *parent = 0);
	~stretchBitmap();

private:
	Ui::stretchBitmapClass ui;
};

#endif // STRETCHBITMAP_H
