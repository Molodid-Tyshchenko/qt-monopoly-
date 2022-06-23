#include "myselectwin.h"
#include "ui_myselectwin.h"

mySelectWin::mySelectWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mySelectWin)
{
    ui->setupUi(this);
}

mySelectWin::~mySelectWin()
{
    delete ui;
}
