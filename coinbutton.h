#ifndef COINBUTTON_H
#define COINBUTTON_H

#include <QPushButton>

class CoinButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit CoinButton(QWidget *parent = nullptr);
    //CoinButton();

    //自定义构造函数
    CoinButton(int x,int y,QString name);

    //按钮在游戏矩阵界面的位置
    int coinX;
    int coinY;
    QString coinName;//金币还是银币
    bool buttonStatus=true;

    //翻转动画函数
    void reverse();

    //记录金银币图片地址的索引
    int index=0;

    //金银币图片地址的索引+1槽函数
    void addIndex();

    //鼠标按下事件
    virtual void mousePressEvent(QMouseEvent *event);

    //鼠标释放事件
    //virtual void mouseReleaseEvent(QMouseEvent *event);


signals:
    void add();//金银币图片地址的索引+1信号

};

#endif // COINBUTTON_H
