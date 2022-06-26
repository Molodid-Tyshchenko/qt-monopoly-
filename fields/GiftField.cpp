#include "GiftField.h"

void GiftField::action(std::shared_ptr<AbstractPlayer> player) {

    std::random_device generation;
    int value = (generation() % 50 + 1) * 100;
    int cash = player->getCash();
    cash += value;

    QString str = "Today is your birthday! Your friends have collected for a gift %1$";
    QMessageBox::information(nullptr, "GIFT", str.arg(value));
    player->setPoints(player->getPoints() + 1);
    player->setCash(cash);


  return;
}

void GiftField::deserialize(const json& data) {
    data.at("id").get_to(id);
}

void GiftField::sendSignalToInfo(int idPlayer)
{
    emit signal_gift(id);
}

void GiftField::changeColor(int pl_id)
{

}

void GiftField::pressToButton(std::shared_ptr<AbstractPlayer> player, std::string action)
{

}

void GiftField::changeLevel(int level)
{

}
// functions for the GiftField class will be located here
