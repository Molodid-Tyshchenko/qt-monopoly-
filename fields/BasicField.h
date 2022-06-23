#pragma once

#include "Field.h"

#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
#include <string>

#include "../players/AbstractPlayer.h"
#include "../players/Bot.h"
#include "../players/Player.h"

#include "../game/MonopolyManager.h"
#include "../game/Monopoly.h"

class BasicField : public Field {
public:
    BasicField(int id)
        : Field(id) {
        bought = 0;
            level = 1;

    };

    BasicField() : Field() {
    bought = 0;
        level = 1;
    };





    void setLevel(int level);
    void setCostUpgrade(int costUpgrade);
    void setCostDowngrade(int costDowngrade);
    void setCostSell(int costSell);
    void setTax(int tax);
    void setTax1(int tax1);
    void setTax2(int tax2);
    void setTax3(int tax3);
    void setTax4(int tax4);
    void setTax5(int tax5);

    void setAmount(int amount);


    std::string getName();
    std::string getGroup();
    int getLevel();
    int getCost();
    int getCostUpgrade();
    int getCostDowngrade();
    int getCostSell();
    int getTax();
    int getTax1();
    int getTax2();
    int getTax3();
    int getTax4();
    int getTax5();

    int getAmount();


    void info() override;

    std::unique_ptr<AbstractPlayer> buy(std::unique_ptr<AbstractPlayer> player);
    std::unique_ptr<AbstractPlayer> sell(std::unique_ptr<AbstractPlayer> player);
    //std::unique_ptr<AbstractPlayer> pay(std::unique_ptr<AbstractPlayer> player);
    std::unique_ptr<AbstractPlayer> upgrade(std::unique_ptr<AbstractPlayer> player);
    std::unique_ptr<AbstractPlayer> downgrade(std::unique_ptr<AbstractPlayer> player);

    std::unique_ptr<AbstractPlayer> action(std::unique_ptr<AbstractPlayer> player) override;
    void setCostsValues() ;
    void deserialize(const json& data) override;
    void sendSignalToInfo(int) override ;
    void changeColor(int pl_id) override;
    std::unique_ptr<AbstractPlayer> pressToButton(std::unique_ptr<AbstractPlayer> player, std::string action) override;


protected:
    std::string name = "Name";
    std::string group;
    int level;
    int cost;
    int costUpgrade;
    int costDowngrade;
    int costSell;
    int tax;
    int tax1;
    int tax2;
    int tax3;
    int tax4;
    int tax5;
    int currentTax;

    int amount;

signals:
//    void signal(std::string, std::string, int, int, int, int, int, int, int, int, int, int);
};


