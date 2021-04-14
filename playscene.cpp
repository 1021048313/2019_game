#include "playscene.h"
#include "ui_playscene.h"

#include<QPainter>

#include"startbutton.h"
#include<QEvent>
#include<QTimer>
#include<QTime>
#include<QLCDNumber>
#include<QSound>
#include <QKeyEvent>
#include <QString>

playscene::playscene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playscene)
{

    ui->setupUi(this);
    this->setFixedSize(1000,750);
        this->setWindowTitle("南开冰火人");
    this->setWindowIcon(QIcon(":/ps/icon.png"));
    this->setFocus();

    QSound *clickbgm=new QSound(":/music/clic.wav",this);
    //sun初始位置
    sunx=40;suny=555;
    //moon初始位置
    moonx=40;moony=650;
    //箱子初始位置
    boxx=240;boxy=245;
    //板1初始位置
    ban1x=40;ban1y=395;
    //板2初始位置
    ban2x=860;ban2y=320;ban2status=0;
    //杆的初始位置
    ganx[0]=270;gany[0]=485;
    ganx[1]=0;gany[1]=750;
    //门初始位置
    doorx[0]=0;doory[0]=750;
    doorx[1]=0;doory[1]=750;
    //reda横坐标
    redax[0]=705;redax[1]=660;redax[2]=80;redax[3]=570;
    //reda纵坐标
    reday[0]=660;reday[1]=360;reday[2]=135;reday[3]=115;
    //bluea横坐标
    blueax[0]=505;blueax[1]=190;blueax[2]=270;blueax[3]=475;
    //bluea纵坐标
    blueay[0]=660;blueay[1]=330;blueay[2]=60;blueay[3]=115;


    //计时
    //isStart = false;     //初始为还未计时
    timer = new QTimer(this);  //初始化定时器
    TimeRecord = new QTime(0, 0); //初始化时间
    ui->Timer->setStyleSheet("color:green;font-size:18px;");
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    ui->Timer->setDigitCount(8);
    ui->Timer->setSegmentStyle(QLCDNumber::Flat);
    ui->Timer->display(TimeRecord->toString("mm:ss"));


    //指针定义
            died *die=new died;
            suspend *zant=new suspend;

      //返回
      connect(die,&died::dieagain,[=](){
          die->hide();
          //时间
          on_Stop_clicked();
          timer->start();
          this->show();
      });
      connect(zant,&suspend::suspendagain,[=](){
          zant->hide();
          on_Stop_clicked();
         // timer->start();
          this->show();
      });
      //主菜单
      connect(zant,&suspend::suspendback,[=](){
          zant->hide();
          this->hide();
          emit this->suspendback();
          //on_Stop_clicked();
      });
      connect(die,&died::dieback,[=](){
          die->hide();
          this->hide();
          emit this->suspendback();
          //on_Stop_clicked();
      });
      //
      StartButton *playbtn=new StartButton(":/ps/greendown.png",":/ps/greendown1.png");
      playbtn->setParent(this);
      playbtn->move(this->width()*0.5-playbtn->width()*0.5,this->height()*0.965);
      connect(playbtn, &StartButton::clicked, [=](){
          clickbgm->play();
          //延时进入到第二个场景
          QTimer::singleShot(600,[=](){
             //进入暂停界面
          zant->show();
                 ;});
      });
        //时间暂停
          connect(playbtn,&StartButton::clicked,[=](){
              timer->stop();
          });
}


playscene::~playscene()
{
    delete ui;
}

//定时器

void playscene::updateTime()
{
    *TimeRecord = TimeRecord->addSecs(1);
    ui->Timer->display(TimeRecord->toString("mm:ss"));
}

void playscene::on_Stop_clicked()
{
    timer->stop();    //计时器停止
    TimeRecord->setHMS(0,0,0); //时间设为0
    ui->Timer->display(TimeRecord->toString("mm:ss")); //显示00:00:00
}

