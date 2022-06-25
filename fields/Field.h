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
    virtual void deserialize(const json& data) = 0;
    virtual void sendSignalToInfo(int) = 0;
    virtual void changeColor(int pl_id) = 0;
    virtual void pressToButton(std::shared_ptr<AbstractPlayer> player, std::string action) = 0;
    virtual void changeLevel(int) = 0;

    int getAmount();

protected:
    int id;
    int bought;

signals:
    void signal(std::string, std::string, int, int, int, int, int, int, int, int, int, int, int, int, int);
    void signal_selective (std::string, std::string, int, int, int, int, int, int, int, int, int);
    void signal_question(int);
    void signal_vadim(int);
    void signal_portal(int);
    void signal_gift(int);
    void signal_polyana(int);
    void signal_bought(int, int);
};

