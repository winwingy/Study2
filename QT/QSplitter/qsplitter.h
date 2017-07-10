#ifndef QSPLITTER_H
#define QSPLITTER_H

#include <QtWidgets/QMainWindow>
#include "ui_qsplitter.h"

class QSplitter : public QMainWindow
{
	Q_OBJECT

public:
	QSplitter(QWidget *parent = 0);
	~QSplitter();

private:
	Ui::QSplitterClass ui;
};

#endif // QSPLITTER_H
