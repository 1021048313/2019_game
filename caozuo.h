#ifndef CAOZUO_H
#define CAOZUO_H

#include <QWidget>

class caozuo : public QWidget
{
    Q_OBJECT
public:
    explicit caozuo(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);


signals:

public slots:
};

#endif // CAOZUO_H
