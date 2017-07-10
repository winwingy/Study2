#ifndef QTGLOBALIZATION_H
#define QTGLOBALIZATION_H

#include <QtWidgets/QMainWindow>
#include "ui_qtglobalization.h"

class QTGlobalization : public QMainWindow
{
	Q_OBJECT

public:
	QTGlobalization(QWidget *parent = 0);
	~QTGlobalization();
	
private slots:
	void fileOpen();
private:
	Ui::QTGlobalizationClass ui;
};

#endif // QTGLOBALIZATION_H
