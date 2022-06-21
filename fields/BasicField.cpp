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

std::unique_ptr<AbstractPlayer> BasicField::buy(std::unique_ptr<AbstractPlayer> player) {
  View display;
	int moneyPlayer = player->getCash();
 	if (moneyPlayer < getCost()) {
		display.lowMoney();
		return std::move(player);
	}
	else {
		moneyPlayer -=  getCost();
		player->setCash(moneyPlayer);
		int idPlayer = player->getID();
		setBought(idPlayer);
		player->setPoints(player->getPoints() + 10);
		player->setBusiness(getGroup());
		return std::move(player);
	}
}

std::unique_ptr<AbstractPlayer> BasicField::sell(std::unique_ptr<AbstractPlayer> player) {
  View display;
	int level = getLevel();

	if (level < 0) {
    display.showErr();
		return std::move(player);
	}
	if (level > 0) {
    display.notSellImField();
		return std::move(player);
	}
	else {  // level == 0
		int moneyPlayer = player->getCash();
		int costSell = getCost() * 0.75;
		moneyPlayer += costSell;
		setBought(0);
		//delete remembering the owner of field 
		std::string group = getGroup();
		player->removeBusiness(group);
		player->setPoints(player->getPoints() - 5);
		/*int amountPlayer = player->getPurchasedField(group);
		amountPlayer--;
		player->setPurchasedField(group, amountPlayer);*/
		return std::move(player);

	}
}
std::unique_ptr<AbstractPlayer> BasicField::upgrade(std::unique_ptr<AbstractPlayer> player) {
  View display;
	if (player->getBusiness(getGroup()) != getAmount()) {
    display.notUpgNoMonop();
		return std::move(player);
	}
	
	int upg_cost = getCost() * 0.5;
	int pl_cash = player->getCash();
	if (pl_cash < upg_cost) {
		
		return std::move(player);
	}
	player->setCash(pl_cash - upg_cost);
	level++;
	setTax(getTax() * 1.25);
	player->setPoints(player->getPoints() + 3);
  display.sucUpg();
	return std::move(player);
}


std::unique_ptr<AbstractPlayer> BasicField::downgrade(std::unique_ptr<AbstractPlayer> player) {
  View display;
	if (player->getBusiness(getGroup()) != getAmount()) {
    display.notDownNoMonop();
		return std::move(player);
	}
	
	int level_t = getLevel();
	if (level_t == 0) {
    display.minLevel();
		return std::move(player);;
	}
	else { //level>0
		int moneyPlayer = player->getCash();
		int costDowngrade = getCost() * 1.5;
		setTax(getTax() / 1.25);
		player->removeBusiness(getGroup());
		moneyPlayer += costDowngrade;
		player->setCash(moneyPlayer);
		player->setPoints(player->getPoints() - 2);
		level--;
	}
  return std::move(player);
}

std::unique_ptr<AbstractPlayer> BasicField::action(std::unique_ptr<AbstractPlayer> player) {
  Model option;
  View display;
	if (getBought() == 0) {

    if(player->getBot() == true){
      display.BotBuy();
     
      player = buy(std::move(player));
      return std::move(player);
    }

    display.actionBuyPlayer();
		switch (option.inputOpt()) {
		case 1:
			player = buy(std::move(player));
      return std::move(player);
		default: 
      return std::move(player);
		}
	}


	int counterUpgrade = 0;

	if (getBought() == player->getID()) {

    if(player->getBot() == true){
      return std::move(player);
    }

		while (1) {
      display.playerField();
			switch (option.inputOpt()) {
			case 1:
        player = sell(std::move(player));
				return std::move(player);
			case 2:
				if (counterUpgrade == 1){
          display.alreadyUpgrade();
        }
				else {
          player = upgrade(std::move(player));
					counterUpgrade++;
				}
        return std::move(player);	
			case 3:
        player = downgrade(std::move(player));
        return std::move(player);
        return std::move(player);
			default:
				return std::move(player);
			}
		}	
	}

	if (getBought() != 0 && getBought() != player->getID()) {
		return std::move(player);
	}
}

void BasicField::deserialize(const json& data)  {
    data.at("id").get_to(id);
    data.at("group").get_to(group);
    data.at("cost").get_to(cost);
    data.at("tax").get_to(tax1);
    data.at("amount").get_to(amount);
    setCostsValues();
}

void BasicField::sendSignalToInfo()
{
    emit signal(name, group, level, cost, costUpgrade,
                 costDowngrade, costSell, tax1, tax2, tax3, tax4, tax5);
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

}



// functions for the BasicField class will be located here
