#include "Player.h"

int Player::makeTurn(){

    Dice Dice1, Dice2;
    Dice1.randValue();
    Dice2.randValue();
    //display.firstDiceValue(Dice1.getValue());
    //display.secondDiceValue(Dice2.getValue());


    pos += Dice1.getValue() + Dice2.getValue();
    pos %= 44;
    //display.movedField(name, pos);
    return pos;
}

int Player::move(){


}


/*add_or_remove(std::unique_ptr<AbstractPlayer>& player){
  std::cout << player->name() << "\n\n";
}*/
