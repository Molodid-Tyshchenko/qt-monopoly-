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
    std::unique_ptr<AbstractPlayer> action(std::unique_ptr<AbstractPlayer> player) override;
    void deserialize(const json& data) override;
    void sendSignalToInfo() ;
    void changeColor(int pl_id);

  
private:


//signals:
//    void signal(std::string, std::string, int, int, int, int, int, int, int, int, int, int);
};
