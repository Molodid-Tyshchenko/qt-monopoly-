#include "VadimField.h"
std::unique_ptr<AbstractPlayer> VadimField::action(std::unique_ptr<AbstractPlayer> player) {
  player->setPos(9);
  return std::move(player);
}


void VadimField::deserialize(const json& data) {
    data.at("id").get_to(id);
}

void VadimField::sendSignalToInfo()
{
    emit signal_vadim(id);
}

void VadimField::changeColor(int pl_id)
{

}
// functions for the VadimField class will be located here
