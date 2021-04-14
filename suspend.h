#ifndef SUSPEND_H
#define SUSPEND_H

#include<QWidget>
class suspend : public QWidget
{
    Q_OBJECT
public:
    explicit suspend(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);


signals:
    //自定义信号只需声明
    void suspendback();//返回
    void suspendagain();//重来
public slots:
};

#endif // SUSPEND_H
