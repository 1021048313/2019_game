#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include <QPushButton>

class PlayButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit playbutton(QWidget *parent = nullptr);
    PlayButton(QString normalImg,QString pressImg=" ");
    QString normalImgPath;//默认显示图片路径
    QString pressImgPath;//按下路径
    void exchange();
    void exchange2();
signals:

public slots:
};

#endif // PLAYBUTTON_H
