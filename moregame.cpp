#include "moregame.h"
#include<QPainter>
moregame::moregame(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(474,471);
    this->setWindowTitle("更多的（我们写不出来的）游戏");

}
void moregame::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pix;
        pix.load(":/ps/more1.jpg");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
