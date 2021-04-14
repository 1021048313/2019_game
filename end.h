#ifndef END_H
#define END_H

#include <QWidget>

namespace Ui {
class end;
}

class end : public QWidget
{
    Q_OBJECT

public:
    explicit end(QWidget *parent = nullptr);
    ~end();
    void paintEvent(QPaintEvent*);
//     QTimer * timer2;

private:
    Ui::end *ui;
};

#endif // END_H
