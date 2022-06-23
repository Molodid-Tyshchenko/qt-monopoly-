#include "Monopoly.h"
#include "QMessageBox"

//Monopoly::Monopoly(QWidget* w) {
//    myMapWindow = w;
//}


void Monopoly::menu(int players_t, int bots_t) {
    numberPlayers = players_t;
    numberBots = bots_t;
    numberAllPlayers = numberPlayers + numberBots;
    std::cout << numberAllPlayers << std::endl;
}

void Monopoly::startGame() {
    //(255,255,255)
    std::vector <std::string> color;
    color.push_back("QPushButton { background-color: red; }");
    color.push_back("QPushButton { background-color: yellow; }");
    color.push_back("QPushButton { background-color: blue; }");
    color.push_back("QPushButton { background-color: green; }");

	int id = 1;
	for (int i = 0; i < numberPlayers; i++) {
		Player a("Human", id);
        a.setColor(color[i]);
		players.push_back(std::make_unique<Player>(a));
		id++;
	}
	for (int i = 0; i < numberBots; i++) {
		Bot a("Bot", id);
        a.setColor(color[i + numberPlayers]);
		players.push_back(std::make_unique<Bot>(a));
		id++;
	}

    mapMonopoly = fieldCreation();


}

AbstractPlayer* Monopoly::getPlayer(int i) {
    return players.at(i).get();
}

int Monopoly::getNumberAllPlayers()
{
    return numberAllPlayers;
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
    //проверить makeTurn
    int tmpField = players[currentPlayer]->makeTurn();
    players[currentPlayer]->changePos(currentPlayer ,players[currentPlayer]->getPos());
    //проверить action
    players[currentPlayer] = mapMonopoly[tmpField]->action(std::move(players[currentPlayer]));
    int attempt = 0;

    while (attempt < numberAllPlayers) {
        currentPlayer++;
        currentPlayer %= numberAllPlayers;
        if(players[currentPlayer]->getBankrot() == false) {
            QString str = "The turn goes to the player %1!";
            QMessageBox::information(nullptr, "Info", str.arg(currentPlayer+1));
            break;
        }
        else attempt++;
    }

    if(attempt == numberAllPlayers)
        QMessageBox::information(nullptr, "Info", "The game is over!");


}








//std::vector<std::unique_ptr<AbstractPlayer>> Monopoly::get_players(){
//    return players;
//}
//std::vector<std::unique_ptr<Field>> Monopoly::get_map(){
//    return mapMonopoly;
//}
