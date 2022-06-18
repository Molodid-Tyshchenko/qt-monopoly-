#include "mapwindow.h"
#include "ui_mapwindow.h"

#include <iostream>

MapWindow::MapWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapWindow)
{
    ui->setupUi(this);

}

MapWindow::~MapWindow()
{
    delete ui;
}

void MapWindow::on_pushButton_2_clicked()
{
    std::cout << ui->pushButton_2->geometry().x();
}

