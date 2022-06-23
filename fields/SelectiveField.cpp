#include "SelectiveField.h"

void SelectiveField::setGroup(std::string g) {
    this->group = g;
}

void SelectiveField::setCost(int cost) {
    this->cost = cost;
}

void SelectiveField::setTax(int tax) {
    this->tax = tax;
}

void SelectiveField::setAmount(int amount) {
    this->amount = amount;
}

std::string SelectiveField::getGroup() {
    return group;
}

int SelectiveField::getCost(){
  return cost;
}

int SelectiveField::getTax(){
  return tax;
}

int SelectiveField::getAmount() {
    return amount;
}

//std::unique_ptr<AbstractPlayer> SelectiveField::buy(std::unique_ptr<AbstractPlayer> player) {
//  View display;
//	int moneyPlayer = player->getCash();
// 	if (moneyPlayer < getCost()) {
//     display.noEnoughMoney();
//		return std::move(player);
//	}
//	else {
//		moneyPlayer -=  getCost();
//		player->setCash(moneyPlayer);
//		int idPlayer = player->getID();
//		setBought(idPlayer);
//		player->setPoints(player->getPoints() + 10);
//		player->setBusiness(getGroup());
//		return std::move(player);
//	}
//}






std::unique_ptr<AbstractPlayer> SelectiveField::buy(std::unique_ptr<AbstractPlayer> player) {

    int moneyPlayer = player->getCash();
    if (moneyPlayer < cost) {
        QString str = "Not enough money to buy a field %1 (cost %2)";
        QMessageBox::information(nullptr, "Buying a field", str.arg(id).arg(cost));
        return std::move(player);
    }
    else {
        QMessageBox::StandardButton reply;
        QString str = "Do you want to buy this field %1 (cost %2)?";
        reply = QMessageBox::question(nullptr, "Buying a field", str.arg(id).arg(cost),
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            moneyPlayer -=  cost;
            player->setCash(moneyPlayer);
            int idPlayer = player->getID();
            setBought(idPlayer);
            player->setPoints(player->getPoints() + 10);
            player->setBusiness(getGroup(), id);
            changeColor(player->getID()-1);
            level = player->getBusiness(group);


        }
        return std::move(player);
    }
}

std::unique_ptr<AbstractPlayer> SelectiveField::sell(std::unique_ptr<AbstractPlayer> player) {

    QMessageBox::StandardButton reply;
    QString str = "Are you sure you want to sell field %1?";
    reply = QMessageBox::question(nullptr, "Sell a field", str.arg(id),
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        int moneyPlayer = player->getCash();

        moneyPlayer += costSell;
        player->setCash(moneyPlayer);
        setBought(0);
            //delete remembering the owner of field
        player->removeBusiness(getGroup(), id);
        player->setPoints(player->getPoints() - 5);
        changeColor(-1);
        level = player->getBusiness(group);
    }

    return std::move(player);

}

void SelectiveField::pay(std::unique_ptr<AbstractPlayer> player) {

}

std::unique_ptr<AbstractPlayer> SelectiveField::action(std::unique_ptr<AbstractPlayer> player) {

//  if(player->getBot() == true){
//    return std::move(player);
//  }

    if (getBought() == 0) {
        player = buy(std::move(player));
    }
    return std::move(player);



}

void SelectiveField::deserialize(const json& data) {
    data.at("id").get_to(id);
    data.at("group").get_to(group);
    data.at("cost").get_to(cost);
    data.at("tax").get_to(tax);
    data.at("amount").get_to(amount);
    setCostsValues();
}

void SelectiveField::sendSignalToInfo(int idPlayer)
{
    //emit signal_selective(id, bought, group, cost, tax, amount);

    emit signal_selective(name, group, level, bought, cost, costSell, tax, tax2, tax3, idPlayer, id);
}

void SelectiveField::changeColor(int pl_id) {
    emit signal_bought(this->id, pl_id);
}

std::unique_ptr<AbstractPlayer> SelectiveField::pressToButton(std::unique_ptr<AbstractPlayer> player, std::string action)
{

    player = sell(std::move(player));

//    level = player->getBusiness(group);
    sendSignalToInfo(player->getID() - 1);

    return std::move(player);
}

void SelectiveField::setCostsValues()
{

    this->costSell = 0.8*cost;
    this->tax2 = 2*tax;
    this->tax3 = 2*tax2;
    this->currentTax = tax;
}
// functions for the SelectiveField class will be located here
