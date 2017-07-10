#include "animation.h"
#include "qpushbutton.h"
#include "QPropertyAnimation"
#include "qnamespace.h"
#include "qevent.h"
#include "QSequentialAnimationGroup"
#include "QParallelAnimationGroup"
#include "QStateMachine"
#include "QSignalTransition"
#include "QtWebKit\qwebsettings.h"
#include "QtWebKitWidgets\qwebview.h"
#include "qboxlayout.h"
#include "qlabel.h"
#include "QTimeLine"
#include "qlogging.h"

Animation::Animation(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

}

Animation::~Animation()
{

}

class FlyHint : public QWidget
{
public:
	FlyHint(QWidget* par = 0):QWidget(par)
	{
		QHBoxLayout* layout = new QHBoxLayout(this);
		QLabel* label = new QLabel;
		label->setPixmap(QString("d:\\test\\20120510110846854.png"));
		layout->addWidget(label);
	}
	~FlyHint()
	{

	}


};

class QPropertyAnimationEx : public QPropertyAnimation
{
public:
	QPropertyAnimationEx(QObject *target, const QByteArray &propertyName, QObject *parent = 0)
		:QPropertyAnimation(target, propertyName, parent)
	{

	}
	~QPropertyAnimationEx()
	{

	}
};

void Animation::QTimeLineUse()
{
	QTimeLine* timeLine = new QTimeLine(10000);
	timeLine->setFrameRange(0, 100);
	connect(timeLine, &QTimeLine::frameChanged, [](int frameValue)
	{
		qDebug() << "frameValue" << frameValue;
	});
	timeLine->start();
}

class QVariantAnimationEx : public QVariantAnimation
{
public:
	QVariantAnimationEx(QObject* par):QVariantAnimation(par)
	{

	}

	~QVariantAnimationEx()
	{

	}
};

void Animation::onMyCircleRunAnimation()
{
	QPushButton* button = new QPushButton("Animated Button", this);
	button->setGeometry(100, 300, 100, 80);
	QRect targetRect(400, 100, 50, 30);
	button->show(); 

	{
		QVariantAnimation* animation = new QVariantAnimationEx(button);  
		animation->setDuration(2000);  
		animation->setStartValue(button->geometry().left());  
		animation->setEndValue(targetRect.left());
		animation->setEasingCurve(QEasingCurve::InOutBack);
		QObject::connect(animation, &QVariantAnimation::valueChanged, [button, targetRect]
		(const QVariant &value){
			QRect pos = button->geometry();
			pos.moveLeft(value.toInt());
			button->setGeometry(pos);

		});
		animation->start();  
	}

	{
		QVariantAnimation* animation = new QVariantAnimationEx(button);  
		animation->setDuration(2000);  
		animation->setStartValue(button->geometry().top());  
		animation->setEndValue(targetRect.top());
		animation->setEasingCurve(QEasingCurve::OutQuint);
		QObject::connect(animation, &QVariantAnimation::valueChanged, [button, targetRect]
		(const QVariant &value){
			QRect pos = button->geometry();
			pos.moveTop(value.toInt());
			button->setGeometry(pos);
		});
		animation->start(); 
	} 

}

