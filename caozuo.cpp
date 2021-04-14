#include "caozuo.h"
#include<QPainter>
caozuo::caozuo(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(474,471);
    this->setWindowTitle("操作说明");
}

void caozuo::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pix;
        pix.load(":/ps/caozuo1.png");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
