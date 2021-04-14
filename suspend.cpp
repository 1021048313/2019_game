#include "suspend.h"
#include"playbutton.h"
#include"startbutton.h"
#include<QPainter>
#include<QTimer>
#include<QSound>
suspend::suspend(QWidget *parent) : QWidget(parent)
{
    QSound *clickbgm=new QSound(":/music/clic.wav",this);
    this->setFixedSize(540,540);
    this->setWindowTitle("菜单");
    this->setWindowIcon(QIcon(":/ps/icon.png"));
    //再试一次
    StartButton *againbtn=new StartButton(":/ps/again.png",":/ps/again1.png");
    againbtn->setParent(this);
    againbtn->move(this->width()*0.5-againbtn->width()*0.5,this->height()*0.25);
    connect(againbtn,&StartButton::clicked,[=](){
        clickbgm->play();
        //隐藏自身
        //显示主场景
        emit this->suspendagain();
    });
    //中间
    StartButton *cenbtn=new StartButton(":/ps/mental.png");
    cenbtn->setParent(this);
    cenbtn->move(this->width()*0.5-cenbtn->width()*0.5,this->height()*0.35);


    //返回主菜单


    StartButton *backbtn=new StartButton(":/ps/backbtn.png",":/ps/backbtn1.png");
    backbtn->setParent(this);
    backbtn->move(this->width()*0.5-backbtn->width()*0.5,this->height()*0.65);
    connect(backbtn,&StartButton::clicked,[=](){
        //隐藏自身
        //显示主场景
        clickbgm->play();

        emit this->suspendback();
    });
}



void suspend::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pix;
        pix.load(":/ps/suspend.png");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
