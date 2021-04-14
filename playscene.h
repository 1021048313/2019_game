#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include <QWidget>
#include"suspend.h"
#include <QDateTime>
#include <QTimer>
#include <QTime>
#include <QPixmap>
#include <QIcon>
#include<QSound>
#include<QMediaPlayer>
#include"end.h"
#include"died.h"
namespace Ui {
class playscene;
}

class playscene : public QWidget
{
    Q_OBJECT

public:
    explicit playscene(QWidget *parent = nullptr);
    ~playscene();
        void paintEvent(QPaintEvent*);
        void keyPressEvent(QKeyEvent *);
            void gameover();
            void checkgameover();
            void victory();
            void checkvictory();
            void checkreda1();
            void checkreda2();
            void checkreda3();
            void checkreda4();
            void checkbluea1();
            void checkbluea2();
            void checkbluea3();
            void checkbluea4();
            void checkban1();
            void checkstatus();
            void checkban2();
            void checkdoor();

        suspend *zant;
        died *die;
        end *endd;

        //定时器
        QTimer * timer;      //定时器 每秒更新时间
            QTime * TimeRecord;  //记录时间
signals:
        //返回choose
        void suspendback();

private:
    Ui::playscene *ui;
    int ban2status;
        int sunx;
        int suny;
        int moonx;
        int moony;
        int boxx;
        int boxy;
        int redax[4];
        int reday[4];
        int blueax[4];
        int blueay[4];
        int ban1x;
        int ban1y;
        int ban2x;
        int ban2y;
        int ganx[2];
        int gany[2];
        int doorx[2];
        int doory[2];






private slots:
    void updateTime();
        void on_Stop_clicked();

};

#endif // PLAYSCENE_H
