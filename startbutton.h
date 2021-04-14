#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include <QPushButton>

class StartButton : public QPushButton
{
    Q_OBJECT
public:

    StartButton(QString normalImg,QString pressImg=" ");

    QString normalImgPath;//默认显示图片路径
    QString pressImgPath;//按下显示图片路径
    //向下向上
    void zoom1();
    void zoom2();
    //按键
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:

public slots:
};

#endif // STARTBUTTON_H
