#include "game/Test.h"
#include "game/Monopoly.h"

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]){
    
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

  //  Test t;     // testing the program
  //  t.tests();

  //  Monopoly m; // the game
  //  m.menu();
  //  m.startGame();
  //  m.updateGame();

  //  return 0;
}
