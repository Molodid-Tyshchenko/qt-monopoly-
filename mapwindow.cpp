#include "mapwindow.h"
#include "ui_mapwindow.h"
#include "MapInterface.h"


#include <iostream>
#include <QLabel>
#include <QMessageBox>

MapWindow::MapWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapWindow)
{

    ui->setupUi(this);

}

MapWindow::~MapWindow()
{
    delete ui;
}

MapWindow::MapWindow(QWidget *parent, Monopoly* t_m) :
    QWidget(parent),
    ui(new Ui::MapWindow)
{
    ui->setupUi(this);
    m = t_m;
    //QMessageBox::information(this,"NAME","PIT");
}



void MapWindow::set_play_num(int p_t){
    // зараз тут буде жахливий код, головне не помри від інфаркту пж
   QString money = QString::number(m->players.at(0)->getCash());
   QString pos = QString::number(m->players.at(0)->getPos());
   ui->play1->setText("Player 1");
   ui->money1->setText(money+ "$");
   ui->pos1->setText(pos);

   money = QString::number(m->players.at(1)->getCash());
   pos = QString::number(m->players.at(1)->getPos());
   ui->play2->setText("Player 2");
   ui->money2->setText(money+ "$");
   ui->pos2->setText(pos);

   if (p_t == 3){
       money = QString::number(m->players.at(2)->getCash());
       pos = QString::number(m->players.at(2)->getPos());
       ui->play3->setText("Player 3");
       ui->money3->setText(money + "$");
       ui->pos3->setText(pos);
   }
   else if (p_t == 4) {
       money = QString::number(m->players.at(2)->getCash());
       pos = QString::number(m->players.at(2)->getPos());
       ui->play3->setText("Player 3");
       ui->money3->setText(money+ "$");
       ui->pos3->setText(pos);

       money = QString::number(m->players.at(3)->getCash());
       pos = QString::number(m->players.at(3)->getPos());
       ui->play4->setText("Player 4");
       ui->pos4->setText(pos);
       ui->money4->setText(money+ "$");
   }


}

void MapWindow::on_bRollDice_clicked()
{
    m->updateGame();
}

