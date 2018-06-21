#include "qwebviewbackkey.h"
#include <QVBoxLayout>
#include <QPushButton>


QWebViewBackKey::QWebViewBackKey(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QVBoxLayout* pMain = new QVBoxLayout(centralWidget());
	QWebView* pWeb = new QWebView;
	pWeb->setUrl(QUrl::fromLocalFile("F:/WingyWork/Study2/QT/QWebViewBackKey/Resources/easyWeb.html"));
	bool isex = QFile::exists(("qrc:/Resources/easyWeb.html"));
	bool isex2 = QFile::exists("F:/WingyWork/Study2/QT/QWebViewBackKey/Resources/easyWeb.html");
	pMain->addWidget(pWeb);



	WebViewE* pWeb2 = new WebViewE;
	pMain->addWidget(pWeb2);


	QWebView* pWeb3 = new QWebView;
	pWeb3->setUrl(QUrl("http://www.163.com"));
	pWeb3->show();
}

QWebViewBackKey::~QWebViewBackKey()
{

}

WebViewE::WebViewE(QWidget* par /*= nullptr*/)
{
// 	QVBoxLayout* pMainLayout = new QVBoxLayout();
// 	setLayout(pMainLayout);
// 
// 	QPushButton* pBtn = new QPushButton;
// 	pBtn->setText("WebViewE");
// 	pMainLayout->addWidget(pBtn);

	setContextMenuPolicy(Qt::CustomContextMenu);
	setAcceptDrops(false);
	//setProperty("url", QVariant(QUrl(QStringLiteral("about:blank"))));
	setUrl(QUrl("http://blog.163.com"));

	page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
	page()->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
	page()->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
	
	//setUrl(QUrl("http:://www.baidu.com"));
	
}

WebViewE::~WebViewE()
{

}

void WebViewE::mousePressEvent(QMouseEvent*ev)
{
	setUrl(QUrl("http://www.qq.com"));
}
