#ifndef STARTPUSHBUTTON_H
#define STARTPUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include<QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit StartPushButton(QWidget *parent = nullptr);防止隐式类型转换来初始化
    //自定义有参构造函数
    MyPushButton(QString normalImg,QString pressImg="");

    //点击开始按钮 向上下跳跃函数
    void zomm(QString direction);

    //自定义属性
    QString normalImgPath;//默认显示图片路径
    QString pressedImgPath;//按下后显示图片路径

    //重写鼠标按下和释放事件
    void mousePressEvent(QMouseEvent *e);

    void mouseReleaseEvent(QMouseEvent *e);

    bool buttonStatus=true;

signals:

};

#endif // STARTPUSHBUTTON_H
