#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QWidget>
#include"choosescene.h"
#include"suspend.h"
namespace Ui {
class startscene;
}

class startscene : public QWidget
{
    Q_OBJECT

public:
    explicit startscene(QWidget *parent = nullptr);
    ~startscene();
void paintEvent(QPaintEvent*);

choosescene *choose;
suspend *zant;

private:
    Ui::startscene *ui;
};

#endif // STARTSCENE_H
