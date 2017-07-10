#ifndef COMPOSITIONMODE_H
#define COMPOSITIONMODE_H

#include <QtWidgets/QMainWindow>
#include "ui_compositionmode.h"

class CompositionMode : public QMainWindow
{
	Q_OBJECT

public:
	CompositionMode(QWidget *parent = 0);
	~CompositionMode();

private:
	void paintEvent(QPaintEvent *e);
	bool nativeEvent( const QByteArray & eventType, void * message, long * result );
	Ui::CompositionModeClass ui;
};

#endif // COMPOSITIONMODE_H
