#include "playscene.h"
#include<QPainter>
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
#include<coinbutton.h>
#include<dataconfig.h>
#include<successlabel.h>
#include<QPushButton>
#include<QSound>
#include<mainscene.h>


PlayScene::PlayScene(int level)
{
    this->v_CoinBtn.clear();
    this->playLevel=level;
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
            emit this->playSceneBack();//发送返回信号
        });
        MainScene::backgMusic->play();//背景音乐打开
    });

    //设置当前关卡数Label
    QLabel *label=new QLabel(this);
    label->resize(100,50);
    label->move(0,this->height()-label->height());
    label->setText("关卡："+QString::number(this->playLevel));
    label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);//设置文字水平垂直居中
    label->setFont(QFont("微软雅黑", 16, 75));//字体加粗

    double coinStartP=this->width()*0.5-50*2;

    //创建金币的背景图矩阵
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            QLabel *playCoinBackgroundLabel=new QLabel(this);
            playCoinBackgroundLabel->resize(50,50);
            playCoinBackgroundLabel->setPixmap(QPixmap(":/res/BoardNode.png"));
            playCoinBackgroundLabel->setScaledContents(true);//充满label
            playCoinBackgroundLabel->move(coinStartP+j*playCoinBackgroundLabel->width(),200+i*playCoinBackgroundLabel->height());
        }
    }

    connect(this,&PlayScene::sideReverse,this,&PlayScene::sideReverseF);//监听旁边金币翻转信号
    connect(this,&PlayScene::checkSccess,this,&PlayScene::checkSuccessF);//监听检查通关成功信号

    //翻金币音效创建
    QSound *clipSound=new QSound(":/res/ConFlipSound.wav",this);



    //创建金币按钮
    DataConfig config;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            CoinButton *coinBtn;
            if(config.mData[this->playLevel][i][j]==1){
                coinBtn=new CoinButton(i,j,"gold");
            }else if(config.mData[this->playLevel][i][j]==0){
                coinBtn=new CoinButton(i,j,"silver");
            }else{
                qDebug()<<"创建出错！";
                return;
            }
            coinBtn->setParent(this);
            coinBtn->move(coinStartP+j*coinBtn->width(),200+i*coinBtn->height());
            this->v_CoinBtn.push_back(coinBtn);
            connect(coinBtn,&QPushButton::clicked,[=](){
                btn1->buttonStatus=false;//禁用返回按钮
                clipSound->play();//翻金币音效播放
                qDebug()<<"点击槽函数";
                //coinBtn->buttonStatus=false;
                for(QVector<CoinButton *>::iterator it=this->v_CoinBtn.begin();it!=this->v_CoinBtn.end();it++){
                    (*it)->buttonStatus=false;//点击一个按钮后禁用所有按钮 防止快速点击
                }
                coinBtn->reverse();//当前金币翻转
                QTimer::singleShot(400,this,[=](){
                    emit this->sideReverse(i,j);//发送旁边金币翻转信号
                    //检查通关前解开按钮，然后让检查通关函数禁用
                    for(QVector<CoinButton *>::iterator it=this->v_CoinBtn.begin();it!=this->v_CoinBtn.end();it++){
                        (*it)->buttonStatus=true;
                    }
                    emit this->checkSccess();//发送检查通关成功信号

                });//延迟发送信号
                QTimer::singleShot(4000,this,[=](){
                    btn1->buttonStatus=true;//开启返回按钮
                });

            });


        }
    }

}

void PlayScene::paintEvent(QPaintEvent *event)
{
    //centralWidget背景设置
    QPainter painter(this);
    painter.drawPixmap(0,22,QPixmap(":/res/PlayLevelSceneBg.png"));//22为菜单栏的高度

    //画背景图标
    QPixmap pix1;
    pix1.load(":/res/Title.png");
    pix1=pix1.scaled(pix1.width(),pix1.height());//不放大
    painter.drawPixmap(this->width()*0.5-pix1.width()*0.5,22,pix1);//放中间

}

void PlayScene::sideReverseF(int i, int j)
{
    for(QVector<CoinButton *>::iterator it=this->v_CoinBtn.begin();it!=this->v_CoinBtn.end();it++){
        if(((*it)->coinX==i-1&&(*it)->coinY==j)||((*it)->coinX==i+1&&(*it)->coinY==j)||((*it)->coinY==j-1&&(*it)->coinX==i)||((*it)->coinY==j+1&&(*it)->coinX==i)){
            (*it)->reverse();//翻转
        }
    }
}

void PlayScene::checkSuccessF()
{
    int count=0;
    qDebug()<<"进入检查成功函数";
    for(QVector<CoinButton *>::iterator it=this->v_CoinBtn.begin();it!=this->v_CoinBtn.end();it++){
        qDebug()<<(*it)->coinName;
        if((*it)->coinName=="gold"){
            count++;
        }
    }
    if(count==16){
        qDebug()<<"检查成功!";
        SuccessLabel *label1=new SuccessLabel;
        label1->setParent(this);
        label1->move(this->width()*0.5-label1->width()*0.5,0-label1->height()+22);
        //禁用所有按钮
        for(QVector<CoinButton *>::iterator it=this->v_CoinBtn.begin();it!=this->v_CoinBtn.end();it++){
            (*it)->buttonStatus=false;
        }
        //成功音效创建
        QSound *successSound=new QSound(":/res/LevelWinSound.wav",this);
        QTimer::singleShot(600,this,[=](){
            MainScene::backgMusic->stop();//背景音乐关闭
            successSound->play();//成功音效播放
            label1->show();
            label1->zoom();
        });

    }
}
