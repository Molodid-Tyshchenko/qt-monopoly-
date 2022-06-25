#include "StartField.h"
void StartField::action(std::shared_ptr<AbstractPlayer> player) {
    int cash = player->getCash();
    cash += 2000;

    QString str = "Player %1 on the start field! He gets 2000$";
    QMessageBox::information(nullptr, "Start field", str.arg(player->getID()));

    player->setCash(cash);
    player->setPoints(player->getPoints() + 5);

    return ;
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

void StartField::pressToButton(std::shared_ptr<AbstractPlayer> player, std::string action)
{

}

void StartField::changeLevel(int level)
{

}
// functions for the StartField class will be located here
