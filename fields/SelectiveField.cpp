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



void SelectiveField::buy(std::shared_ptr<AbstractPlayer> player) {

    int moneyPlayer = player->getCash();
    if (moneyPlayer < cost) {
        QString str = "Not enough money to buy a field %1 (cost %2)";
        QMessageBox::information(nullptr, "Buying a field", str.arg(id).arg(cost));
        return;
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
            player->changeLevelBusinessSelectiveField(group);
        }
        return;
    }
}

void SelectiveField::sell(std::shared_ptr<AbstractPlayer> player) {

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
        player->changeLevelBusinessSelectiveField(group);
    }

    return;

}

void SelectiveField::pay(std::shared_ptr<AbstractPlayer> player) {

    int moneyPlayer = player->getCash();
    int idPlayer = player->getID() - 1;
    int playerBankrot = player->getBankrot();

    if (moneyPlayer < currentTax) {
        if(playerBankrot == -1) {
            QString str = "Player %1 has not enough money to pay player %2 to visit field %3 (price %4$)!\n"
                          "You need to find money and pay off the debt!";
            QMessageBox::information(nullptr, "Payment", str.arg(idPlayer+1).arg(bought).arg(id).arg(currentTax));
            player->setBankrot(0);
            return ;
        }
        else { //playerBankrot == 0 && moneyPlayer < currentTax
            QString str = "Player %1 goes bankrupt! Game over for him :(";
            QMessageBox::information(nullptr, "Payment", str.arg(idPlayer+1));
            player->setPoints(0);
            player->setBankrot(1);
            return ;
        }
    }
    else { //moneyPlayer >= currentTax

        QMessageBox::StandardButton reply;
        QString str = "Player %1 must pay player %2 to visit field %3 (price %4$)!";
        reply = QMessageBox::question(nullptr, "Payment", str.arg(idPlayer+1).arg(bought).arg(id).arg(currentTax),
                                      QMessageBox::Yes|QMessageBox::No );
        if (reply == QMessageBox::Yes) {

            player->transferMoney(bought - 1, currentTax);
            player->setPoints(player->getPoints() + 2);
            QMessageBox::information(nullptr, "Payment", "The operation was successful!");
            player->setBankrot(-1);

            return ;
        }
        else { //reply == QMessageBox::No

            QString str = "Player %1 is too greedy to continuing playing the game, so he goes bankrupt!...";
            QMessageBox::information(nullptr, "Payment", str.arg(idPlayer+1));
            player->setPoints(-100);
            player->setBankrot(1);
            return ;
        }

    }

        return;
}

void SelectiveField::action(std::shared_ptr<AbstractPlayer> player) {

    int numPlayer = player->getID();

    if (bought == 0)
        buy(player);
    else if (bought != numPlayer)
        pay(player);
    else {
        QString str = "Player %1 visited own field %2";
        QMessageBox::information(nullptr, "Own field", str.arg(numPlayer).arg(id));
    }

    return ;
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

void SelectiveField::pressToButton(std::shared_ptr<AbstractPlayer> player, std::string action)
{

    sell(player);

//    level = player->getBusiness(group);
    sendSignalToInfo(player->getID() - 1);

    return;
}

void SelectiveField::setCostsValues()
{

    this->costSell = 0.8*cost;
    this->tax2 = 2*tax;
    this->tax3 = 2*tax2;
    this->currentTax = tax;
}

void SelectiveField::changeLevel(int level)
{
    this->level = level;
    switch (level) {
    case 1:
        currentTax = tax;
    case 2:
        currentTax = tax2;
    case 3:
        currentTax = tax3;

    }
}
// functions for the SelectiveField class will be located here
