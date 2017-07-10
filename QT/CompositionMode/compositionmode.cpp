#include "compositionmode.h"
#include "QPainter"
#include <windows.h>
#include <WindowsX.h>

CompositionMode::CompositionMode(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setFixedSize(1500, 500);

	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	//setWindowFlags(Qt::CustomizeWindowHint/* | Qt::WindowMinimizeButtonHint*/);
	// QWidget透明显示，当设置主显示窗口的外边距时，防止外边距显示出来。
	setAttribute(Qt::WA_TranslucentBackground);

}

CompositionMode::~CompositionMode()
{

}

//重载 nativeEvent，实现窗体可拖动  
bool CompositionMode::nativeEvent( const QByteArray & eventType, void * message, long * result )  
{  
	const MSG* pMsg=static_cast<const MSG*>(message);  
	if(pMsg && pMsg->message == WM_NCHITTEST)  
	{  
		QPoint pos=QPoint(GET_X_LPARAM (pMsg->lParam), GET_Y_LPARAM (pMsg->lParam));  
		pos=mapFromGlobal(pos);  
		bool bRes=false;  

		if(this->geometry().contains(pos))  
		{  
			bRes=true;  

		}  

		if(bRes)  
			return QWidget::nativeEvent(eventType,message,result);  
		auto pChild=childAt(pos);  
		if(!pChild ||   
			(!pChild->inherits("QAbstractButton")&&  
			!pChild->inherits("QComboBox")&&  
			!pChild->inherits("QLineEdit")&&  
			pChild->objectName() != "qt_scrollarea_viewport"))  
		{  
			*result=HTCAPTION;  
			return true;  
		}  
	}  
	return QWidget::nativeEvent(eventType,message,result);  
}  

void CompositionMode::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	//painter.fillRect(rect(),  Qt::NoBrush);
	QRect rc(50, 50, 200, 80);
	QRect rcEll(70, 60, 150, 150);
	// default CompositionMode_SourceOver
// 	{
// 		painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
// 		painter.setBrush(QBrush(QColor(0, 0, 255, 125)));
// 		painter.setPen(Qt::NoPen);
// 		painter.drawRect(100, 100, 300, 200);
// 
// 		painter.setBrush(QBrush(QColor(250, 0, 0, 125)));
// 		painter.drawEllipse(200, 150, 200, 200);
// 	}

	//QPainter::CompositionMode_DestinationOver  等于之后画的没什么用
// 	{
// 		painter.setBrush(QBrush(QColor(0, 0, 255, 152)));
// 		painter.setPen(Qt::NoPen);
// 		painter.drawRect(100, 100, 300, 200);
// 
// 		painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
// 		painter.setBrush(QBrush(QColor(250, 0, 0, 120)));
// 		painter.drawEllipse(200, 150, 200, 200);
// 	}

	//QPainter::CompositionMode_Clear  之后画的是一团黑， 啥也没画
// 	{
// 		painter.setBrush(QBrush(QColor(0, 0, 255, 255)));
// 		painter.setPen(Qt::NoPen);
// 		painter.drawRect(100, 100, 300, 200);
// 
// 		painter.setCompositionMode(QPainter::CompositionMode_Clear);
// 		painter.setBrush(QBrush(QColor(250, 0, 0, 120)));
// 		painter.drawEllipse(200, 150, 200, 200);
// 	}

	//QPainter::CompositionMode_Source 和  CompositionMode_SourceOver 区别在于画的东西不透明了
// 	{
// 		painter.setBrush(QBrush(QColor(0, 0, 255, 125)));
// 		painter.setPen(Qt::NoPen);
// 		painter.drawRect(rc);
// 
// 		painter.setCompositionMode(QPainter::CompositionMode_Source);
// 		painter.setBrush(QBrush(QColor(250, 0, 0, 125)));
// 		painter.drawEllipse(rcEll);
// 	}

