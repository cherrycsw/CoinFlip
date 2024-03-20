#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <QMainWindow>
#include<mypushbutton.h>
#include<playscene.h>

class ChooseScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseScene(QWidget *parent = nullptr);

    //绘图事件 画背景图片
    virtual void paintEvent(QPaintEvent *event);

    //游戏界面对象
    PlayScene *play=NULL;
//    //存储MyPushButton的容器
//    QVector<MyPushButton> v;


signals:
    //写一个自定义信号，告诉主场景点击了返回
    void chooseSceneBack();

};

#endif // CHOOSESCENE_H
