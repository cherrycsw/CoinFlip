#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include<QVector>
#include<coinbutton.h>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);

    //自定义构造函数
    PlayScene(int level);

    //绘图事件 画背景图片
    virtual void paintEvent(QPaintEvent *event);

    int playLevel;//关卡数

    QVector<CoinButton *> v_CoinBtn;//存储当前关数CoinButton按钮对象

    void sideReverseF(int i,int j);//金币旁边翻转槽函数

    void checkSuccessF();//检查通关函数

signals:
    //写一个自定义信号，告诉主场景点击了返回
    void playSceneBack();

    void sideReverse(int i,int j);//金币旁边翻转信号

    void checkSccess();//检查通关信号

};

#endif // PLAYSCENE_H
