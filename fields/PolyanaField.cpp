#include "PolyanaField.h"

std::unique_ptr<AbstractPlayer> PolyanaField::action(std::unique_ptr<AbstractPlayer> player) {
  return std::move(player);
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

std::unique_ptr<AbstractPlayer> PolyanaField::pressToButton(std::unique_ptr<AbstractPlayer> player, std::string action)
{

}
// functions for the PolyanaField class will be located here
