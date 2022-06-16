#include "game/Test.h"
#include "game/Monopoly.h"

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]){
    
    QApplication a(argc, argv);
    MainWindow w;

    Monopoly m; // the game
    m.menu();
    m.startGame();


    w.show();

//      Test t;     // testing the program
//      t.test5();


    return a.exec();

  //  Test t;     // testing the program
  //  t.tests();

  //  Monopoly m; // the game
  //  m.menu();
  //  m.startGame();
  //  m.updateGame();

  //  return 0;
}
