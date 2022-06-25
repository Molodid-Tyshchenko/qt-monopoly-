#pragma once
#include <string>
#include <unordered_map>
#include <QObject>
#include "../players/AbstractPlayer.h"

#include "../lib/json.hpp"
#include <QMessageBox>

class Field : public QWidget {
    Q_OBJECT
public:
    Field();
    Field(int id);

    void setID(int id);
    void setBought(int b);

    int getID();
    int getBought();

    virtual void info() = 0;
    virtual void action(std::shared_ptr<AbstractPlayer> player) = 0;
    //virtual void setCostsValues() = 0;
    virtual void deserialize(const json& data) = 0;
    virtual void sendSignalToInfo(int) = 0;
    virtual void changeColor(int pl_id) = 0;
    virtual void pressToButton(std::shared_ptr<AbstractPlayer> player, std::string action) = 0;
    virtual void changeLevel(int) = 0;


//    virtual void setLevel(int level);
//    virtual void setCostUpgrade(int costUpgrade);
//    virtual void setCostDowngrade(int costDowngrade);
//    virtual void setCostSell(int costSell);
//    virtual void setTax(int tax);
//    virtual void setTax1(int tax1);
//    virtual void setTax2(int tax2);
//    virtual void setTax3(int tax3);
//    virtual void setTax4(int tax4);
//    virtual void setTax5(int tax5);

//    virtual void setAmount(int amount);


//    virtual std::string getName();
//    virtual std::string getGroup();
//    virtual int getLevel();
//    virtual int getCost();
//    virtual int getCostUpgrade();
//    virtual int getCostDowngrade();
//    virtual int getCostSell();
//    virtual int getTax();
//    virtual int getTax1();
//    virtual int getTax2();
//    virtual int getTax3();
//    virtual int getTax4();
//    virtual int getTax5();

    int getAmount();




protected:
    int id;
    int bought;

private:


signals:
    void signal(std::string, std::string, int, int, int, int, int, int, int, int, int, int, int, int, int);
    //void signal_selective (int, int, std::string, int, int, int);
    void signal_selective (std::string, std::string, int, int, int, int, int, int, int, int, int);
    void signal_question(int);
    void signal_vadim(int);
    void signal_portal(int);
    void signal_gift(int);
    void signal_polyana(int);
    void signal_bought(int, int);
};

