#pragma once
#include <string>
#include <memory>
#include <vector>
#include <QObject>

#include "../game/Dice.h"
#include "../game/MonopolyManager.h"

class AbstractPlayer : public QObject {
    Q_OBJECT
public:
    AbstractPlayer();
    AbstractPlayer(const std::string& Name, int Playerid);
    AbstractPlayer(const AbstractPlayer& P);

    void setName(const std::string name);
    void setID(int id);
    void setCash(int cash);
    void setBankrot(bool bankrot);
    void setPos(int pos);
    void setSkip(bool skip);
    void setBot(bool bot);
    void setBusiness(std::string key, int idField);
    void SetLevelBusinessField(std::string key, int idField, int level);
    void setPoints(int points);
    void setColor(std::string color_t);

    std::string getName();
    int getID();
    int getCash();
    bool getBankrot();
    int getPos();
    bool getSkip();
    bool getBot();
    int getPoints();
    std::string getColor();
    int getBusiness(std::string key);
    int getLevelBusinessField(std::string key, int idField);
    bool checkLevelBusinessField(std::string key, int level);

    void removeBusiness(std::string key, int idField);
    int makeTurn();
    virtual void changePos(int id_t,int t_pos) = 0;
  
protected:
    std::string name;
	int id;
	int cash;
	bool bankrot;
	int pos;
	bool skip;
	int points;
    bool bot = true;
    std::string color;

    std::unordered_map<std::string, std::pair<int,int>> business;

signals:
    void signal(QString, QString);
    void signal_changePos(int, int);
    void signal_changeMoney(int, int);

};
