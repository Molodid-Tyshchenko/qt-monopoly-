#include "game/Test.h"
#include "game/Monopoly.h"

#include "mainwindow.h"
#include "mapwindow.h"

#include <QApplication>
#include <QFile>
#include <QResource>

int main(int argc, char *argv[]){
    
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QResource::registerResource(":/new/prefix3/style.qss");
    QFile qss(":/new/prefix3/style.qss");
    qss.open(QFile::ReadOnly);
    a.setStyleSheet(qss.readAll());
    qss.close();

    return a.exec();

}