// 	{
// 		painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
// 		painter.setBrush(QBrush(QColor(0, 0, 255, 255)));
// 		painter.setPen(Qt::NoPen);
// 		painter.drawRect(rc);
// 
// 		painter.setCompositionMode(QPainter::CompositionMode_Xor);
// 		painter.setBrush(QBrush(QColor(250, 0, 0, 255)));
// 		painter.drawEllipse(rcEll);
// 	}
// 
// 	rc.translate(rc.width() + 20, 0);
// 	rcEll.translate(rcEll.width() + 20, 0);
// 	//QPainter::CompositionMode_SourceIn
// 	{
// 		painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
// 		painter.setBrush(QBrush(QColor(0, 0, 255, 125)));
// 		painter.setPen(Qt::NoPen);
// 		painter.drawRect(rc);
// 
// 		painter.setCompositionMode(QPainter::CompositionMode_Xor);
// 		painter.setBrush(QBrush(QColor(250, 0, 0, 125)));
// 		painter.drawEllipse(rcEll);
// 	}

	static QPixmap pixMask("D:\\test\\avatar_mask.png");

	{
		QPainter painter(this);
	 	painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
	 	painter.setBrush(QBrush(QColor(0, 0, 255, 255)));
	 	painter.setPen(Qt::NoPen);
	 	painter.drawRect(rc);
	 
	 	painter.setCompositionMode(QPainter::CompositionMode_Lighten);
	 	painter.setBrush(QBrush(QColor(250, 0, 0, 255)));
	 	painter.drawEllipse(rcEll);

		painter.setCompositionMode(QPainter::CompositionMode_Lighten);
		painter.setBrush(QBrush(QColor(250, 0, 0, 255)));
		painter.drawPixmap(rcEll.left(), rcEll.top(), pixMask);
	}
	 
	rc.translate(rc.width()*1.5, 0);
	rcEll.translate(rc.width()*1.5, 0);
	//QPainter::CompositionMode_SourceIn
	{
		QPainter painter(this);
	 	painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
	 	painter.setBrush(QBrush(QColor(0, 0, 255, 255)));
	 	painter.setPen(Qt::NoPen);
	 	painter.drawRect(rc);
	 
	 	painter.setCompositionMode(QPainter::CompositionMode_Lighten);
	 	painter.setBrush(QBrush(QColor(250, 0, 0, 125)));
	 	painter.drawEllipse(rcEll);

		painter.setCompositionMode(QPainter::CompositionMode_Lighten);
		painter.setBrush(QBrush(QColor(250, 0, 0, 255)));
		painter.drawPixmap(rcEll.left(), rcEll.top(), pixMask);
	}

	rc.translate(rc.width()*1.5, 0);
	rcEll.translate(rc.width()*1.5, 0);
	//QPainter::CompositionMode_SourceIn
	{
		QPainter painter(this);
		painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
		painter.setBrush(QBrush(QColor(0, 0, 255, 125)));
		painter.setPen(Qt::NoPen);
		painter.drawRect(rc);

		painter.setCompositionMode(QPainter::CompositionMode_Lighten);
		painter.setBrush(QBrush(QColor(250, 0, 0, 255)));
		painter.drawEllipse(rcEll);

		painter.setCompositionMode(QPainter::CompositionMode_Lighten);
		painter.setBrush(QBrush(QColor(250, 0, 0, 255)));
		painter.drawPixmap(rcEll.left(), rcEll.top(), pixMask);
	}

	rc.translate(rc.width()*1.5, 0);
	rcEll.translate(rc.width()*1.5, 0);
	//QPainter::CompositionMode_SourceIn
	{
		QPainter painter(this);
		painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
		painter.setBrush(QBrush(QColor(0, 0, 255, 125)));
		painter.setPen(Qt::NoPen);
		painter.drawRect(rc);

		painter.setCompositionMode(QPainter::CompositionMode_Lighten);
		painter.setBrush(QBrush(QColor(250, 0, 0, 125)));
		painter.drawEllipse(rcEll);

		painter.setCompositionMode(QPainter::CompositionMode_Lighten);
		painter.setBrush(QBrush(QColor(250, 0, 0, 255)));
		painter.drawPixmap(rcEll.left(), rcEll.top(), pixMask);
	}



}
