#include "Monopoly.h"
#include "QMessageBox"


void Monopoly::menu(int players_t) {
    numberPlayers = players_t;
    numberAllPlayers = numberPlayers;
}

void Monopoly::startGame() {

    int id = 1;
    for (int i = 0; i < numberPlayers; i++) {
        Player a("Human", id);
        players.push_back(std::make_shared<Player>(a));
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


void Monopoly::updateGame() {

    if(gameOver) {
        QMessageBox::information(nullptr, "Info", "The game is over!");
        return;
    }


    if(players[currentPlayer]->getBankrot() == -1) {
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

