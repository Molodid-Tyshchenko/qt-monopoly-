#include "QuestionField.h"

void QuestionField::incident1(std::shared_ptr<AbstractPlayer>& player) {
    int cashPlayer = player->getCash();
    if (cashPlayer >= 1000)
        cashPlayer -= 1000;
    else cashPlayer = 0;
    player->setCash(cashPlayer);
    player->setSkip(1);
    player->setPoints(player->getPoints() - 1);
}

void QuestionField::incident2(std::shared_ptr<AbstractPlayer>& player) {
    player->setSkip(1);
    player->setPoints(player->getPoints() - 1);
}

void QuestionField::incident3(std::shared_ptr<AbstractPlayer>& player) {
    int cashPlayer = player->getCash();
    cashPlayer += 2000;
    player->setCash(cashPlayer);
    player->setPoints(player->getPoints() + 1);
}

void QuestionField::incident4(std::shared_ptr<AbstractPlayer>& player) {
    int cashPlayer = player->getCash();
    if (cashPlayer >= 500)
        cashPlayer -= 500;
    else cashPlayer = 0;
    player->setCash(cashPlayer);
    player->setPoints(player->getPoints() - 1);
}

void QuestionField::incident5(std::shared_ptr<AbstractPlayer>& player) {
    int cashPlayer = player->getCash();
    cashPlayer += 1000;
    player->setCash(cashPlayer);
    player->setPoints(player->getPoints() + 1);
}

void QuestionField::action(std::shared_ptr<AbstractPlayer> player) {
    std::random_device generation;
    int opt = generation() % 5 + 1;
  View display;
    switch (opt) {
    case 1:
    display.showIncident1();
        incident1(player);
        return;
    case 2:
    display.showIncident2();
        incident2(player);
        return;
    case 3:
    display.showIncident3();
        incident3(player);
        return;
    case 4:
    display.showIncident4();
      incident4(player);
        return;
    case 5:
    display.showIncident5();
        incident5(player);
        return;
    default:
        return;
    }


}

void QuestionField::deserialize(const json& data) {
    data.at("id").get_to(id);
}

void QuestionField::sendSignalToInfo(int idPlayer)
{
    emit signal_question(id);
}

void QuestionField::changeColor(int pl_id)
{

}

void QuestionField::pressToButton(std::shared_ptr<AbstractPlayer> player, std::string action)
{

}
// functions for the QuestionField class will be located here
