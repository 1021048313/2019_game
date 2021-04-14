#ifndef MOREGAME_H
#define MOREGAME_H

#include <QWidget>

class moregame : public QWidget
{
    Q_OBJECT
public:
    explicit moregame(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);

signals:

public slots:
};

#endif // MOREGAME_H
