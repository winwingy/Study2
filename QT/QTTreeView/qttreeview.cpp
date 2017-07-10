#include "qttreeview.h"
#include <QStandardItemModel>
#include <QTreeView>
#include <functional>
#include <QDebug>
#include "qevent.h"
using namespace std;


MyTreeView::MyTreeView(QWidget* wid)
	: QTreeView(wid)
	, wid_(wid)
{

}

MyTreeView::~MyTreeView()
{

}
void MyTreeView::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::RightButton)
	{
		emit rightButtonClicked1(event->pos());
	}
	__super::mouseReleaseEvent(event);
}


QTTreeView::QTTreeView(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	CreateTree();
	_connect();
}

struct Teacher
{
	Teacher(const string& nameR, int ageR)
		: name(nameR), age(ageR)
	{

	}

	Teacher()
	{

	}

	~Teacher()
	{

	}
	string name;
	int age;
};

enum TreeViewRole
{
	TreeViewRole_teacher = Qt::UserRole + 10,
};

Q_DECLARE_METATYPE(shared_ptr<Teacher>)
void QTTreeView::CreateTree()
{
	QTreeView* view = new MyTreeView(this);
	view_ = view;
	view->setObjectName(QStringLiteral("QTreeViewStudy"));
	view->setGeometry(0, 0, 500, 400);
	view->setContextMenuPolicy(Qt::CustomContextMenu);
// 	connect(view, SIGNAL(customContextMenuRequested(const QPoint&)), this, 
// 		SLOT(OnCustomContextMunu(const QPoint&)));
	connect(view, SIGNAL(rightButtonClicked1(QPoint)), this, 
		SLOT(OnTreeViewRightButtonClicked(QPoint)));
	//view->installEventFilter(this);
	model_ = new QStandardItemModel(view);
	view->setModel(model_);
	
	model_->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("项目名")<<QStringLiteral("信息"));

	QStandardItem* itemProject = new QStandardItem(QIcon(QStringLiteral("D:/test/green.png")), 
		QStringLiteral("文件夹"));	
	model_->appendRow(itemProject);
	model_->setItem(model_->indexFromItem(itemProject).row(), 1, new QStandardItem(QStringLiteral("总的目录")));
	{
		QStandardItem* itemYuWen = new QStandardItem(QIcon(QStringLiteral("D:/test/green.png")), 
			QStringLiteral("语文"));
		itemProject->appendRow(itemYuWen);
		itemProject->setChild(itemYuWen->index().row(), 1, new QStandardItem(QStringLiteral("基本科目")));
		{
			{
				QStandardItem* childItem = new QStandardItem(QIcon(QStringLiteral("D:/test/app.png")),
					QStringLiteral("诗歌"));
				itemYuWen->appendRow(childItem);
				itemYuWen->setChild(childItem->index().row(), 1, new QStandardItem(QStringLiteral("五言诗歌")));
			}
			{
				QStandardItem* childItem = new QStandardItem(QIcon(QStringLiteral("D:/test/app.png")),
					QStringLiteral("散文"));
				itemYuWen->appendRow(childItem);
				itemYuWen->setChild(childItem->index().row(), 1, new QStandardItem(QStringLiteral("现代")));
			}
		}	
	}

	{
		QStandardItem* item = new QStandardItem(QIcon(QStringLiteral("D:/test/app.png")), 
			QStringLiteral("数学"));
		shared_ptr<Teacher> t(new Teacher("liufang", 32));
		item->setData(QVariant::fromValue(t), TreeViewRole_teacher);
		itemProject->appendRow(item);
		itemProject->setChild(item->index().row(), 1, new QStandardItem(QStringLiteral("小学数学")));
	}
	//view->



}

void QTTreeView::OnTreeViewRightButtonClicked(QPoint pt)
{
	OnCustomContextMunu(pt);
}

void QTTreeView::_connect()
{
	QTreeView* view = this->findChild<QTreeView*>(QStringLiteral("QTreeViewStudy"));
	QObject::connect(view, &QTreeView::clicked, this, &QTTreeView::onViewClicked);
	QObject::connect(view, &QTreeView::doubleClicked, this, &QTTreeView::onViewDbClicked);
		 //std::bind(&QTTreeView::onViewClicked, this, std::placeholders::_1));

}



void QTTreeView::onViewClicked(const QModelIndex &index)
{
	QStandardItem * item = model_->itemFromIndex(index);
	qDebug()<< index.row() << " " << index.column() << item->text();
	int a = 0;
}

void QTTreeView::onViewDbClicked(const QModelIndex &index)
{
	QStandardItem * item = model_->itemFromIndex(index);
	shared_ptr<Teacher> t = 
		(item->data(TreeViewRole_teacher)).value<shared_ptr<Teacher>>();
	if (!t)
	{
		return;
	}
	qDebug()<< index.row() << " " << index.column() << item->text()
		<< t->name.c_str() << t->age;
	

	int a = 0;
}

void QTTreeView::OnCustomContextMunu(const QPoint& pt)
{
	QMenu menu(this);
	QAction* a1 = new QAction(QStringLiteral("删除行"), this);
	connect(a1, &QAction::triggered,
		[&, pt](bool checked){
			QModelIndex index = view_->indexAt(pt);
			bool ok = model_->removeRows(index.row(), 1, index.parent());
			int a = 1;
		});
	QAction* a2 = new QAction(QStringLiteral("删除列"), this);
	connect(a2, &QAction::triggered, this, [&, pt](bool checked)
	{
		QModelIndex index = view_->indexAt(pt);
		QStandardItem* item = model_->itemFromIndex(index);
		qDebug() << item->row() << ", " <<item->column() << "  " << item->text();
		item->removeColumn(index.column());
		//bool ok = model_->removeColumns(index.column(), 1, index.parent());
		int a = 1;
	});
	menu.addAction(a1);
	menu.addAction(a2);
	menu.exec(view_->mapToGlobal(pt));
}

void QTTreeView::OnExitMenuTriggered(bool checked)
{

}

void QTTreeView::OnOpenMenuTriggered(bool checked)
{

}


QTTreeView::~QTTreeView()
{

}

bool QTTreeView::eventFilter(QObject * obj , QEvent * ev)
{
	if (obj == view_)
	{
		if (ev->type() == QEvent::MouseButtonRelease)
		{

		}
	}
	return __super::eventFilter(obj, ev);
}