//背景
void playscene::paintEvent(QPaintEvent*)
{

    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/ps/state.png"));
    painter.drawPixmap(455,710,QPixmap(":/ps/water.png"));
    painter.drawPixmap(662,710,QPixmap(":/ps/fire.png"));
    painter.drawPixmap(613,556,QPixmap(":/ps/green.png"));
    painter.drawPixmap(750,270,QPixmap(":/ps/anniu.png"));
    painter.drawPixmap(240,370,QPixmap(":/ps/anniu.png"));
    painter.drawPixmap(ganx[0],gany[0],QPixmap(":/ps/gan1.png"));
    painter.drawPixmap(ganx[1],gany[1],QPixmap(":/ps/gan2.png"));
    painter.drawPixmap(doorx[0],doory[0],QPixmap(":/ps/blackdoor.png"));
    painter.drawPixmap(doorx[1],doory[1],QPixmap(":/ps/blackdoor.png"));
    painter.drawPixmap(sunx,suny,QPixmap(":/ps/rederr.png"));
    painter.drawPixmap(moonx,moony,QPixmap(":/ps/bule.png"));
    painter.drawPixmap(boxx,boxy,QPixmap(":/ps/stone.png"));
    painter.drawPixmap(ban1x,ban1y,QPixmap(":/ps/ban1.png"));
    painter.drawPixmap(ban2x,ban2y,QPixmap(":/ps/ban2.png"));

    for(int i=0;i<4;i++){
        painter.drawPixmap(redax[i],reday[i],QPixmap(":/ps/redalas.png"));
    }
    for(int i=0;i<4;i++){
        painter.drawPixmap(blueax[i],blueay[i],QPixmap(":/ps/bluedark.png"));
    }

}
//检查板1位置
void playscene::checkban1(){
    if(moony>450){
        if(sunx>455){
            ban1y=395;
        }
    }
    if(moony<=450){
        if(moonx<=255){
          ban1y=460;
          ganx[0]=0;gany[0]=750;
          ganx[1]=245;gany[1]=485;
        }
    }
    if(suny<=455){
        if(sunx<=255){
            ban1y=460;
            ganx[0]=0;gany[0]=750;
            ganx[1]=245;gany[1]=485;
        }
    }
}
//确定板2状态
void playscene::checkban2(){
    if((moonx==240&&moony==325&&sunx>=850&&suny==335)||(sunx==240&&suny==330&&moonx>=850&&moony==330)){
        ban2status=1;
    }
    else if((moonx!=240&&moony==325&&sunx>=850&&suny==335)||(sunx!=240&&suny==330&&moonx>=850&&moony==330)){
        ban2status=2;
    }
    else if((moonx==750&&moony==225&&sunx>=850&&suny==335)||(sunx==750&&suny==230&&moonx>=850&&moony==330)){
        ban2status=3;
    }
    else if((moonx!=750&&moony==225&&sunx>=850&&suny==335)||(sunx!=750&&suny==230&&moonx>=850&&moony==330)){
        ban2status=4;
    }
    else if((moonx==240&&moony==325)||(moonx==750&&moony==225)||(sunx==240&&suny==330)||(sunx==750&&suny==230)){
        ban2status=6;
    }
    else if (!(moonx==240&&moony==325)||(moonx==750&&moony==225)||(sunx==240&&suny==330)||(sunx==750&&suny==230)) {
        ban2status=0;
    }
    checkstatus();
}
//检查板2状态
void playscene::checkstatus(){
    if(ban2status==6){
        ban2y=390;
    }
    if (ban2status==0){
        ban2y=320;
    }
    else if(ban2status==1){
        ban2y=390;
    }
    else if(ban2status==2){
        if(moonx!=240&&moony==325&&sunx>=850&&suny==335){
            ban2y=320;
            suny=265;
        }
        else if (sunx!=240&&suny==330&&moonx>=850&&moony==330){
            ban2y=320;
            moony=260;
        }
    }
    else if(ban2status==3){
        ban2y=390;
    }
    else if(ban2status==4){
        if(moonx!=750&&moony==225&&sunx>=850&&suny==335){
            ban2y=320;
            suny=265;
        }
        else if (sunx!=750&&suny==230&&moonx>=850&&moony==330){
            ban2y=320;
            moony=260;
        }
    }
}
//检查并改变蓝色A的位置
void playscene::checkbluea1(){
    if(moonx==505&&moony>500){
        blueax[0]=0;blueay[0]=40;
    }
}
void playscene::checkbluea2(){
    if(moonx==190&&moony>225&&moony<=325){
        blueax[1]=40;blueay[1]=40;
    }
}
void playscene::checkbluea3(){
    if(moonx==270&&moony<=115){
        blueax[2]=80;blueay[2]=40;
    }
}
void playscene::checkbluea4(){
if(moonx==475&&moony<=100){
        blueax[3]=120;blueay[3]=40;
    }
}
//检查并改变红色A的位置
void playscene::checkreda1(){
    if(sunx==705&&suny>505){
        redax[0]=0;reday[0]=0;
    }
 }
