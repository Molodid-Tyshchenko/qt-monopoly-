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

MapWindow::MapWindow(QWidget *parent, Monopoly* t_m) :
    QWidget(parent),
    ui(new Ui::MapWindow)
{
    ui->setupUi(this);
    m = t_m;

    myInfoWindow = new InfoWindow(nullptr, m);


    mPlayers = m->getNumberAllPlayers();

    //вывод на кубики
    connect(m->players[0].get(), &AbstractPlayer::signal, this, &MapWindow::diceValue);
    connect(m->players[1].get(), &AbstractPlayer::signal, this, &MapWindow::diceValue);
    if(mPlayers == 3)
        connect(m->players[2].get(), &AbstractPlayer::signal, this, &MapWindow::diceValue);
    else if(mPlayers == 4) {
        connect(m->players[2].get(), &AbstractPlayer::signal, this, &MapWindow::diceValue);
        connect(m->players[3].get(), &AbstractPlayer::signal, this, &MapWindow::diceValue);
    }

    //нажатие на кнопки basicField(запись информации из BasicField полей в InfoWindow)
//    connect(m->mapMonopoly.at(1).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(2).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(3).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(5).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(6).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(7).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(10).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(11).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(12).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(15).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(16).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(17).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(20).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(21).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(22).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(23).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(25).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(26).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(27).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(28).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(30).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(31).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(32).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(33).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(34).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(35).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(40).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(41).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);
//    connect(m->mapMonopoly.at(42).get(), &Field::sendSignalToInfo, myInfoWindow, &InfoWindow::fromBasicField);



//    connect(ui->bField1, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField2, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField3, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField5, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField6, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField7, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField10, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField11, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField12, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField15, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField16, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField17, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField20, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField21, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField22, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField23, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField25, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField26, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField27, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField28, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField30, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField31, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField32, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField33, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField34, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField35, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField40, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField41, SIGNAL(clicked()), this, SLOT(infoBasicField));
//    connect(ui->bField42, SIGNAL(clicked()), this, SLOT(infoBasicField));


}

MapWindow::~MapWindow()
{
    delete ui;
    delete myInfoWindow;
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
       ui->money3->setText(money + "$");
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

void MapWindow::diceValue(QString value1, QString value2)
{
    ui->dice1->setText(value1);
    ui->dice2->setText(value2);
}

//void MapWindow::infoBasicField()
//{
//    QPushButton *button = (QPushButton*)sender();

//}


void MapWindow::on_bField1_clicked()
{
    m->mapMonopoly.at(1)->sendSignalToInfo();
    myInfoWindow->show();
}


void MapWindow::on_bField2_clicked()
{
    m->mapMonopoly.at(2)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField3_clicked()
{
    m->mapMonopoly.at(3)->sendSignalToInfo();
    myInfoWindow->show();
}


void MapWindow::on_bField5_clicked()
{
    m->mapMonopoly.at(5)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField6_clicked()
{
    m->mapMonopoly.at(6)->sendSignalToInfo();myInfoWindow->openInfo(6);
    myInfoWindow->show();
}

void MapWindow::on_bField7_clicked()
{
    m->mapMonopoly.at(7)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField10_clicked()
{
    m->mapMonopoly.at(10)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField11_clicked()
{
    m->mapMonopoly.at(11)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField12_clicked()
{
    m->mapMonopoly.at(12)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField15_clicked()
{
    m->mapMonopoly.at(15)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField16_clicked()
{
    m->mapMonopoly.at(16)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField17_clicked()
{
    m->mapMonopoly.at(17)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField20_clicked()
{
    m->mapMonopoly.at(20)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField21_clicked()
{
    m->mapMonopoly.at(21)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField22_clicked()
{
    m->mapMonopoly.at(22)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField23_clicked()
{
    m->mapMonopoly.at(23)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField25_clicked()
{
    m->mapMonopoly.at(25)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField26_clicked()
{
    m->mapMonopoly.at(26)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField27_clicked()
{
    m->mapMonopoly.at(27)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField28_clicked()
{
    m->mapMonopoly.at(28)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField30_clicked()
{
    m->mapMonopoly.at(30)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField31_clicked()
{
    m->mapMonopoly.at(31)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField32_clicked()
{
    m->mapMonopoly.at(32)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField33_clicked()
{
    m->mapMonopoly.at(33)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField34_clicked()
{
    m->mapMonopoly.at(34)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField35_clicked()
{
    m->mapMonopoly.at(35)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField40_clicked()
{
    m->mapMonopoly.at(40)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField41_clicked()
{
    m->mapMonopoly.at(41)->sendSignalToInfo();
    myInfoWindow->show();
}

void MapWindow::on_bField42_clicked()
{
    m->mapMonopoly.at(42)->sendSignalToInfo();
    myInfoWindow->show();
}




