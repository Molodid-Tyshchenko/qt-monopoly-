#include "mapwindow.h"
#include "myselectwin.h"
#include "ui_mapwindow.h"
#include "MapInterface.h"


#include <iostream>
#include <QLabel>
#include <QMessageBox>
#include <QFile>
#include <QPropertyAnimation>
#include <QResource>

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
    myStatWin = new StatistikWindow(nullptr, m);
    mPlayers = m->getNumberAllPlayers();
    create_field();

    connect(m, &Monopoly::signal_changeTextButton, this, &MapWindow::changeTextButton);

    connect(m->players[0].get(), &AbstractPlayer::signal, this, &MapWindow::diceValue);
    connect(m->players[0].get(), &AbstractPlayer::signal_changePos, this, &MapWindow::update_pos);
    connect(m->players[0].get(), &AbstractPlayer::signal_changeMoney, this, &MapWindow::update_money);
    connect(m->players[0].get(), &AbstractPlayer::signal_transferMoney, this, &MapWindow::transfer_money);
    connect(m->players[0].get(), &AbstractPlayer::signal_actionForNewPos, this, &MapWindow::action_for_new_pos);
    connect(m->players[0].get(), &AbstractPlayer::signal_changeLevelBusinessSelectiveField, this, &MapWindow::changeLevelSelectiveField);
    connect(m->players[0].get(), &AbstractPlayer::signal_changeTmpField, m, &Monopoly::changeTmpField);



    connect(m->players[1].get(), &AbstractPlayer::signal, this, &MapWindow::diceValue);
    connect(m->players[1].get(), &AbstractPlayer::signal_changePos, this, &MapWindow::update_pos);
    connect(m->players[1].get(), &AbstractPlayer::signal_changeMoney, this, &MapWindow::update_money);
    connect(m->players[1].get(), &AbstractPlayer::signal_transferMoney, this, &MapWindow::transfer_money);
    connect(m->players[1].get(), &AbstractPlayer::signal_actionForNewPos, this, &MapWindow::action_for_new_pos);
    connect(m->players[1].get(), &AbstractPlayer::signal_changeLevelBusinessSelectiveField, this, &MapWindow::changeLevelSelectiveField);
    connect(m->players[1].get(), &AbstractPlayer::signal_changeTmpField, m, &Monopoly::changeTmpField);

    ui->pl3->setHidden(true);
    ui->pl4->setHidden(true);
    ui->icon_pl3->setHidden(true);
    ui->icon_pl4->setHidden(true);

    if(mPlayers == 3){
        connect(m->players[2].get(), &AbstractPlayer::signal, this, &MapWindow::diceValue);
        connect(m->players[2].get(), &AbstractPlayer::signal_changePos, this, &MapWindow::update_pos);
        connect(m->players[2].get(), &AbstractPlayer::signal_changeMoney, this, &MapWindow::update_money);
        connect(m->players[2].get(), &AbstractPlayer::signal_transferMoney, this, &MapWindow::transfer_money);
        connect(m->players[2].get(), &AbstractPlayer::signal_actionForNewPos, this, &MapWindow::action_for_new_pos);
        connect(m->players[2].get(), &AbstractPlayer::signal_changeLevelBusinessSelectiveField, this, &MapWindow::changeLevelSelectiveField);
        connect(m->players[2].get(), &AbstractPlayer::signal_changeTmpField, m, &Monopoly::changeTmpField);

        ui->pl3->setHidden(false);
        ui->icon_pl3->setHidden(false);
    }

    else if(mPlayers == 4) {
        connect(m->players[2].get(), &AbstractPlayer::signal, this, &MapWindow::diceValue);
        connect(m->players[2].get(), &AbstractPlayer::signal_changePos, this, &MapWindow::update_pos);
        connect(m->players[2].get(), &AbstractPlayer::signal_changeMoney, this, &MapWindow::update_money);
        connect(m->players[2].get(), &AbstractPlayer::signal_transferMoney, this, &MapWindow::transfer_money);
        connect(m->players[2].get(), &AbstractPlayer::signal_actionForNewPos, this, &MapWindow::action_for_new_pos);
        connect(m->players[2].get(), &AbstractPlayer::signal_changeLevelBusinessSelectiveField, this, &MapWindow::changeLevelSelectiveField);
        connect(m->players[2].get(), &AbstractPlayer::signal_changeTmpField, m, &Monopoly::changeTmpField);

        connect(m->players[3].get(), &AbstractPlayer::signal, this, &MapWindow::diceValue);
        connect(m->players[3].get(), &AbstractPlayer::signal_changePos, this, &MapWindow::update_pos);
        connect(m->players[3].get(), &AbstractPlayer::signal_changeMoney, this, &MapWindow::update_money);
        connect(m->players[3].get(), &AbstractPlayer::signal_transferMoney, this, &MapWindow::transfer_money);
        connect(m->players[3].get(), &AbstractPlayer::signal_actionForNewPos, this, &MapWindow::action_for_new_pos);
        connect(m->players[3].get(), &AbstractPlayer::signal_changeLevelBusinessSelectiveField, this, &MapWindow::changeLevelSelectiveField);
        connect(m->players[3].get(), &AbstractPlayer::signal_changeTmpField, m, &Monopoly::changeTmpField);

        ui->pl3->setHidden(false);
        ui->pl4->setHidden(false);
        ui->icon_pl3->setHidden(false);
        ui->icon_pl4->setHidden(false);
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

    connect(m->mapMonopoly.at(14).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(19).get(), &Field::signal_bought, this, &MapWindow::changeColor);
    connect(m->mapMonopoly.at(37).get(), &Field::signal_bought, this, &MapWindow::changeColor);



}

