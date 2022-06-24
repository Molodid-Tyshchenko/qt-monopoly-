#pragma once

#include "Field.h"

#include "../players/AbstractPlayer.h"
#include "../players/Bot.h"
#include "../players/Player.h"

#include "../game/Monopoly.h"

class QuestionField : public Field {
public:

    QuestionField(int id)
        : Field(id) {};

    QuestionField() : Field() {};

    void info() override{
    std::cout << "it's QuestionField\n";
  }
    void incident1(std::shared_ptr<AbstractPlayer>& player);
    void incident2(std::shared_ptr<AbstractPlayer>& player);
    void incident3(std::shared_ptr<AbstractPlayer>& player);
    void incident4(std::shared_ptr<AbstractPlayer>& player);
    void incident5(std::shared_ptr<AbstractPlayer>& player);

    void action(std::shared_ptr<AbstractPlayer> player) override;
    void deserialize(const json& data) override;
    void sendSignalToInfo(int ) override;
    void changeColor(int pl_id) override;
    void pressToButton(std::shared_ptr<AbstractPlayer> player, std::string action) override;


private:


//signals:
//    void signal(std::string, std::string, int, int, int, int, int, int, int, int, int, int);
};
