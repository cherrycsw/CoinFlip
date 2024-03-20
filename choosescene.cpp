#include "choosescene.h"
#include<QMenuBar>
#include<QAction>
#include<QMenu>
#include<QAction>
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
#include<QLabel>
#include<QDebug>
#include<QWidget>
#include<playscene.h>
#include<QSound>

ChooseScene::ChooseScene(QWidget *parent) : QMainWindow(parent)
{
    //设置窗口固定大小
    setFixedSize(390,592);
    //设置窗口图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置窗口title
    setWindowTitle("老王带你翻金币");

    //创建菜单栏
    QMenuBar *menuBar=new QMenuBar(this);
    menuBar->setFixedSize(390,22);
    QMenu *menu1=menuBar->addMenu("开始");
    QAction *quitAction=menu1->addAction("退出");

    //菜单栏退出功能实现
    connect(quitAction,&QAction::triggered,this,&QMainWindow::close);

    //设置返回按钮
    MyPushButton *btn1=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    btn1->setParent(this);
    btn1->move(this->width()-btn1->width(),560);

    //返回音效创建
    QSound *backSound=new QSound(":/res/BackButtonSound.wav",this);

    //点击返回按钮
    connect(btn1,&QPushButton::clicked,[=](){
        backSound->play();//点击返回音效播放
        //点击返回按钮动画 在MyPushButton的点击和释放事件中完成（点击则切换图片 释放则还原图片）
        //返回功能实现
        QTimer::singleShot(500,this,[=](){
            emit this->chooseSceneBack();//发送返回信号
        });
    });
    //选择音效创建
    QSound *chooseSound=new QSound(":/res/TapButtonSound.wav",this);

    //选择关卡按钮
    for(int i=0;i<20;i++){
        MyPushButton *selectBtn=new MyPushButton(":/res/LevelIcon.png");
        selectBtn->setParent(this);
        //创建数字Lable 并将label放置在selectButton上
        QLabel *label=new QLabel(QString::number(i+1),selectBtn);
        label->resize(selectBtn->width(),selectBtn->height());//lable设置成selectBtn一样大小
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);//设置文字水平垂直居中
        label->setFont(QFont("微软雅黑", 10, 75));//字体加粗
        selectBtn->move(this->width()*0.5-2*selectBtn->width()+(i%4)*selectBtn->width(),150+(i/4)*selectBtn->height());//移动算法 形成矩阵 x坐标每轮都移动button宽度，每隔四轮回到起始点，y坐标每隔四轮移动button高度，单位轮数中y坐标保持不变
        //监听每个按钮的点击事件
        connect(selectBtn,&QPushButton::clicked,[=](){
            chooseSound->play();//点击选择关卡音效播放
            selectBtn->zomm("down");
            selectBtn->zomm("up");
            qDebug()<<"你选择的是第"<<i+1<<"关";

            //创建对应的playScene界面
            play=new PlayScene(i+1);
            //play->setParent(this);
            QTimer::singleShot(500,this,[=](){
                this->hide();
                play->setGeometry(this->geometry());
                play->show();
            });
            //监听返回信号
            connect(play,&PlayScene::playSceneBack,[=](){
                this->setGeometry(play->geometry());
                delete play;//游戏界面删除
                play=NULL;
                this->show();//选择界面重新显示
            });
        });

    }







}

void ChooseScene::paintEvent(QPaintEvent *event)
{
    //centralWidget背景设置
    QPainter painter(this);
    painter.drawPixmap(0,22,QPixmap(":/res/OtherSceneBg.png"));//22为菜单栏的高度

    //画背景图标
    QPixmap pix1;
    pix1.load(":/res/Title.png");
    pix1=pix1.scaled(pix1.width(),pix1.height());//不放大
    painter.drawPixmap(this->width()*0.5-pix1.width()*0.5,22,pix1);//放中间
}
