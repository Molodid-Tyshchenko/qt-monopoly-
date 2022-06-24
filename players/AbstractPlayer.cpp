#include "AbstractPlayer.h"

AbstractPlayer::AbstractPlayer() {
	name = "";
	id = 0;
	cash = 15000;
    bankrot = -1;
	pos = 0;
	skip = 0;
  bot = true;
  points = 0;
  std::string color = "none";
  
//  std::vector<int> tempV = { };

//	std::string groups[9] = { "humanitarian","PE","DiscreteMath", "NumericalMethods",
//		"Physics",  "DSA",
//	"MathematicalAnalysis", "Circuitry", "Programming" };
//	int k_iter = 0;
//	while (k_iter < 9) {
//		business.insert(std::make_pair(groups[k_iter], tempV));
//		k_iter++;
//	}
}

AbstractPlayer::AbstractPlayer(const std::string& name, int Playerid) {
	this->name = name;
	this->id = Playerid;
	cash = 15000;
    bankrot = -1;
	pos = 0;
	skip = 0;
	points = 0;
    std::string color = "none";

//    std::vector<int> tempV = { };

//      std::string groups[9] = { "humanitarian","PE","DiscreteMath", "NumericalMethods",
//          "Physics",  "DSA",
//      "MathematicalAnalysis", "Circuitry", "Programming" };
//      int k_iter = 0;
//      while (k_iter < 9) {
//          business.insert(std::make_pair(groups[k_iter], tempV));
//          k_iter++;
//      }

}

AbstractPlayer::AbstractPlayer(const AbstractPlayer& p) {
	this->name = p.name;
	this->id = p.id;
	cash = p.cash;
	bankrot = p.bankrot;
	pos = p.pos;
	skip = p.skip;
    bot = p.bot;
    points = p.points;
    business = p.business;
}

void AbstractPlayer::setName(const std::string name) {
	this->name = name;
}

void AbstractPlayer::setID(int id) {
	this->id = id;
}

void AbstractPlayer::setCash(int cash) {
	this->cash = cash;
    emit signal_changeMoney(id - 1, cash);
}

void AbstractPlayer::setBankrot(int bankrot) {
	this->bankrot = bankrot;
}

void AbstractPlayer::setPos(int pos) {
	this->pos = pos;
}

void AbstractPlayer::setSkip(bool skip){
  this->skip = skip;
}

void AbstractPlayer::setBot(bool bot) {
  this->bot = bot;
}

void AbstractPlayer::setPoints(int points) {
	this->points = points;
}

void AbstractPlayer::setColor(std::string color_t) {
    this->color = color_t;
}

void AbstractPlayer::setBusiness(std::string key, int idField) {
    business.insert(std::make_pair(key, std::make_pair(idField, 1)));
}

void AbstractPlayer::SetLevelBusinessField(std::string key, int idField, int level)
{
    int count = business.count(key);
    std::unordered_map <std::string, std::pair<int,int>> :: iterator it = business.find(key);
    for(int i = 0; i < count ; i++, it++) {
        if(it->second.first == idField) {
            it->second.second = level;
            return;
        }
    }
}
void AbstractPlayer::removeBusiness(std::string key, int idField) {
    int count = business.count(key);
    std::unordered_map <std::string, std::pair<int,int>> :: iterator it = business.find(key);

    for(int i = 0; i < count ; i++) {
        if(it->second.first == idField) {
            business.erase(it);
            return;
        }
        it++;
    }
}

std::string AbstractPlayer::getName() {
	return name;
}

int AbstractPlayer::getID() {
	return id;
}

int AbstractPlayer::getCash() {
	return cash;
}

std::string AbstractPlayer::getColor(){
    return color;
}

int AbstractPlayer::getBankrot() {
	return bankrot;
}

int AbstractPlayer::getPos() {
	return pos;
}

bool AbstractPlayer::getSkip() {
	return skip;
}

bool AbstractPlayer::getBot() {
  return bot;
}
int AbstractPlayer::getPoints()
{
	return points;
}


int AbstractPlayer::getBusiness(std::string key) {
    return business.count(key);
}

int AbstractPlayer::getLevelBusinessField(std::string key, int idField)
{
    int count = business.count(key);
    std::unordered_map <std::string, std::pair<int,int>> :: iterator it = business.find(key);
    for(int i = 0; i < count ; i++, it++) {
        if(it->second.first == idField)
            return it->second.second;
    }
    return -1;
}

bool AbstractPlayer::checkLevelBusinessField(std::string key, int level)
{
    int count = business.count(key);
    std::unordered_map <std::string, std::pair<int,int>> :: iterator it = business.find(key);
    for(int i = 0; i < count ; i++, it++) {
        if(it->second.second != level)
            return false;
    }

    return true;
}

int AbstractPlayer::makeTurn(){

    Dice Dice1, Dice2;
    Dice1.randValue();
    Dice2.randValue();

    QString value1 = QString::number(Dice1.getValue());
    QString value2 = QString::number(Dice2.getValue());

    emit signal(value1, value2);

    pos += Dice1.getValue() + Dice2.getValue();
    pos %= 44;


    return pos;
}

void AbstractPlayer::transferMoney(int idPlayer2, int money)
{
    emit signal_transferMoney(id - 1, idPlayer2, money);
}

void AbstractPlayer::actionForNewPos(int idPlayer, int idField)
{
    emit signal_actionForNewPos(idPlayer, idField);
}

void AbstractPlayer::changeTmpField(int tmpField)
{
    emit signal_changeTmpField(tmpField);
}
