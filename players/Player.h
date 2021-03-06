#pragma once
#include <string>
#include <iostream>

#include "AbstractPlayer.h"
#include "../game/Monopoly.h"

class Player : public AbstractPlayer {
public:
	Player(const std::string& Name, int Playerid)
		: AbstractPlayer(Name, Playerid) {
            bankrot = -1;
            bot = false;
    };
    
    Player() : AbstractPlayer() {};

  int makeTurn();
  int move();
  void changePos(int id_t,int t_pos) override;
  
private:
};


