#include "StartField.h"
std::unique_ptr<AbstractPlayer> StartField::action(std::unique_ptr<AbstractPlayer> player) {
    int cash = player->getCash();
    cash += 2000;

    QString str = "Player %1 on the start field! He gets 2000$";

    player->setCash(cash);


  return std::move(player);
}


void StartField::deserialize(const json& data) {
    data.at("id").get_to(id);
}

void StartField::sendSignalToInfo(int idPlayer)
{

}

void StartField::changeColor(int pl_id)
{

}

std::unique_ptr<AbstractPlayer> StartField::pressToButton(std::unique_ptr<AbstractPlayer> player, std::string action)
{

}
// functions for the StartField class will be located here
