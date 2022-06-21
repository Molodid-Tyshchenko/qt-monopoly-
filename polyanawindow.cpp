#include "polyanawindow.h"
#include "ui_polyanawindow.h"

PolyanaWindow::PolyanaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PolyanaWindow)
{
    ui->setupUi(this);
}

PolyanaWindow::PolyanaWindow(QWidget *parent, Monopoly *t_m):
    QDialog(parent),
    ui(new Ui::PolyanaWindow)
{
    ui->setupUi(this);
    m = t_m;
    connect(m->mapMonopoly.at(9).get(), &Field::signal_gift, this, &PolyanaWindow::get_info_polyana);
}

PolyanaWindow::~PolyanaWindow()
{
    delete ui;
}

void PolyanaWindow::get_info_polyana(int id_t)
{
    ui->id->setText(QString::number(id_t));
}
