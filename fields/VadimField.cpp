#include "VadimField.h"
std::unique_ptr<AbstractPlayer> VadimField::action(std::unique_ptr<AbstractPlayer> player) {

    int idPlayer = player->getID() - 1;

    QString str = "Player %1 was going about his business and met Vadim. Then there is only one road - to Polyana :)";
    QMessageBox::information(nullptr, "Portal", str.arg(idPlayer+1));

    player->setPos(9);
    player->changePos(idPlayer, 9);
    return std::move(player);
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

std::unique_ptr<AbstractPlayer> VadimField::pressToButton(std::unique_ptr<AbstractPlayer> player, std::string action)
{

}
// functions for the VadimField class will be located here
