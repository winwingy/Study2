/*
 * 圆周运动动画
 * */
#ifndef CircleAnimationWidget_H
#define CircleAnimationWidget_H

#include <QWidget>
#define PI  3.1415
class QPropertyAnimation;

class CircleAnimationWidget : public QWidget
{
    Q_OBJECT
    //注册属性,用于动画
    Q_PROPERTY(qreal percent READ percent WRITE setPercent)
public:
    explicit CircleAnimationWidget(QWidget *parent = 0);
    explicit CircleAnimationWidget(const QString &icon, \
                                   const qreal &radius, QWidget *parent = 0);
    void setCircleInfo(const QString &icon, const qreal &radius);
    void startAnimation();
    void stopAnimation();
    void setPercent(const qreal &per);
    const qreal &percent()
    {
        return m_percent;
    }
protected:
    void paintEvent(QPaintEvent *);
private slots:
    //更新坐标值
    void updatePos();
private:
    //计算坐标值
    QPoint mathPoint();
    QPoint mathPoint(const QPoint ¢erPos, const qreal &percent, const qreal &radius);
    void initAnimation();
private:
    qreal m_percent;//百分比
    qreal m_radius;//半径
    QPoint m_centerPos;//圆点坐标

    QPropertyAnimation *m_percentAnimation;
    QPixmap m_pix;
    QPoint m_point;//图片坐标
    QPoint m_originPoint;//图片原始坐标
};

#endif // CircleAnimationWidget_H
