#pragma once
#include <random>

#include "Field.h"

#include "../players/AbstractPlayer.h"
#include "../players/Bot.h"
#include "../players/Player.h"

#include "../game/Monopoly.h"

class GiftField : public Field {
public:

    GiftField(int id)
        : Field(id) {};

    GiftField() : Field() {};


    void info() override{
    std::cout << "it's GiftField\n";
  }
    void action(std::shared_ptr<AbstractPlayer> player) override;
    void deserialize(const json& data) override;
    void sendSignalToInfo(int ) override;
    void changeColor(int pl_id) override;
    void pressToButton(std::shared_ptr<AbstractPlayer> player, std::string action) override;
    void changeLevel(int) override;

};