void MapWindow::create_field()
{
    //поле кнопок у векторі
    map_storage.push_back(ui->bField0);
    map_storage.push_back(ui->bField1);
    map_storage.push_back(ui->bField2);
    map_storage.push_back(ui->bField3);
    map_storage.push_back(ui->bField4);
    map_storage.push_back(ui->bField5);
    map_storage.push_back(ui->bField6);
    map_storage.push_back(ui->bField7);
    map_storage.push_back(ui->bField8);
    map_storage.push_back(ui->bField9);
    map_storage.push_back(ui->bField10);
    map_storage.push_back(ui->bField11);
    map_storage.push_back(ui->bField12);
    map_storage.push_back(ui->bField13);
    map_storage.push_back(ui->bField14);
    map_storage.push_back(ui->bField15);
    map_storage.push_back(ui->bField16);
    map_storage.push_back(ui->bField17);
    map_storage.push_back(ui->bField18);
    map_storage.push_back(ui->bField19);
    map_storage.push_back(ui->bField20);
    map_storage.push_back(ui->bField21);
    map_storage.push_back(ui->bField22);
    map_storage.push_back(ui->bField23);
    map_storage.push_back(ui->bField24);
    map_storage.push_back(ui->bField25);
    map_storage.push_back(ui->bField26);
    map_storage.push_back(ui->bField27);
    map_storage.push_back(ui->bField28);
    map_storage.push_back(ui->bField29);
    map_storage.push_back(ui->bField30);
    map_storage.push_back(ui->bField31);
    map_storage.push_back(ui->bField32);
    map_storage.push_back(ui->bField33);
    map_storage.push_back(ui->bField34);
    map_storage.push_back(ui->bField35);
    map_storage.push_back(ui->bField36);
    map_storage.push_back(ui->bField37);
    map_storage.push_back(ui->bField38);
    map_storage.push_back(ui->bField39);
    map_storage.push_back(ui->bField40);
    map_storage.push_back(ui->bField41);
    map_storage.push_back(ui->bField42);
    map_storage.push_back(ui->bField43);
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
   //ui->pos1->setText(pos);

   money = QString::number(m->players.at(1)->getCash());
   pos = QString::number(m->players.at(1)->getPos());
   ui->play2->setText("Player 2");
   ui->money2->setText(money+ "$");
   //ui->pos2->setText(pos);

   if (p_t == 3){
       money = QString::number(m->players.at(2)->getCash());
       pos = QString::number(m->players.at(2)->getPos());
       ui->play3->setText("Player 3");
       ui->money3->setText(money + "$");
       //ui->pos3->setText(pos);
   }
   else if (p_t == 4) {
       money = QString::number(m->players.at(2)->getCash());
       pos = QString::number(m->players.at(2)->getPos());
       ui->play3->setText("Player 3");
       ui->money3->setText(money + "$");
       //ui->pos3->setText(pos);

       money = QString::number(m->players.at(3)->getCash());
       pos = QString::number(m->players.at(3)->getPos());
       ui->play4->setText("Player 4");
       //ui->pos4->setText(pos);
       ui->money4->setText(money+ "$");
   }
    playebles = p_t;

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

void MapWindow::changeColor(int id_t, int color_t){
    //myPushButton->setStyleSheet("color: blue");
    QString temp;
    switch(color_t) {
    case 0:{
        temp = "QPushButton { background-color: rgb(186,112,252); }";
        break;
    }
    case 1:{
        temp = "QPushButton { background-color: rgb(245,110,212); }";
        break;
    }
    case 2:{
        temp = "QPushButton { background-color: rgb(181,114,4); }";
        break;
    }
    case 3:{
        temp = "QPushButton { background-color: rgb(126,211,33); }";
        break;
    }
    default: {
        temp = "QPushButton { background-color: rgb(255,255,255); }";
        break;
    }
    }
    map_storage.at(id_t)->setStyleSheet(temp);

}

void MapWindow::update_pos(int id_t, int pos_t)
{
    int x_t = map_storage.at(pos_t)->x();
    int y_t = map_storage.at(pos_t)->y();
    switch(id_t){
    case 0:
        //ui->pos1->setText(QString::number(pos_t));
        ui->pl1->move(x_t+5,y_t+5);
        break;

    case 1:
        //ui->pos2->setText(QString::number(pos_t));
        ui->pl2->move(x_t+5,y_t+40);
        break;

    case 2:
        //ui->pos3->setText(QString::number(pos_t));
        ui->pl3->move(x_t+40,y_t+5);
        break;

    case 3:
        //ui->pos4->setText(QString::number(pos_t));
        ui->pl4->move(x_t+40,y_t+40);
        break;

    }
}

void MapWindow::update_money(int id_t, int money_t)
{
    switch(id_t){
    case 0:
        ui->money1->setText(QString::number(money_t) + "$");
        break;

    case 1:
        ui->money2->setText(QString::number(money_t) + "$");
        break;

    case 2:
        ui->money3->setText(QString::number(money_t) + "$");
        break;

    case 3:
        ui->money4->setText(QString::number(money_t) + "$");
        break;

    }
}

void MapWindow::transfer_money(int idPlayer1, int idPlayer2, int money)
{

    int moneyPlayer1 = m->players.at(idPlayer1)->getCash();
    int moneyPlayer2 = m->players.at(idPlayer2)->getCash();

    moneyPlayer1 -= money;
    moneyPlayer2 += money;

    m->players.at(idPlayer1)->setCash(moneyPlayer1);
    m->players.at(idPlayer2)->setCash(moneyPlayer2);

}

void MapWindow::action_for_new_pos(int idPlayer, int idField)
{
    m->mapMonopoly[idField]->action(m->players[idPlayer]);
}

void MapWindow::changeTextButton(std::string text)
{
    ui->bRollDice->setText(QString::fromStdString(text));
}

void MapWindow::changeLevelSelectiveField(std::vector<int> vec, int level)
{
//    int count = business.count(key);
//    std::multimap <std::string, std::pair<int,int>> :: iterator it = business.find(key);
//    for(int i = 0; i < count ; i++, it++) {
//        if(it->second.first == idField)
//            return it->second.second;
//    }
//    return -1;

    for (auto it : vec) {
        m->mapMonopoly.at(it)->changeLevel(level);
    }


}


void MapWindow::on_bField1_clicked()
{
    m->mapMonopoly.at(1)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}


void MapWindow::on_bField2_clicked()
{
    m->mapMonopoly.at(2)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField3_clicked()
{
    m->mapMonopoly.at(3)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}


void MapWindow::on_bField5_clicked()
{
    m->mapMonopoly.at(5)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField6_clicked()
{
    m->mapMonopoly.at(6)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField7_clicked()
{
    m->mapMonopoly.at(7)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField10_clicked()
{
    m->mapMonopoly.at(10)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField11_clicked()
{
    m->mapMonopoly.at(11)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField12_clicked()
{
    m->mapMonopoly.at(12)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField15_clicked()
{
    m->mapMonopoly.at(15)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField16_clicked()
{
    m->mapMonopoly.at(16)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField17_clicked()
{
    m->mapMonopoly.at(17)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField20_clicked()
{
    m->mapMonopoly.at(20)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField21_clicked()
{
    m->mapMonopoly.at(21)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField22_clicked()
{
    m->mapMonopoly.at(22)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField23_clicked()
{
    m->mapMonopoly.at(23)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField25_clicked()
{
    m->mapMonopoly.at(25)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField26_clicked()
{
    m->mapMonopoly.at(26)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField27_clicked()
{
    m->mapMonopoly.at(27)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField28_clicked()
{
    m->mapMonopoly.at(28)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField30_clicked()
{
    m->mapMonopoly.at(30)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField31_clicked()
{
    m->mapMonopoly.at(31)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField32_clicked()
{
    m->mapMonopoly.at(32)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField33_clicked()
{
    m->mapMonopoly.at(33)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField34_clicked()
{
    m->mapMonopoly.at(34)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField35_clicked()
{
    m->mapMonopoly.at(35)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField40_clicked()
{
    m->mapMonopoly.at(40)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField41_clicked()
{
    m->mapMonopoly.at(41)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}

void MapWindow::on_bField42_clicked()
{
    m->mapMonopoly.at(42)->sendSignalToInfo(m->getCurrentPlayer());
    myInfoWindow->show();
}





void MapWindow::on_bField14_clicked()
{
    m->mapMonopoly.at(14)->sendSignalToInfo(m->getCurrentPlayer());
    mySelecWin->show();
}


void MapWindow::on_bField19_clicked()
{
    m->mapMonopoly.at(19)->sendSignalToInfo(m->getCurrentPlayer());
    mySelecWin->show();
}


void MapWindow::on_bField37_clicked()
{
    m->mapMonopoly.at(37)->sendSignalToInfo(m->getCurrentPlayer());
    mySelecWin->show();
}


void MapWindow::on_bField4_clicked()
{
    m->mapMonopoly.at(4)->sendSignalToInfo(m->getCurrentPlayer());
    myQWin->show();
}


void MapWindow::on_bField13_clicked()
{
    m->mapMonopoly.at(13)->sendSignalToInfo(m->getCurrentPlayer());
    myQWin->show();
}


void MapWindow::on_bField29_clicked()
{
    m->mapMonopoly.at(29)->sendSignalToInfo(m->getCurrentPlayer());
    myQWin->show();
}


void MapWindow::on_bField39_clicked()
{
    m->mapMonopoly.at(39)->sendSignalToInfo(m->getCurrentPlayer());
    myQWin->show();
}


void MapWindow::on_bField18_clicked()
{
    m->mapMonopoly.at(18)->sendSignalToInfo(m->getCurrentPlayer());
    myVadimWin->show();
}


void MapWindow::on_bField8_clicked()
{
    m->mapMonopoly.at(8)->sendSignalToInfo(m->getCurrentPlayer());
    myPortalWin->show();
}


void MapWindow::on_bField24_clicked()
{
    m->mapMonopoly.at(24)->sendSignalToInfo(m->getCurrentPlayer());
    myPortalWin->show();
}


void MapWindow::on_bField36_clicked()
{
    m->mapMonopoly.at(36)->sendSignalToInfo(m->getCurrentPlayer());
    myPortalWin->show();
}


void MapWindow::on_bField43_clicked()
{
    m->mapMonopoly.at(43)->sendSignalToInfo(m->getCurrentPlayer());
    myPortalWin->show();
}


void MapWindow::on_bField38_clicked()
{

    m->mapMonopoly.at(38)->sendSignalToInfo(m->getCurrentPlayer());
    myGiftWin->show();
}


void MapWindow::on_bField9_clicked()
{
    m->mapMonopoly.at(9)->sendSignalToInfo(m->getCurrentPlayer());
    myPolyanaWin->show();
}



void MapWindow::on_pushButton_2_clicked()
{
    m->stats->info();
    myStatWin->show();
}