void playscene::checkreda2(){
    if(sunx==660&&suny>235&&suny<=355){
        redax[1]=40;reday[1]=0;
    }
}
void playscene::checkreda3(){
    if(sunx==80&&suny>105&&suny<130){
        redax[2]=80;reday[2]=0;
    }
}
void playscene::checkreda4(){
if(sunx==570&&suny<=105){
        redax[3]=120;reday[3]=0;
    }
}
//检查门的颜色
void playscene::checkdoor(){
    if(moonx==900&&moony==100){
        doorx[1]=902;doory[1]=115;
    }
    if(sunx==800&&suny==105){
        doorx[0]=801;doory[0]=114;
    }
}
void playscene::victory(){
 endd=new end(this);
 endd->show();
 //音乐
}
//判断是否成功
void playscene::checkvictory(){
    if(moonx==900&&moony==100&&sunx==795&&suny==105)
        victory();
}
void playscene::gameover(){
    die=new died(this);
    die->show();
    
}
//判断是否失败

void playscene::checkgameover(){
    if(suny==655){
        if(sunx>=470&&sunx<=545){
            gameover();
        }
    }
    else if(suny==505){
        if(sunx>=605&&sunx<=710){
            gameover();
        }
    }
    else if(moony==650){
        if(moonx>=660&&moonx<=750){
            gameover();
        }
    }
    else if(moony==500){
        if(moonx>=605&&moonx<=710){
            gameover();
        }
    }
}

