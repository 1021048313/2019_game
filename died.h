#ifndef DIED_H
#define DIED_H

#include <QWidget>

class died : public QWidget
{
    Q_OBJECT
public:
    explicit died(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);
signals:

    void dieback();//返回
    void dieagain();//重来
public slots:
};

#endif // DIED_H
