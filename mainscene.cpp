#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include<QPixmap>
#include<QToolButton>
#include"mypushbutton.h"
#include<QDebug>
#include<QTimer>
#include"choosescene.h"
#include<QSound>
#include<QMediaPlayer>
#include<QMediaPlaylist>

QMediaPlayer* MainScene::backgMusic=NULL;//静态成员变量类内申明 类外定义

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //设置窗口固定大小
    setFixedSize(390,592);
    //设置窗口图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置窗口title
    setWindowTitle("老王带你翻金币");
    //菜单栏退出功能实现
    connect(ui->actionquit,&QAction::triggered,this,&QMainWindow::close);

    //设置开始按钮
    MyPushButton *startBtn=new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(143,380);

    //选择关卡界面对象创建
    ChooseScene *chooseScene=new ChooseScene(this);

    //游戏背景音效
    // 创建QMediaPlaylist对象
    QMediaPlaylist *playlist = new QMediaPlaylist(this);
    // 加载音频文件
    playlist->addMedia(QUrl("qrc:/res/myDouDZ.wav"));
    // 设置循环播放
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    // 创建QMediaPlayer对象

    this->backgMusic = new QMediaPlayer(this);
    this->backgMusic->setPlaylist(playlist);//将QMediaPlayer对象加到QMediaPlaylist中
    this->backgMusic->play();//播放

    //监听返回信号
    connect(chooseScene,&ChooseScene::chooseSceneBack,[=](){
        chooseScene->hide();//选择关卡界面隐藏
        this->setGeometry(chooseScene->geometry());//选择场景点击返回按钮时，将主场景的窗口位置设置成与选择窗口一样
        this->show();//主界重新显示
    });

    //点击开始按钮弹起特效 方式一：利用定时器实现
//    connect(startBtn,&QPushButton::clicked,[=](){
//        qDebug()<<"点击了开始！";
//        startBtn->move(startBtn->x(),startBtn->y()+3);
//        QTimer *timer=new QTimer(this);
//        timer->start(100);
//        connect(timer,&QTimer::timeout,[=](){
//            startBtn->move(startBtn->x(),startBtn->y()-3);
//            timer->stop();
//        });

//    });
    //点击开始按钮弹起特效  方式二：利用动画实现
    //开始音效创建
    QSound *startSound=new QSound(":/res/TapButtonSound.wav",this);

    connect(startBtn,&QPushButton::clicked,[=](){
        startSound->play();//点击开始音效播放
        qDebug()<<"点击了开始！";
        startBtn->zomm("down");//向下跳
        startBtn->zomm("up");//向上跳

        //点击开始0.5秒钟后 ChooseScene界面出现
        QTimer::singleShot(500,this,[=](){
            this->hide();//主界面隐藏
            chooseScene->setGeometry(this->geometry());
            chooseScene->show();//弹出ChooseScene界面
        });

    });



}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *event)
{
    //centralWidget背景设置
    QPainter painter(this);
    painter.drawPixmap(0,22,QPixmap(":/res/MenuSceneBg.png"));//22为菜单栏的高度

    //画背景图标
    QPixmap pix1;
    pix1.load(":/res/Title.png");
    pix1=pix1.scaled(pix1.width()*0.8,pix1.height()*0.8);//缩小0.8
    painter.drawPixmap(0,22,pix1);


}

