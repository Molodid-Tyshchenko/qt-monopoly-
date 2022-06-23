#include "questwindow.h"
#include "ui_questwindow.h"

QuestWindow::QuestWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestWindow)
{
    ui->setupUi(this);
}

QuestWindow::~QuestWindow()
{
    delete ui;
}
