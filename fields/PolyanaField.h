#pragma once

#include "Field.h"

#include "../players/AbstractPlayer.h"
#include "../players/Bot.h"
#include "../players/Player.h"

#include "../game/Monopoly.h"

class PolyanaField : public Field {
public:

    PolyanaField(int id)
        : Field(id) {};

    PolyanaField() : Field() {};

    void info() override{
    std::cout << "it's PolyanaField\n";
  }
    void action(std::shared_ptr<AbstractPlayer> player) override;
    void deserialize(const json& data) override;
    void sendSignalToInfo(int ) override;
    void changeColor(int pl_id) override;
    void pressToButton(std::shared_ptr<AbstractPlayer> player, std::string action) override;
    void changeLevel(int) override;
};
