#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>

#include "../players/AbstractPlayer.h"
#include "../players/Bot.h"
#include "../players/Player.h"

#include "../game/Actions.h"
#include "../game/Dice.h"

#include "../fields/Field.h"
#include "../game/Statistik.h"

#include <QObject>
#include <QWidget>

class Monopoly : public QObject {
  Q_OBJECT
public:
//    Monopoly();
    void menu(int players_t);
    void startGame();   // function with initial data
    void updateGame();	// the game

    std::vector<std::shared_ptr<AbstractPlayer>> players;
    std::vector<std::shared_ptr<Field>> mapMonopoly;
    QWidget *myMapWindow;
    AbstractPlayer* getPlayer(int);
    Statistik* stats;
    int getNumberAllPlayers();
    int getCurrentPlayer();



private:
    int numberPlayers = 0;
    int numberBots = 0;
    int currentPlayer = 0;
    int numberAllPlayers = 0;
    Dice Dice1;
    Dice Dice2;


    bool lock = 0;
    int tmpField;
    bool gameOver = 0;

signals:
    void signal_changeTextButton(std::string);


public slots:

    void changeTmpField(int tmpField);

};

class View : public QWidget {
public:
  void BotBuy(){
    std::cout << "decided to buy a field\n";
  }
  void actionBuyPlayer() {
   // std::cout << "Choose an action:\n" << "1. Buy the field\n" << "Other value - cancel(skip)\n";
  }
  void noEnoughMoney(){
    std::cout << "No enough money :(" << std::endl;
  }
  void playerField(){
    std::cout << "Choose an action:\n"
                << "1. Sell the field\n"
                << "2. Upgrade the field\n"
                << "3. Downgrade the field\n"
                << "Other value - cancel(skip)\n";
  }
  void alreadyUpgrade(){
    std::cout << "You have already upgrated the field in this step" << std::endl;
  }
  void showErr(){
    std::cout << "ERROR" << std::endl;
  }
  void notSellImField() {
    std::cout << "You can't sell the field, because you have an improved fields" << std::endl;
  }
  void notUpgNoMonop() {
    std::cout << "You cannot upgrade\n Tip: you need to own all fields of this monopoly to upgrade\n";
  }
  void lowMoney() {
    std::cout << "You are low on money. \n Tip: Try to collect rent.\n";
  }
  void sucUpg() {
    std::cout << "You've sucessfully upgraded the field!\n";
  }
  void notDownNoMonop(){
    std::cout << "You cannot downgrade the field\n Tip: you need to own all fields of this monopoly to downgrate\n";
  }
  void minLevel(){
        std::cout << "You have the minimum field level " << std::endl;
  }
  void showIncident1() {
    QMessageBox::information(this, "IASA event!", "Today is the IASA event, you spent 1000 money and skip one move because "
                                                  "of severe headache :)", QMessageBox::Ok);
    //std::cout << "Today is the IASA event, you spent 1000 money and skip one move because of severe headache :)" << std::endl;
  }
  void showIncident2() {
      QMessageBox::information(this, "Bokhonov...", "You suffered from bullying by Bokhonov and decided to watch the series, "
                                                    "so you skip one move", QMessageBox::Ok);
   // std::cout << "You suffered from bullying by Bokhonov and decided to watch the series, so you skip one move" << std::endl;
  }
  void showIncident3() {
      QMessageBox::information(this, "Scholarship! Yay!", "Today is scholarship day and you get +2000 money :)", QMessageBox::Ok);
   // std::cout << "Today is scholarship day and you get +2000 money :)" << std::endl;
  }
  void showIncident4() {
      QMessageBox::information(this, "White Naliv", "You met a friend and you sat in White Naliv, so you lost 500 money", QMessageBox::Ok);
   // std::cout << "You met a friend and you sat in White Naliv, so you lost 500 money" << std::endl;
  }
  void showIncident5() {
      QMessageBox::information(this, "Money on the grass?...", "You found 1000 money in the grass near the dorm and of course you took them :)))", QMessageBox::Ok);
    //std::cout << "You found 1000 money in the grass near the dorm and of course you took them :)))" << std::endl;
  }
  void unknownMove(){
    std::cout << "Unknown (skip)...\n\n";
  }
  void input(){
    std::cout << "input: ";
  }
  void throwDice(int temp_id){
    std::cout << "\nplayer number " << temp_id << " chooses:\n"
            << "1. trade \n2. add / remove an asterisk from the field \n3. throw the dice\n\n";
  }
  void throwDiceBot(int temp_id){
    std::cout << "\nplayer number " << temp_id << " chooses:\n"
            << "1. trade \n2. add / remove an asterisk from the field \n3. throw the dice\n\n"
            << "Bot decided to throw the dice";
  }
  void firstDiceValue(int value){
    std::cout << "On the first bone: " << value << std::endl;
  }
  void secondDiceValue(int value){
  std::cout << "On the second bone: " << value << std::endl;
  }
  void gift(){
    std::cout << "received a gift";
  }
  void movedField(std::string name, int pos){
    std::cout << name << " moved to field " << pos << "\n";
    std::cout << "---------------------------\n";
  }
  void actionSellPlayer() {
    std::cout << "Choose an action:\n"
            << "1. Sell the field\n"
            << "Other value - cancel(skip)\n";
  }
};

class Model {
public:
  int inputOpt(){
    int opt;
    std::cin >> opt;
    return opt;
  }

};

class Controller {

};