//键盘事件
void playscene::keyPressEvent(QKeyEvent *e){
    checkgameover();
    checkvictory();
    if(e->key()==Qt::Key_Up){
        if(moony>500){
            if(moonx<=760){
                if(moony>580){
                    moony-=5;
                }
                else {
                    moony=650;
                }
            }
            else if (moonx>760&&moonx<920) {
                moony-=5;
            }
        }
        if(moony<=500&&moony>350){
            if(moonx>=40&&moonx<480){
                moony-=5;
            }
            else if(moonx>=480){
                if(moony<=360){
                    moony=500;
                }
                else{
                    moony-=5;
                }
            }
        }
        if(moony<=350&&moony>40){
            moony-=5;
        }
    }
    if(e->key()==Qt::Key_Down){
        if(moony>500){
            if(moonx<=845){
                moony+=10;
                if(moony>=650){
                    moony=650;
                }
            }
            else if (moonx>845&&moonx<920) {
                moony=575;
            }

        }
        if(moony<=500&&moony>350){
            if(moonx>=480){
                moony+=5;
                if(moony>=500){
                    moony=500;
                }
            }
            else if (moonx<480&&moonx>120) {
                moony=450;
            }
            else if (moonx<=120&&moonx>40) {
                moony=400;
            }
        }
        if(moony<=350&&moony>225){
            if(moonx>=520&&moonx<850){
                moony=350;
            }
            else if(moonx>=850){
                moony=330;
            }
            else if (moonx<520&&moonx>40) {
                moony=325;
            }
        }
        if(moony>100&&moony<=225){
            if(moonx>=710){
                moony=225;
            }
            else if(moonx<710&&moonx>=480){
                moony=175;
            }
            else if (moonx<480&&moonx>170) {
                moony=225;
            }
            else if (moonx<=170&&moonx>140) {
                moony=185;
            }
            else if (moonx<=140&&moonx>40) {
                moony=125;
            }
        }
        if(moony<=100){
            if(moonx>=140&&moonx<240){
                moony=185;
            }
            else if (moonx>=240&&moonx<300) {
                moony=50;
            }
            else if (moonx>=300&&moonx<340) {
                moony=75;
            }
            else if (moonx>=340&&moonx<=640) {
                moony=100;
            }
            else if (moonx>640&&moonx<750) {
                moony=75;
            }
            else if (moonx>=750&&moonx<900) {
                moony=100;
            }
        }
    }
    if(e->key()==Qt::Key_Right){
        if(moonx<=920){
        moonx+=5;
        }
        else {
            moonx=920;
        }
    }
    if(e->key()==Qt::Key_Left){
        if(moony==225){
            if(moonx<=280){
                if(boxx>165){
                    boxx-=5;
                    moonx-=5;
                }
                else{
                    boxx=165;
                    moonx=205;
                }
            }
            else{
                moonx-=5;
            }
        }
        else{
            moonx-=5;
        }
    }
    if(e->key()==Qt::Key_D&&e->text()=="D"){
        if(sunx<=920){
            sunx+=5;
        }
        else {
            sunx=920;
        }
    }
    if(e->key()==Qt::Key_A&&e->text()=="A"){
        if(suny==230){
            if(sunx<=280){
                if(boxx>165){
                    boxx-=5;
                    sunx-=5;
                }
                else{
                    boxx=165;
                    sunx=205;
                }
            }
            else{
                sunx-=5;
            }
        }
        else{
            sunx-=5;
        }
    }
    if(e->key()==Qt::Key_W&&e->text()=="W"){
        if(suny>505){
            if(sunx<=760){
                if(suny>580){
                    suny-=5;
                }
                else {
                    suny=655;
                }
            }
            else if (sunx>760&&sunx<920) {
                suny-=5;
            }
        }
        if(suny<=505&&suny>355){
            if(sunx>=40&&sunx<480){
                suny-=5;
            }
            else if(sunx>=480){
                if(suny<=360){
                    suny=505;
                }
                else{
                    suny-=5;
                }
            }
        }
        if(suny<=355&&suny>40){
            suny-=5;
        }
    }
    if(e->key()==Qt::Key_S&&e->text()=="S"){
        if(suny>505){
            if(sunx<320){
                suny=555;
            }
            else if (sunx>=320&&sunx<435) {
                suny=655;
            }
            else if(sunx>=435&&sunx<=845){
                suny+=10;
                if(suny>=655){
                    suny=655;
                }
            }
            else if (sunx>845&&sunx<920) {
                suny=580;
            }

        }
        if(suny<=505&&suny>355){
            if(sunx>=480){
                suny+=10;
                if(suny>=505){
                    suny=505;
                }
            }
            else if (sunx<480&&sunx>120) {
                suny=455;
            }
            else if (sunx<=120&&sunx>40) {
                suny=405;
            }
        }
        if(suny<=355&&suny>230){
            if(sunx>=520&&sunx<850){
                suny=355;
            }
            else if (sunx>=850&&sunx<920) {
                suny=335;
            }
            else if (sunx<520&&sunx>40) {
                suny=330;
            }
        }
        if(suny>105&&suny<=230){
            if(sunx>=710){
                suny=230;
            }
            else if(sunx<710&&sunx>=480){
                suny=180;
            }
            else if (sunx<480&&sunx>200) {
                suny=230;
            }
            else if (sunx<=200&&sunx>140) {
                suny=190;
            }
            else if (sunx<=140&&sunx>40) {
                suny=130;
            }
        }
        if(suny<=105){
            if(sunx>=140&&sunx<240){
                suny=190;
            }
            else if (sunx>=240&&sunx<300) {
                suny=55;
            }
            else if (sunx>=300&&sunx<340) {
                suny=80;
            }
            else if (sunx>=340&&sunx<=640) {
                suny=105;
            }
            else if (sunx>640&&sunx<750) {
                suny=80;
            }
            else if (sunx>=750&&sunx<900) {
                suny=105;
            }
        }
    }

    checkbluea1();
    checkbluea2();
    checkbluea3();
    checkbluea4();
    checkreda1();
    checkreda2();
    checkreda3();
    checkreda4();
    checkban1();
    checkban2();
    checkdoor();
    update();
}





