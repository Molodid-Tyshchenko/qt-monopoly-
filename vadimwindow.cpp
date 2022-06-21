#include "vadimwindow.h"
#include "ui_vadimwindow.h"

VadimWindow::VadimWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VadimWindow)
{
    ui->setupUi(this);
}

VadimWindow::VadimWindow(QWidget *parent, Monopoly *t_m):
    QDialog(parent),
    ui(new Ui::VadimWindow)
{
    ui->setupUi(this);
    m = t_m;

    connect(m->mapMonopoly.at(18).get(), &Field::signal_vadim, this, &VadimWindow::get_info_vadim);
}


VadimWindow::~VadimWindow()
{
    delete ui;
}

void VadimWindow::get_info_vadim(int id_t)
{
    ui->id->setText(QString::number(id_t));
}
