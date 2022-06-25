#include "VadimField.h"
void VadimField::action(std::shared_ptr<AbstractPlayer> player) {

    int idPlayer = player->getID() - 1;

    QString str = "Player %1 was going about his business and met Vadim. Then there is only one road - to Polyana :)";
    QMessageBox::information(nullptr, "Portal", str.arg(idPlayer+1));

    player->setPos(9);
    player->changePos(idPlayer, 9);
    player->setPoints(player->getPoints() + 2);
    return;
}


void VadimField::deserialize(const json& data) {
    data.at("id").get_to(id);
}

void VadimField::sendSignalToInfo(int idPlayer)
{
    emit signal_vadim(id);
}

void VadimField::changeColor(int pl_id)
{

}

void VadimField::pressToButton(std::shared_ptr<AbstractPlayer> player, std::string action)
{

}

void VadimField::changeLevel(int level)
{

}
// functions for the VadimField class will be located here
