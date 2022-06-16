#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("background-color: yellow");


    myMapWindow = new MapWindow();

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(push_button0()));

}

MainWindow::~MainWindow()
{
    delete myMapWindow;
    delete ui;
}


void MainWindow::push_button0()
{

    QPushButton *button = (QPushButton *)sender();
    button->setStyleSheet("background-color: blue");
    int id = (button->text()).toInt();
    myMapWindow->push_button0(id);
    myMapWindow->show();



}

