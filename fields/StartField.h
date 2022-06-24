#pragma once

#include "Field.h"

#include "../players/AbstractPlayer.h"
#include "../players/Bot.h"
#include "../players/Player.h"

class StartField : public Field {

public:

    StartField(int id)
        : Field(id) {};

    StartField() : Field() {};

    void info() override{
    std::cout << "it's StartField\n";
  }
    void action(std::shared_ptr<AbstractPlayer> player) override;
    void deserialize(const json& data) override;
    void sendSignalToInfo(int ) override;
    void changeColor(int pl_id) override;
    void pressToButton(std::shared_ptr<AbstractPlayer> player, std::string action) override;

private:



//signals:
//    void signal(std::string, std::string, int, int, int, int, int, int, int, int, int, int) ;
};
