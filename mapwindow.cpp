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

void MapWindow::on_pushButton_2_clicked()
{

}

void MapWindow::set_play_num(int p_t){
    // зараз тут буде жахливий код, головне не помри від інфаркту пж
   ui->play1->setText("Player 1");
   QString money = QString::number(m->players.at(0)->getCash());
   ui->money1->setText(money+ "$");
   ui->play2->setText("Player 2");
   money = QString::number(m->players.at(1)->getCash());
   ui->money2->setText(money+ "$");
   if (p_t == 3){
       ui->play3->setText("Player 3");
       money = QString::number(m->players.at(2)->getCash());
       ui->money3->setText(money + "$");
   }
   else if (p_t == 4) {
       ui->play3->setText("Player 3");
       money = QString::number(m->players.at(2)->getCash());
       ui->money3->setText(money+ "$");
       ui->play4->setText("Player 4");
       money = QString::number(m->players.at(3)->getCash());
       ui->money4->setText(money+ "$");
   }


}
