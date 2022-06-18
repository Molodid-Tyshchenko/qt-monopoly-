#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("background-color: yellow");


    myMapWindow = new MapWindow();

    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(push_button0()));

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
    //myMapWindow->push_button0(id);
    //myMapWindow->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    int play_num = ui->spinBox->value();
    int bot_num = ui->spinBox_2->value();

    if (play_num + bot_num > 4) {
        QMessageBox::warning(this, "Warning: Number of active players", "Maximum number of players and bots are four! Please consider it, "
                                                                      "before choosing numbers in slots!");
        return;
    }
    m.menu(play_num,bot_num);
    m.startGame();
    myMapWindow->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    exit(0);
}

