#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <QWidget>
#include"playscene.h"
#include"caozuo.h"
#include"moregame.h"
#include"suspend.h"
class choosescene : public QWidget
{
    Q_OBJECT
public:
    explicit choosescene(QWidget *parent = nullptr);

    //背景
    void paintEvent(QPaintEvent*);
    //维护具体游戏场景的指针
    playscene *play;
    caozuo *Caozuo;
    moregame *more;


signals:
    void starttime();

public slots:
};

#endif // CHOOSESCENE_H
