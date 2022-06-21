#include "game/Test.h"
#include "game/Monopoly.h"

#include "mainwindow.h"
#include "mapwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[]){
    
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    MapWindow map(&w);
//    map.show();
    QFile file("C:/Users/tysya/Documents/GitHub/qt-monopoly-/style.qss");
    file.open(QIODevice::ReadOnly);
    QString styleSheet { QLatin1String(file.readAll()) };
    a.setStyleSheet(styleSheet);
    return a.exec();

  //  Test t;     // testing the program
  //  t.tests();

  //  Monopoly m; // the game
  //  m.menu();
  //  m.startGame();
  //  m.updateGame();

  //  return 0;
}
