#include "Monopoly.h"
#include "QMessageBox"

//Monopoly::Monopoly() {

//}


void Monopoly::menu(int players_t, int bots_t) {
    numberPlayers = players_t;
    numberBots = bots_t;
    numberAllPlayers = numberPlayers + numberBots;
}

void Monopoly::startGame() {

    int id = 1;
    for (int i = 0; i < numberPlayers; i++) {
        Player a("Human", id);
        players.push_back(std::make_shared<Player>(a));
        id++;
    }
    for (int i = 0; i < numberBots; i++) {
        Bot a("Bot", id);
        players.push_back(std::make_shared<Bot>(a));
        id++;
    }
    stats = new Statistik(numberAllPlayers);
    mapMonopoly = fieldCreation();



}

AbstractPlayer* Monopoly::getPlayer(int i) {
    return players.at(i).get();
}

int Monopoly::getNumberAllPlayers()
{
    return numberAllPlayers;
}

int Monopoly::getCurrentPlayer()
{
    return currentPlayer;
}

void Monopoly::changeTmpField(int tmpField)
{
    this->tmpField = tmpField;
}

//void Monopoly::updateGame() {
//	std::cout << "-----------------\n";
//	std::cout << "The game begins\n";
//	std::cout << "There are " << players.size() << " participants in the game\n";

//  int number_players = players.size();
//  int id_player = 0;

//  Statistik stats(number_players);

//  while(number_players > 1){
//	  if(players[id_player]->getBankrot() == true){
//       continue;
//    }
//	  int tmpField = players[id_player]->makeTurn();

//    players[id_player] = mapMonopoly[tmpField]->action(std::move(players[id_player]));

//	  stats.update_pt(id_player, players[id_player]->getPoints());

//	  id_player++;

//    id_player %= players.size();
//	stats.info();
//  }

//}


void Monopoly::updateGame() {

    if(gameOver) {
        QMessageBox::information(nullptr, "Info", "The game is over!");
        return;
    }


    if(players[currentPlayer]->getBankrot() == -1) {          //проверять на банкрота не обязательно, ибо на него проверка идет в конце функции
        tmpField = players[currentPlayer]->makeTurn();
        players[currentPlayer]->changePos(currentPlayer ,players[currentPlayer]->getPos());
        mapMonopoly[tmpField]->action(players[currentPlayer]);
        if(players[currentPlayer]->getBankrot() == 0) {
            emit signal_changeTextButton("CONTINUE");
            return;
        }
    }
    else if(players[currentPlayer]->getBankrot() == 0) {
        mapMonopoly[tmpField]->action(players[currentPlayer]);
        emit signal_changeTextButton("ROLL THE DICE");
    }

    if(players[currentPlayer]->getBankrot() == 1) {

        int countBankrots = 0;

        for(int i = 0; i < numberAllPlayers; i++) {
            if(players[i]->getBankrot() == 1)
                countBankrots++;
        }

        if(countBankrots >= numberAllPlayers - 1) {
            gameOver = true;
            QMessageBox::information(nullptr, "Info", "The game is over!");
            return;
        }
    }

    while (1) {

        currentPlayer++;
        currentPlayer %= numberAllPlayers;

        if(players[currentPlayer]->getSkip() == true) {
            players[currentPlayer]->setSkip(false);
            QString str = "Player %1 skips a turn";
            QMessageBox::information(nullptr, "Info", str.arg(currentPlayer+1));
            continue;
        }

        if(players[currentPlayer]->getBankrot() == -1) {
            QString str = "The turn goes to the player %1!";
            QMessageBox::information(nullptr, "Info", str.arg(currentPlayer+1));
            break;
        }          
    }
    stats->update_pt(currentPlayer, players[currentPlayer]->getPoints());
}








//std::vector<std::unique_ptr<AbstractPlayer>> Monopoly::get_players(){
//    return players;
//}
//std::vector<std::unique_ptr<Field>> Monopoly::get_map(){
//    return mapMonopoly;
//}
