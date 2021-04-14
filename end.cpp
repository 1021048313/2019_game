#include "end.h"
#include "ui_end.h"

//#include"playscene.h"
#include<QIcon>
#include<QPainter>
#include"startbutton.h"
#include<QSound>
//#include<QTimer>
end::end(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::end)
{
    ui->setupUi(this);
    this->setFixedSize(1000,750);
    this->setWindowTitle("南开冰火人");
    this->setWindowIcon(QIcon(":/ps/icon.png"));
    StartButton *nextBtn=new StartButton(":/ps/next.png");
    nextBtn->setParent(this);
    nextBtn->move(this->width()*0.5-nextBtn->width()*0.5,this->height()*0.65);
//    playscene *ply=new playscene;
    //时间
//    timer2 = new QTimer(this);  //初始化定时器
//    ui->Timer->setStyleSheet("color:#fcc900;font-size:18px;");
//    ui->Timer->setSegmentStyle(QLCDNumber::Flat);
//    ui->Timer->display(ply->TimeRecord->toString("mm:ss"));

}



end::~end()
{
    delete ui;
}
void end::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pix;
        pix.load(":/ps/he.jpg");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