void Animation::keyPressEvent(QKeyEvent *ev)
{
	switch(ev->key())
	{
	case Qt::Key_A:
		{
			QPushButton* btn = new QPushButton(this);
			btn->setGeometry(100, 100, 300, 100);
			btn->show();
			QPropertyAnimation* animation = new QPropertyAnimation(btn, "geometry", this);
			animation->setDuration(1000);
			animation->setStartValue(QRect(100, 100, 500, 100));
			animation->setEndValue(QRect(400, 200, 100, 100));
			animation->start();
			break;
		}
	case Qt::Key_B:
		{
			QPushButton* btn = new QPushButton(this);
			btn->setGeometry(100, 100, 300, 100);
			btn->show();
			QPropertyAnimation* animation = new QPropertyAnimation(btn, "geometry", this);
			animation->setDuration(10000);
			animation->setKeyValueAt(0.3, QRect(100, 100, 500, 100));
			animation->setKeyValueAt(0.4, QRect(1000, 100, 500, 100));
			animation->setKeyValueAt(0.8, QRect(100, 300, 500, 100));
			animation->setKeyValueAt(1.0, QRect(300, 300, 500, 100));
			animation->start();

			break;
		}
	case Qt::Key_C:
		{
			QPushButton* button = new QPushButton("Animated Button", this);  
			button->show();  
			QPropertyAnimation* animation = new QPropertyAnimation(button, "geometry", this);  
			animation->setDuration(3000);  
			animation->setStartValue(QRect(100, 100, 100, 30));  
			animation->setEndValue(QRect(450, 250, 100, 100));  
			static QEasingCurve::Type type = QEasingCurve::Linear;
			type = (QEasingCurve::Type)(type + 1);	
			animation->setEasingCurve(type); // 这里设置速度曲线  
			const char* p = qt_getEnumName(type);
			animation->start();  
			break;
		}
	case Qt::Key_D:
		{
			//串行动画
			QPushButton* button = new QPushButton("Animated Button", this);  
			button->show();  
			QPropertyAnimation* animation = new QPropertyAnimation(button, "geometry", this);  
			animation->setDuration(3000);  
			animation->setStartValue(QRect(100, 100, 100, 30));  
			animation->setEndValue(QRect(250, 150, 30, 100));  

			QPushButton* button2 = new QPushButton("Animated Button2", this);  
			button2->show();  
			QPropertyAnimation* animation2 = new QPropertyAnimation(button2, "geometry", this);  
			animation2->setDuration(3000);  
			animation2->setStartValue(QRect(100, 100, 100, 30));  
			animation2->setEndValue(QRect(450, 250, 100, 100));
			QSequentialAnimationGroup* group = new QSequentialAnimationGroup(this);
			group->addAnimation(animation);
			group->addAnimation(animation2);
			group->start();  
			break;
		}
	case Qt::Key_E:
		{
			//并行动画
			QPushButton* button = new QPushButton("Animated Button", this);  
			button->show();  
			QPropertyAnimation* animation = new QPropertyAnimation(button, "geometry", this);  
			animation->setDuration(3000);  
			animation->setStartValue(QRect(100, 100, 100, 30));  
			animation->setEndValue(QRect(250, 150, 30, 100));  

			QPushButton* button2 = new QPushButton("Animated Button2", this);  
			button2->show();  
			QPropertyAnimation* animation2 = new QPropertyAnimation(button2, "geometry", this);  
			animation2->setDuration(3000);  
			animation2->setStartValue(QRect(100, 100, 100, 30));  
			animation2->setEndValue(QRect(450, 250, 100, 100));
			QParallelAnimationGroup* group = new QParallelAnimationGroup(this);
			group->addAnimation(animation);
			group->addAnimation(animation2);
			group->start();  
			break;
		}
	case Qt::Key_F:
		{
			QPushButton *button = new QPushButton("Animated Button", this);  
			button->show();  
			QStateMachine *machine = new QStateMachine;  
			QState *state1 = new QState(machine);  
			state1->assignProperty(button, "geometry", QRect(0, 0, 100, 30));  
			machine->setInitialState(state1);  
			QState *state2 = new QState(machine);  
			state2->assignProperty(button, "geometry", QRect(250, 250, 100, 30));  
			QSignalTransition *transition1 = state1->addTransition(button,  
				SIGNAL(clicked()), state2);  
			transition1->addAnimation(new QPropertyAnimation(button, "geometry"));  
			QSignalTransition *transition2 = state2->addTransition(button,  
				SIGNAL(clicked()), state1);  
			transition2->addAnimation(new QPropertyAnimation(button, "geometry"));  
			machine->start();  
			break;
		}
		// play flash 
	case Qt::Key_G:
		{
			QWebSettings *settings = QWebSettings::globalSettings();  
			settings->setAttribute(QWebSettings::PluginsEnabled, true);  
			settings->setAttribute(QWebSettings::JavascriptEnabled, true);  
			QWebView *webView = new QWebView;  
			webView->load(QUrl("file:///D:\\test\\flash\\flash5471.swf"));  
			webView->show();
			break;
		}
	case Qt::Key_H:
		{
			onMyCircleRunAnimation();
			break;
		}
		// my test
	case Qt::Key_1:
		{
			QWidget* flyHint = new FlyHint();  
			flyHint->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint |
				Qt::WindowMinimizeButtonHint | Qt::Tool);
			flyHint->setAttribute(Qt::WA_TranslucentBackground);
			flyHint->setAttribute(Qt::WA_DeleteOnClose);
			flyHint->setWindowIcon(QIcon("D:\\test\\20120510110846854.png"));
			flyHint->show();  
			QPropertyAnimation* animation = new QPropertyAnimationEx(flyHint, "geometry", flyHint);  
			animation->setDuration(3000);  
			animation->setStartValue(QRect(100, 100, 100, 30));  
			animation->setEndValue(QRect(450, 250, 100, 100));  
			static QEasingCurve::Type type = QEasingCurve::Linear;
			type = (QEasingCurve::Type)(type + 1);	
			animation->setEasingCurve(type); // 这里设置速度曲线  
			QObject::connect(animation, &QPropertyAnimation::finished, [flyHint]()
			{
				flyHint->close();
			});
			animation->start(); 
			break;
		}
	case Qt::Key_2:
		{
			QWidget* flyHint = new FlyHint();  
			flyHint->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint |
				Qt::WindowMinimizeButtonHint | Qt::Tool);
			flyHint->setAttribute(Qt::WA_TranslucentBackground);
			flyHint->setAttribute(Qt::WA_DeleteOnClose);
			flyHint->setWindowIcon(QIcon("D:\\test\\20120510110846854.png"));
			flyHint->show();  
			QPropertyAnimation* animation = new QPropertyAnimationEx(flyHint, "geometry", flyHint);  
			animation->setDuration(3000);  
			animation->setStartValue(QRect(100, 100, 100, 30));  
			animation->setEndValue(QRect(450, 250, 100, 100));  
			static QEasingCurve::Type type = QEasingCurve::Linear;
			type = (QEasingCurve::Type)(type + 1);	
			animation->setEasingCurve(type); // 这里设置速度曲线  
			QObject::connect(animation, &QPropertyAnimation::finished, [flyHint]()
			{
				flyHint->close();
			});
			animation->start(); 
			break;
		}
	case Qt::Key_3:
		{
			QTimeLineUse();
			break;
		}

		
	}

	__super::keyPressEvent(ev);
}
