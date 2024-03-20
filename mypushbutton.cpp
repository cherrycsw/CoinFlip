#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>

//StartPushButton::StartPushButton(QWidget *parent) : QPushButton(parent)
//{

//}

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath=normalImg;
    this->pressedImgPath=pressImg;

    //创建Pixmap对象存放开始图片资源
    QPixmap pix;
    bool ret=pix.load(this->normalImgPath);
    if(!ret){
        qDebug()<<"图片加载失败！";
        return;
    }
    //设置按钮的大小 适应按钮图片大小
    setFixedSize(pix.width(),pix.height());
    //设置按钮的样式 将按钮的阴影边界和按钮图片的边界重合
    setStyleSheet("QPushButton{border:0px;}");
    //设置按钮图标，将按钮图片设置到按钮上
    setIcon(pix);
    //设置图标大小
    setIconSize(QSize(pix.width(),pix.height()));


}

//向上下跳跃函数实现
void MyPushButton::zomm(QString direction)
{
    //创建动画对象
    QPropertyAnimation *animation1=new QPropertyAnimation(this,"geometry");

    //设置时间间隔，单位毫秒
    animation1->setDuration(200);
    //向下跳
    if(direction=="down"){
        //创建起始位置
        animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

        //创建结束位置
        animation1->setEndValue(QRect(this->x(),this->y()+3,this->width(),this->height()));
    }else if(direction=="up"){//向下跳
        //创建起始位置
        animation1->setStartValue(QRect(this->x(),this->y()+3,this->width(),this->height()));

        //创建结束位置
        animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    }else{
        qDebug()<<"输入的弹跳方式有误！";
        return;
    }

    //设置缓和曲线 QEasingCurve::OutBounce为弹跳效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation1->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(!this->buttonStatus){
        return;
    }
    if(this->buttonStatus&&this->pressedImgPath!=""){//传入大的按下图片不为空 说明需要有按下状态 切换图片
        //创建Pixmap对象存放开始图片资源
        QPixmap pix;
        bool ret=pix.load(this->pressedImgPath);
        if(!ret){
            qDebug()<<"图片加载失败！";
            return;
        }
        //设置按钮的大小 适应按钮图片大小
        setFixedSize(pix.width(),pix.height());
        //设置按钮的样式 将按钮的阴影边界和按钮图片的边界重合
        setStyleSheet("QPushButton{border:0px;}");
        //设置按钮图标，将按钮图片设置到按钮上
        setIcon(pix);
        //设置图标大小
        setIconSize(QSize(pix.width(),pix.height()));
    }
    //让父类执行点击其他操作
    return QPushButton::mousePressEvent(e);

}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->buttonStatus&&this->pressedImgPath!=""){//传入大的按下图片不为空 说明需要有按下状态 切换初始图片
        //创建Pixmap对象存放开始图片资源
        QPixmap pix;
        bool ret=pix.load(this->normalImgPath);
        if(!ret){
            qDebug()<<"图片加载失败！";
            return;
        }
        //设置按钮的大小 适应按钮图片大小
        setFixedSize(pix.width(),pix.height());
        //设置按钮的样式 将按钮的阴影边界和按钮图片的边界重合
        setStyleSheet("QPushButton{border:0px;}");
        //设置按钮图标，将按钮图片设置到按钮上
        setIcon(pix);
        //设置图标大小
        setIconSize(QSize(pix.width(),pix.height()));
    }
    //让父类执行点击其他操作
    return QPushButton::mouseReleaseEvent(e);

}
