#include "died.h"
#include<QTimer>
#include<QPainter>
#include<QDebug>
#include<QIcon>
#include<QSound>
#include"startbutton.h"
died::died(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1000,750);
    this->setWindowTitle("南开冰火人");
    this->setWindowIcon(QIcon(":/ps/icon.png"));
    QSound *clickbgm=new QSound(":/music/clic.wav",this);
    QSound *bgm=new QSound(":/music/dur.wav",this);
    //再试一次
    StartButton *dieagainbtn=new StartButton(":/ps/again.png",":/ps/again1.png");
    dieagainbtn->setParent(this);
    dieagainbtn->move(this->width()*0.5-dieagainbtn->width()*0.5,this->height()*0.45);
    connect(dieagainbtn,&StartButton::clicked,[=](){
        clickbgm->play();
        //隐藏自身
        //显示主场景
        emit this->dieagain();
        bgm->play();
    });


    //返回主菜单


    StartButton *diebackbtn=new StartButton(":/ps/backbtn.png",":/ps/backbtn1.png");
    diebackbtn->setParent(this);
    diebackbtn->move(this->width()*0.5-diebackbtn->width()*0.5,this->height()*0.60);
    connect(diebackbtn,&StartButton::clicked,[=](){
        //隐藏自身
        //显示主场景

        emit this->dieback();
    });
}
void died::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pix;
        pix.load(":/ps/be.png");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
