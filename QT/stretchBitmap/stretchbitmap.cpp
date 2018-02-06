#include "stretchbitmap.h"

stretchBitmap::stretchBitmap(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.widget->setStyleSheet(
		"border-image:"
		"url(D:/XSTeachMayi/xslive/resources/images/live/liveButtonCircle_3.png);"
		//"0 0 0 0 stretch;"
		"border-width: 2x; "
		"background:url(D:/XSTeachMayi/xslive/resources/images/main/accountant.png);"
		"background-color: rgba(0, 255, 0, 0.1);");


	ui.widget_2->setStyleSheet(		
		"border-image:"
		"url(D:/XSTeachMayi/xslive/resources/images/live/CXsTreasureToastBack.png) 30 80 35 30;"
		//"border-width: 13px;"	
		"border-top: 30 px;"	
		"border-right: 80 px;"		
		"border-bottom: 35 px;"	
		"border-left: 30 px;"
		//"border: 12px solid transparent;"
		//"background:url(D:/XSTeachMayi/xslive/resources/images/live/CXsTreasureToastBack.png);"
		"background-color: rgba(0, 255, 0, 0.1);"		
		);

	ui.widget_3->setStyleSheet(		
		//"background-image: url(D:/XSTeachMayi/xslive/resources/images/live/shieldmic_hover.png) no-repeat;"		

		"border-image:"
		"url(D:/XSTeachMayi/xslive/resources/images/live/liveButtonCircle_2.png) 11 11 11 11  ;"
		"border: 11px solid transparent;"
		//"border-width: 11px;"	
// 		"border-top: 11px;"	
// 		"border-right: 11px;"		
// 		"border-bottom: 11px;"	
// 		"border-left: 11px;"	
	
		//"round no-repeat no-repeat;"
		//"border-width: 12px;"	
		//"background:url(D:/XSTeachMayi/xslive/resources/images/live/vipRanking_1.png);"

		"background-color: rgba(0, 255, 0, 1);"
		//"background-color: url(D:/XSTeachMayi/xslive/resources/images/live/vipRanking_3.png);"
		);

	
}

stretchBitmap::~stretchBitmap()
{

}
