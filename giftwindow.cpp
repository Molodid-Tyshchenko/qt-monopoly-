#include "giftwindow.h"
#include "ui_giftwindow.h"

GiftWindow::GiftWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GiftWindow)
{
    ui->setupUi(this);
}

GiftWindow::GiftWindow(QWidget *parent, Monopoly *t_m):
    QDialog(parent),
    ui(new Ui::GiftWindow)
{
    ui->setupUi(this);
    m = t_m;

    connect(m->mapMonopoly.at(38).get(), &Field::signal_gift, this, &GiftWindow::get_info_gift);
}

GiftWindow::~GiftWindow()
{
    delete ui;
}

void GiftWindow::get_info_gift(int id_t)
{
    ui->id->setText(QString::number(id_t));
}

