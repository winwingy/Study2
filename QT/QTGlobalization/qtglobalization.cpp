#include "qtglobalization.h"
#include "QFileDialog"
#include "QMessageBox"

QTGlobalization::QTGlobalization(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
// 	QMenuBar* bar = new QMenuBar(this);
// 	QMenu* fileMenu = new QMenu(tr("&File"), bar);
// 	QAction* newFile = new QAction(tr("&New..."), fileMenu);
// 	fileMenu->addAction(newFile);
// 	QAction* openFile = new QAction(tr("&Open..."), fileMenu);
// 	fileMenu->addAction(openFile);
// 	setMenuBar(bar);

	QMenu* fileMenu = ui.menuBar->addMenu(tr("&File"));
	QAction* newFile = new QAction(tr("&New..."), fileMenu);
	fileMenu->addAction(newFile);
	QAction* openFile = new QAction(tr("&Open..."), fileMenu);
	fileMenu->addAction(openFile);

	connect(openFile, SIGNAL(triggered()), this, SLOT(fileOpen()));
}

QTGlobalization::~QTGlobalization()
{

}

void QTGlobalization::fileOpen()
{
	QFileDialog* fileDialog = new QFileDialog(this);
	fileDialog->setWindowTitle(tr("Open file"));
	fileDialog->setDirectory(".");
	if (fileDialog->exec() == QDialog::Accepted)
	{
		QString path = fileDialog->selectedFiles()[0];
		QMessageBox::information(nullptr, tr("Path"), tr("You selected\n%1").arg(path));
	}
	else
	{
		QMessageBox::information(nullptr, tr("Path"), tr("You didn't select any files"));
	}
}
