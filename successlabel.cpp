#include "successlabel.h"
#include<QPropertyAnimation>

SuccessLabel::SuccessLabel(QWidget *parent) : QLabel(parent)
{
    QPixmap pix;
    pix.load(":/res/LevelCompletedDialogBg.png");
    setPixmap(pix);
    resize(pix.width(),pix.height());
    setScaledContents(true);

}

//通关label弹出函数实现
void SuccessLabel::zoom()
{
    //创建动画对象
    QPropertyAnimation *animation1=new QPropertyAnimation(this,"geometry");

    //设置时间间隔，单位毫秒
    animation1->setDuration(1000);

    //创建起始位置
    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //创建结束位置
    animation1->setEndValue(QRect(this->x(),this->y()+this->height(),this->width(),this->height()));

    //设置缓和曲线 QEasingCurve::OutBounce为弹跳效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation1->start();

}




