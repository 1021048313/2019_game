#include "playbutton.h"
#include<QPropertyAnimation>
#include<QDebug>
PlayButton::PlayButton(QString normalImg,QString pressImg)
{
    this-> normalImgPath=normalImg;
    this-> pressImgPath=pressImg;
    QPixmap pix;
    bool ret=pix.load(this->normalImgPath);
    if(!ret){
        QString str=QString("1% 图片加载失败").arg(this->normalImgPath);
        qDebug()<<str;
        return;
    }

    this->setFixedSize(pix.width(),pix.height());//pix.width(),pix.height();
    //设置不规则图片的样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图片大小
    this->setIconSize(QSize(pix.width(),pix.height()));


}
void PlayButton::exchange(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    //设定时间间隔
    animation->setDuration(300);
    //设定动画对象起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
   //设定动画对象结束位置；
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();


}
void PlayButton::exchange2(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    //设定时间间隔
    animation->setDuration(300);
    //设定动画对象起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
   //设定动画对象结束位置；
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();

}
