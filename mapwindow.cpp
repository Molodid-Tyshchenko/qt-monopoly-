#include "mapwindow.h"
#include "myselectwin.h"
#include "ui_mapwindow.h"
#include "MapInterface.h"


#include <iostream>
#include <QLabel>
#include <QMessageBox>
#include <QFile>


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
    mySelecWin = new SelectiveWindow(nullptr,m);
    myQWin = new QuestWindow(nullptr, m);
    myVadimWin = new VadimWindow(nullptr, m);
    myGiftWin = new GiftWindow(nullptr, m);
    myPolyanaWin = new PolyanaWindow(nullptr, m);
    myPortalWin = new PortalWindow(nullptr, m);
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
    connect(m->mapMonopoly.at(1).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(2).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(3).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(5).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(6).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(7).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(10).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(11).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(12).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(15).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(16).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(17).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(20).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(21).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(22).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(23).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(25).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(26).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(27).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(28).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(30).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(31).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(32).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(33).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(34).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(35).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(40).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(41).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(42).get(), &Field::signal_bought, this, &MapWindow::changeColor);

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
    playebles = p_t;

}

void MapWindow::on_bRollDice_clicked()
{
    m->updateGame();
    QString pos;
    ui->pos1->setText(QString::number(m->getPlayer(0)->getPos()));
    ui->pos2->setText(QString::number(m->getPlayer(1)->getPos()));
    if (playebles == 3){
        pos = QString::number(m->players.at(2)->getPos());
        ui->pos3->setText(pos);
    }
    else if (playebles == 4) {
        pos = QString::number(m->players.at(2)->getPos());
        ui->pos3->setText(pos);
        pos = QString::number(m->players.at(3)->getPos());
        ui->pos4->setText(pos);
    }
}

void MapWindow::diceValue(QString value1, QString value2)
{
    ui->dice1->setText(value1);
    ui->dice2->setText(value2);
}

void MapWindow::changeColor(int id_t, int color_t){
    //myPushButton->setStyleSheet("color: blue");
    QString temp;
    switch(color_t) {
    case 0:{
        temp = "QPushButton { background-color: red; }";
        break;
    }
    case 1:{
        temp = "QPushButton { background-color: blue; }";
        break;
    }
    case 2:{
        temp = "QPushButton { background-color: yellow; }";
        break;
    }
    case 3:{
        temp = "QPushButton { background-color: green; }";
        break;
    }
    default: break;
    }
    switch(id_t) {
        case 1: {
            ui->bField1->setStyleSheet(temp);
            break;
        }
        case 2: {
            ui->bField2->setStyleSheet(temp);
            break;
        }
        case 3: {
            ui->bField3->setStyleSheet(temp);
            break;
        }
        case 5: {
            ui->bField5->setStyleSheet(temp);
            break;
       }
       case 6: {
           ui->bField6->setStyleSheet(temp);
           break;
       }
       case 7: {
           ui->bField7->setStyleSheet(temp);
           break;
       }
    case 10: {
        ui->bField10->setStyleSheet(temp);
        break;
    }
        case 11: {
            ui->bField11->setStyleSheet(temp);
            break;
        }
        case 12: {
            ui->bField12->setStyleSheet(temp);
            break;
        }
        case 15: {
            ui->bField15->setStyleSheet(temp);
            break;
        }
    case 16: {
        ui->bField16->setStyleSheet(temp);
        break;
    }
    case 17: {
        ui->bField17->setStyleSheet(temp);
        break;
    }
    case 20: {
        ui->bField20->setStyleSheet(temp);
        break;
    }
    case 21: {
        ui->bField21->setStyleSheet(temp);
        break;
    }
    case 22: {
        ui->bField22->setStyleSheet(temp);
        break;
    }
    case 23: {
        ui->bField23->setStyleSheet(temp);
        break;
    }
    case 25: {
        ui->bField25->setStyleSheet(temp);
        break;
    }
    case 26: {
        ui->bField26->setStyleSheet(temp);
        break;
    }
    case 27: {
        ui->bField27->setStyleSheet(temp);
        break;
    }
    case 28: {
        ui->bField28->setStyleSheet(temp);
        break;
    }
    case 30: {
        ui->bField30->setStyleSheet(temp);
        break;
    }
    case 31: {
        ui->bField31->setStyleSheet(temp);
        break;
    }
    case 32: {
        ui->bField32->setStyleSheet(temp);
        break;
    }
    case 33: {
        ui->bField33->setStyleSheet(temp);
        break;
    }
    case 34: {
        ui->bField34->setStyleSheet(temp);
        break;
    }
    case 35: {
        ui->bField35->setStyleSheet(temp);
        break;
    }
    case 40: {
        ui->bField40->setStyleSheet(temp);
        break;
    }
    case 41: {
        ui->bField41->setStyleSheet(temp);
        break;
    }
    case 42: {
        ui->bField42->setStyleSheet(temp);
        break;
    }
    default: break;
}

}


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





void MapWindow::on_bField14_clicked()
{
    m->mapMonopoly.at(14)->sendSignalToInfo();
    mySelecWin->show();
}


void MapWindow::on_bField19_clicked()
{
    m->mapMonopoly.at(19)->sendSignalToInfo();
    mySelecWin->show();
}


void MapWindow::on_bField37_clicked()
{
    m->mapMonopoly.at(37)->sendSignalToInfo();
    mySelecWin->show();
}


void MapWindow::on_bField4_clicked()
{
    m->mapMonopoly.at(4)->sendSignalToInfo();
    myQWin->show();
}


void MapWindow::on_bField13_clicked()
{
    m->mapMonopoly.at(13)->sendSignalToInfo();
    myQWin->show();
}


void MapWindow::on_bField29_clicked()
{
    m->mapMonopoly.at(29)->sendSignalToInfo();
    myQWin->show();
}


void MapWindow::on_bField39_clicked()
{
    m->mapMonopoly.at(39)->sendSignalToInfo();
    myQWin->show();
}


void MapWindow::on_bField18_clicked()
{
    m->mapMonopoly.at(18)->sendSignalToInfo();
    myVadimWin->show();
}


void MapWindow::on_bField8_clicked()
{
    m->mapMonopoly.at(8)->sendSignalToInfo();
    myPortalWin->show();
}


void MapWindow::on_bField24_clicked()
{
    m->mapMonopoly.at(24)->sendSignalToInfo();
    myPortalWin->show();
}


void MapWindow::on_bField36_clicked()
{
    m->mapMonopoly.at(36)->sendSignalToInfo();
    myPortalWin->show();
}


void MapWindow::on_bField43_clicked()
{
    m->mapMonopoly.at(43)->sendSignalToInfo();
    myPortalWin->show();
}


void MapWindow::on_bField38_clicked()
{
    m->mapMonopoly.at(38)->sendSignalToInfo();
    myGiftWin->show();
}


void MapWindow::on_bField9_clicked()
{
    m->mapMonopoly.at(9)->sendSignalToInfo();
    myPolyanaWin->show();
}

