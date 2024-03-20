#include "coinbutton.h"
#include<QPixmap>
#include<QDebug>
#include<QTimer>
#include<QVector>

CoinButton::CoinButton(int x, int y,QString name)
{
    this->coinName=name;
    this->coinX=x;
    this->coinY=y;
    //创建Pixmap对象存放开始图片资源
    QPixmap pix;
    bool ret;
    if(name=="gold"){//金币
        ret=pix.load(":/res/Coin0001.png");
    }
    else if(name=="silver"){//银币
        ret=pix.load(":/res/Coin0008.png");
    }else{
        qDebug()<<"创建金币按钮出错！";
        return;
    }
    if(!ret){
        qDebug()<<"图片加载失败！";
        return;
    }
    //设置按钮的大小 适应按钮图片大小
    setFixedSize(50,50);
    //设置按钮的样式 将按钮的阴影边界和按钮图片的边界重合
    setStyleSheet("QPushButton{border:0px;}");
    //设置按钮图标，将按钮图片设置到按钮上
    setIcon(pix);
    //设置图标大小
    setIconSize(QSize(50,50));

    //监听索引信号
    connect(this,&CoinButton::add,[=](){
        this->addIndex();
    });

}

void CoinButton::reverse()
{
    if(this->coinName=="gold"){
        QVector<QString> v;
        v.clear();
        for(int i=1;i<=8;i++){
            v.push_back(QString(":/res/Coin000%1.png").arg(i));
        }
//        for(int i=0;i<8;i++){
//            qDebug()<<v[i];
//        }

        QTimer *timer=new QTimer(this);
        timer->start(80);
        connect(timer,&QTimer::timeout,[=](){
            QPixmap pix;
            bool ret=pix.load(v[this->index]);
            if(!ret){
                qDebug()<<"图片加载失败！";
                return;
            }
            //设置按钮的大小 适应按钮图片大小
            setFixedSize(50,50);
            //设置按钮的样式 将按钮的阴影边界和按钮图片的边界重合
            setStyleSheet("QPushButton{border:0px;}");
            //设置按钮图标，将按钮图片设置到按钮上
            setIcon(pix);
            //设置图标大小
            setIconSize(QSize(50,50));
            qDebug()<<this->index;
            emit this->add();//发出索引+1信号
            if(this->index==8){
               this->index=0;//重新置零
               timer->stop();
               return;
            }
        });
        this->coinName="silver";
        return;
    }
    if(this->coinName=="silver"){
        QVector<QString> v;
        v.clear();
        for(int i=8;i>=1;i--){
            v.push_back(QString(":/res/Coin000%1.png").arg(i));
        }
        QTimer *timer=new QTimer(this);
        timer->start(80);
        connect(timer,&QTimer::timeout,[=](){
            QPixmap pix;
            bool ret=pix.load(v[this->index]);
            if(!ret){
                qDebug()<<"图片加载失败！";
                return;
            }
            //设置按钮的大小 适应按钮图片大小
            setFixedSize(50,50);
            //设置按钮的样式 将按钮的阴影边界和按钮图片的边界重合
            setStyleSheet("QPushButton{border:0px;}");

            //设置按钮图标，将按钮图片设置到按钮上
            setIcon(pix);
            //设置图标大小
            setIconSize(QSize(50,50));
            emit this->add();
            if(this->index==8){
               this->index=0;//重新置零
               timer->stop();
               return;
            }
        });
        this->coinName="gold";
        return;
    }
}

void CoinButton::addIndex()
{
    this->index++;
}

void CoinButton::mousePressEvent(QMouseEvent *event)
{
    if(!this->buttonStatus){
        return;
    }
    return QPushButton::mousePressEvent(event);

}

//void CoinButton::mouseReleaseEvent(QMouseEvent *event)
//{
//    //创建Pixmap对象存放金币图片资源
//    qDebug()<<"点击事件触发";
//    QPixmap pix;
//    bool ret=false;
//    if(this->coinName=="gold"){//按下时原本图片为金币
//        ret=pix.load(":/res/Coin0001.png");
//    }
//    if(this->coinName=="silver"){
//        ret=pix.load(":/res/Coin0008.png");
//    }
//    if(!ret){
//        qDebug()<<"图片加载失败！";
//        return;
//    }
//    //设置按钮的大小 适应按钮图片大小
//    setFixedSize(50,50);
//    //设置按钮的样式 将按钮的阴影边界和按钮图片的边界重合
//    setStyleSheet("QPushButton{border:0px;}");
//    //设置按钮图标，将按钮图片设置到按钮上
//    setIcon(pix);
//    //设置图标大小
//    setIconSize(QSize(50,50));
//    //让父类执行点击其他操作
//    return QPushButton::mousePressEvent(event);

//}
