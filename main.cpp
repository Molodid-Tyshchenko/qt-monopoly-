#include "game/Test.h"
#include "game/Monopoly.h"

#include "mainwindow.h"
#include "mapwindow.h"

#include <QApplication>

int main(int argc, char *argv[]){
    
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    MapWindow map(&w);
//    map.show();
    return a.exec();

  //  Test t;     // testing the program
  //  t.tests();

  //  Monopoly m; // the game
  //  m.menu();
  //  m.startGame();
  //  m.updateGame();

  //  return 0;
}
