#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete myMapWindow;
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    int play_num = ui->spinBox->value();
    if (play_num > 4) {
        QMessageBox::warning(this, "Warning: Number of active players", "Maximum number of players and bots are four! Please consider it, "
                                                                      "before choosing numbers in slots!");
        return;
    }
    if (play_num < 2) {
        QMessageBox::warning(this, "Warning: Number of active players", "Minimum number of players and bots are two! Please consider it, "
                                                                      "before choosing numbers in slots!");
        return;
    }
    m.menu(play_num,0);
    m.startGame();
    myMapWindow = new MapWindow(nullptr, &m);
    myMapWindow->set_play_num(play_num);
    myMapWindow->show();

    QMessageBox::information(nullptr, "Info", "Player 1 can start the game!");

}


void MainWindow::on_pushButton_3_clicked()
{
    exit(0);
}

