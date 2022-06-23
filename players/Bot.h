#pragma once
#include <string>
#include <iostream>

#include "AbstractPlayer.h"

#include "../game/Monopoly.h"

class Bot : public AbstractPlayer {
public:
	Bot(const std::string& Name, int Playerid)
		: AbstractPlayer(Name, Playerid) {
      bankrot = false;
      bot = true;
    };

  Bot() : AbstractPlayer() {};

  int makeTurn(); 
  int move();
  void changePos(int id_t,int t_pos) override;
  
private:
	
};
