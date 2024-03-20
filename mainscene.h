#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include<QMediaPlayer>
#include<QMediaPlaylist>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //绘图事件 画背景图片
    virtual void paintEvent(QPaintEvent *event);

    // 创建QMediaPlaylist对象
    static QMediaPlayer *backgMusic;//背景音效


private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
