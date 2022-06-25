#include "PolyanaField.h"

void PolyanaField::action(std::shared_ptr<AbstractPlayer> player) {
  return;
}

void PolyanaField::deserialize(const json& data) {
    data.at("id").get_to(id);
}

void PolyanaField::sendSignalToInfo(int idPlayer)
{
    emit signal_polyana(id);
}

void PolyanaField::changeColor(int pl_id)
{

}

void PolyanaField::pressToButton(std::shared_ptr<AbstractPlayer> player, std::string action)
{

}

void PolyanaField::changeLevel(int level)
{

}
// functions for the PolyanaField class will be located here
