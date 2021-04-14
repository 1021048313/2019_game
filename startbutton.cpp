#include<QPushButton>
#include "startbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
StartButton::StartButton(QString normalImg,QString pressImg){
    //保存两个路径
    this->normalImgPath=normalImg;
    this->pressImgPath=pressImg;
    QPixmap pix;
    bool ret=pix.load(this->normalImgPath);
    if(!ret){
        QString str=QString("1% 图片加载失败").arg(this->normalImgPath);
        qDebug()<<str;
        return;
    }
    //设定图片大小
    this->setFixedSize(pix.width(),pix.height());//pix.width(),pix.height();
    //设置不规则图片的样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图片大小
    this->setIconSize(QSize(pix.width(),pix.height()));


}
void StartButton::zoom1(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    //设定时间间隔
    animation->setDuration(300);
    //设定动画对象起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
   //设定动画对象结束位置；
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设定曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();

}

void StartButton::zoom2(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    //设定时间间隔
    animation->setDuration(300);
    //设定动画对象起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
   //设定动画对象结束位置；
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设定曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();

}
void StartButton::mousePressEvent(QMouseEvent*e){
    if(this->pressImgPath != " ")
     {
        QPixmap pix1;
        bool ret=pix1.load(this->pressImgPath);
        if(!ret)
        {
          qDebug()<<"wrong"<<this->pressImgPath;
          return;
        }
        this->setFixedSize(pix1.width(),pix1.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix1);
        this->setIconSize(QSize(pix1.width(),pix1.height()));
        }
    //其他交给父类
    QPushButton::mousePressEvent(e);
}
void StartButton::mouseReleaseEvent(QMouseEvent*e){
    if(this->pressImgPath!=" ")
     {QPixmap pix1;
    bool ret=pix1.load(this->normalImgPath);
    if(!ret){
        qDebug()<<"wrong";
        return;
    }
    this->setFixedSize(pix1.width(),pix1.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix1);
    this->setIconSize(QSize(pix1.width(),pix1.height()));
    }
    //其他交给父类
    QPushButton::mouseReleaseEvent(e);
}
