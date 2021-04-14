#include "clock.h"
#include<QTimer>
clock::clock(QWidget *parent) : QWidget(parent)
{
    // 构造定时器，设置超时为 1 秒
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->start(1000);

}
