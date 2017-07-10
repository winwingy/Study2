#include "clipregion.h"
#include "qpainter.h"

ClipRegion::ClipRegion(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

ClipRegion::~ClipRegion()
{

}

void ClipRegion::paintEvent(QPaintEvent *e)
{
	QPainter pter(this);
	QRegion region(this->rect(), QRegion::Ellipse);
	pter.setClipRegion(region);

	pter.setBrush(QBrush(QColor(Qt::green)));
	pter.drawRect(this->rect());

	__super::paintEvent(e);
}
