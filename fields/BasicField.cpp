#include "BasicField.h"


void BasicField::setTax(int tax) {
    this->tax = tax;
}

void BasicField::setTax1(int tax1) {
    this->tax1 = tax1;
}

void BasicField::setTax2(int tax2) {
    this->tax2 = tax2;
}

void BasicField::setTax3(int tax3) {
    this->tax3 = tax3;
}

void BasicField::setTax4(int tax4) {
    this->tax4 = tax4;
}

void BasicField::setTax5(int tax5) {
    this->tax5 = tax5;
}

void BasicField::setAmount(int amount) {
    this->amount = amount;
}

std::string BasicField::getName()
{
    return name;
}

void BasicField::setLevel(int level) {
    this->level = level;
}

void BasicField::setCostUpgrade(int costUpgrade)
{
    this->costUpgrade = costUpgrade;
}

void BasicField::setCostDowngrade(int costDowngrade)
{
    this->costDowngrade = costDowngrade;
}

void BasicField::setCostSell(int costSell)
{
    this->costSell = costSell;
}

std::string BasicField::getGroup() {
    return group;
}

int BasicField::getCost() {
    return cost;
}

int BasicField::getCostUpgrade()
{
    return costUpgrade;
}

int BasicField::getCostDowngrade()
{
    return costDowngrade;
}

int BasicField::getCostSell()
{
    return costSell;
}

int BasicField::getTax() {
    return tax;
}

int BasicField::getTax1() {
    return tax1;
}

int BasicField::getTax2() {
    return tax2;
}

int BasicField::getTax3() {
    return tax3;
}

int BasicField::getTax4() {
    return tax4;
}

int BasicField::getTax5() {
    return tax5;
}

int BasicField::getLevel() {
    return level;
}
int BasicField::getAmount() {
  return amount;
}
void BasicField::info() {
    std::cout << "it's BasicField\n";
}
void BasicField::changeColor(int pl_id)
{
    emit signal_bought(this->id, pl_id);
}

void BasicField::pressToButton(std::shared_ptr<AbstractPlayer> player, std::string action)
{

    if(action == "sell")
        sell(player);
    else if (action == "upgrade")
        upgrade(player);
    else if (action == "downgrade")
        downgrade(player);

    sendSignalToInfo(player->getID() - 1);
    return;
}


void BasicField::buy(std::shared_ptr<AbstractPlayer> player) {

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
            player->setPoints(player->getPoints() + 10);
            changeColor(player->getID()-1);


        }
        return;
    }
}

void BasicField::sell(std::shared_ptr<AbstractPlayer> player) {

    if (player->getBusiness(getGroup()) == amount) {
        if(!(player->checkLevelBusinessField(group, 1))) {
            QMessageBox::information(nullptr, "Sell field", "You have improved fields in this group. "
                                                         "To sell this field, you need all fields in this group to be level 1!");
            return;
        }
    }

    if (level < 1) {
        QMessageBox::critical(nullptr, "Error", "ERROR!");
        return;
    }
    if (level > 1) {
        QString str = "This field is level %1. To sell a field, you must lower its level!";
        QMessageBox::information(nullptr, "Sell field", str.arg(level));
        return;
    }
//    else {  // level == 1

        QMessageBox::StandardButton reply;
        QString str = "Are you sure you want to sell field %1?";
        reply = QMessageBox::question(nullptr, "Upgrade a field", str.arg(id),
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
        }

        return;
//	}
}
void BasicField::upgrade(std::shared_ptr<AbstractPlayer> player) {

    if (player->getBusiness(getGroup()) != amount) {
        QMessageBox::information(this, "Upgrade a field", "You do not have enough fields for this group. You cannot improve the field!");
        return;
    }

    if (level == 5) {
        QMessageBox::information(this, "Upgrade a field", "You have the maximum level of this field!");
        return;
    }

    int moneyPlayer = player->getCash();
    if (moneyPlayer < costUpgrade) {
        QString str = "Not enough money to upgrade a field %1 (cost %2)";
        QMessageBox::information(this, "Upgrade a field", str.arg(id).arg(costUpgrade));
        return;
    }
    else {

        QMessageBox::StandardButton reply;
        QString str = "Are you sure you want to upgrade field %1 to level %2 (cost %3)?";
        reply = QMessageBox::question(this, "Upgrade a field", str.arg(id).arg(level+1).arg(costUpgrade),
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            moneyPlayer -=  costUpgrade;
            player->setCash(moneyPlayer);

            level++;
            player->SetLevelBusinessField(group, id, level);
            switch (level) {
            case 2:
                currentTax = tax2;
            case 3:
                currentTax = tax3;
            case 4:
                currentTax = tax4;
            case 5:
                currentTax = tax5;
            }

            player->setPoints(player->getPoints() + 5);
        }
        return;
    }

}


void BasicField::downgrade(std::shared_ptr<AbstractPlayer> player) {

    if (level == 1) {
        QMessageBox::information(this, "Upgrade a field", "You have the minimum level of this field!");
        return;
    }

    else { //level>1

        QMessageBox::StandardButton reply;
        QString str = "Are you sure you want to downgrade field %1 to level %2?";
        reply = QMessageBox::question(this, "Upgrade a field", str.arg(id).arg(level-1),
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            int moneyPlayer = player->getCash();
            moneyPlayer += costDowngrade;
            player->setCash(moneyPlayer);

            level--;
            player->SetLevelBusinessField(group, id, level);
            switch (level) {
            case 1:
                currentTax = tax;
            case 2:
                currentTax = tax2;
            case 3:
                currentTax = tax3;
            case 4:
                currentTax = tax4;
            }
            player->setPoints(player->getPoints() - 4);
        }
    }

    return;

}

void BasicField::pay(std::shared_ptr<AbstractPlayer> player)
{

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

void BasicField::action(std::shared_ptr<AbstractPlayer> player) {

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

void BasicField::deserialize(const json& data)  {
    data.at("name").get_to(name);
    data.at("id").get_to(id);
    data.at("group").get_to(group);
    data.at("cost").get_to(cost);
    data.at("tax").get_to(tax1);
    data.at("amount").get_to(amount);
    setCostsValues();
}

void BasicField::sendSignalToInfo(int idPlayer)
{
    emit signal(name, group, level, bought, cost, costUpgrade,
                costDowngrade, costSell, tax1, tax2, tax3, tax4, tax5, idPlayer, id);
}





void BasicField::setCostsValues()
{
    this->costUpgrade = cost/2;
    this->costDowngrade = 0.8*costUpgrade;
    this->costSell = 0.8*cost;
    this->tax = tax1;
    this->tax2 = 1.5*tax1;
    this->tax3 = 1.5*tax2;
    this->tax4 = 1.5*tax3;
    this->tax5 = 1.5*tax4;
    this->currentTax = tax;

}



// functions for the BasicField class will be located here
