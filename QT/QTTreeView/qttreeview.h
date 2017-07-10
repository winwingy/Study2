#ifndef QTTREEVIEW_H
#define QTTREEVIEW_H

#include <QtWidgets/QMainWindow>
#include "ui_qttreeview.h"
#include "qstandarditemmodel.h"
#include "qtreeview.h"


class MyTreeView : public QTreeView
{
	Q_OBJECT
public:
	MyTreeView(QWidget* wid);
	~MyTreeView();
signals:
	void rightButtonClicked1(QPoint);
protected:
	virtual void mouseReleaseEvent(QMouseEvent *event) override;
private:
	QWidget* wid_;
};


class QTTreeView : public QMainWindow
{
	Q_OBJECT

public:
	QTTreeView(QWidget *parent = 0);
	~QTTreeView();
	void CreateTree();
	void _connect();
	void onViewClicked(const QModelIndex &index);
	void onViewDbClicked(const QModelIndex &index);
	void OnCustomContextMunu(const QPoint& pt);

protected:
	virtual bool eventFilter(QObject *, QEvent *) override;
// 
public slots:
 	void OnTreeViewRightButtonClicked(QPoint pt);
	void OnExitMenuTriggered(bool checked);
	void OnOpenMenuTriggered(bool checked);
private:
	Ui::QTTreeViewClass ui;
	QTreeView* view_;
	QStandardItemModel* model_;
};

#endif // QTTREEVIEW_H
