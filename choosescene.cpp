#include "choosescene.h"
#include"startbutton.h"
#include<QTimer>
#include<QPainter>
#include<QDebug>

#include<QSound>

choosescene::choosescene(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1000,750);
    this->setWindowTitle("南开冰火人");
    this->setWindowIcon(QIcon(":/ps/icon.png"));
    playscene  *play=new playscene;

    //按键声音
    QSound *clickbgm=new QSound(":/music/clic.wav",this);
    QSound *clickbgm2=new QSound(":/music/dur.wav",this);


   // this->setWindowIcon("");

     //play=NULL;

    //开始游戏
    StartButton *startBtn1=new StartButton(":/ps/kaishi.png");
    startBtn1->setParent(this);
    startBtn1->move(this->width()*0.5-startBtn1->width()*0.5,this->height()*0.4);



    connect(startBtn1,&StartButton::clicked,[=](){

        //按钮特效 向下跳跃向上跳跃
    startBtn1->zoom1();
     startBtn1->zoom2();

     //进入具体游戏场景
     //隐藏自身
     clickbgm->play();
     QTimer::singleShot(600,[=](){
        //自身隐藏
     this->hide();



            play->timer->start(1000);
        //进入游戏场景
         play->show();
         clickbgm2->play();

    });

    });

    //参数返回
    //传递参数返回主窗口
    connect(play,&playscene::suspendback,[=](){
        play->hide();
        this->show();
        clickbgm2->stop();

    });
    //操作说明
    StartButton *startBtn2=new StartButton(":/ps/caozuo.png");
    startBtn2->setParent(this);
    startBtn2->move(this->width()*0.5-startBtn2->width()*0.5,this->height()*0.6);


    connect(startBtn2,&StartButton::clicked,[=](){
  clickbgm->play();
        //按钮特效 向下跳跃向上跳跃
    startBtn2->zoom1();
     startBtn2->zoom2();




     QTimer::singleShot(600,[=](){
        Caozuo=new caozuo;
        Caozuo->show();
    });

});

    //更多游戏
    StartButton *startBtn3=new StartButton(":/ps/more.png");
    startBtn3->setParent(this);
    startBtn3->move(this->width()*0.5-startBtn3->width()*0.5,this->height()*0.75);


    connect(startBtn3,&StartButton::clicked,[=](){
    clickbgm->play();
        //按钮特效 向下跳跃向上跳跃
    startBtn3->zoom1();
     startBtn3->zoom2();




     QTimer::singleShot(600,[=](){
        more=new moregame;
        more->show();
    });

});

    //监听返回信号

}

void choosescene::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pix;
        pix.load(":/ps/start2.png");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
