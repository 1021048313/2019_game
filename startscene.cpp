#include "startscene.h"
#include "ui_startscene.h"
#include<QPainter>
#include"startbutton.h"
#include<QDebug>
#include<QTimer>
#include<QSound>

startscene::startscene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startscene)
{

    ui->setupUi(this);
    //开始按钮  //可以添加多个
    //bgm
    QSound *clickbgm=new QSound(":/music/click.wav",this);
    StartButton *startBtn=new StartButton(":/ps/play.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.55-startBtn->width()*0.5,this->height()*0.68);
    //创建开始2的场景
     choose=new choosescene;
    connect(startBtn,&StartButton::clicked,[=](){
    clickbgm->play();
        //按钮特效 向下跳跃向上跳跃
    startBtn->zoom1();
     startBtn->zoom2();

     //延时进入到第二个场景
     QTimer::singleShot(600,[=](){
        //自身隐藏
     this->hide();
        //进入选择关卡场景
    choose->show();});
    });
}


startscene::~startscene()
{
    delete ui;
}
//开始背景图插入
void startscene::paintEvent(QPaintEvent*){

    QPainter painter(this);
    QPixmap pix;
        pix.load(":/ps/start1.png");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
}



