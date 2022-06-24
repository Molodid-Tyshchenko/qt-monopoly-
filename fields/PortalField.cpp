#include "PortalField.h"

void PortalField::action(std::shared_ptr<AbstractPlayer> player) {

    std::random_device generation;

    int newPos = generation() % 44;
    int idPlayer = player->getID() - 1;

    QString str = "Player %1 will be teleported to field %2!";
    QMessageBox::information(nullptr, "Portal", str.arg(idPlayer+1).arg(newPos));
    player->setPoints(player->getPoints() +1);
    player->setPos(newPos);
    player->changePos(idPlayer, newPos);
    player->actionForNewPos(idPlayer, newPos);
    player->changeTmpField(newPos);

    return;
}

void PortalField::deserialize(const json& data) {
    data.at("id").get_to(id);
}

void PortalField::sendSignalToInfo(int idPlayer)
{
    emit signal_portal(id);
}

void PortalField::changeColor(int pl_id)
{

}

void PortalField::pressToButton(std::shared_ptr<AbstractPlayer> player, std::string action)
{

}
// functions for the PortalField class will be located here
