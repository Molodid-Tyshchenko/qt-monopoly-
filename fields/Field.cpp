#include "Field.h"

Field::Field() {
    this->id = -1;
    this->bought = 0;
}

Field::Field(int id) {
    this->id = id;
    this->bought = 0;
}

void Field::setID(int id) {
    this->id = id;
}

void Field::setBought(int b) {
    this->bought = b;
}

int Field::getID() {
    return id;
}

int Field::getBought() {
    return bought;
}

//void Field::sendSignalToInfo()
//{
//    emit signal();
//}
