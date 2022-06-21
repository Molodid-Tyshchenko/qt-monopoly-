#include "selectivewindow.h"
#include "ui_selectivewindow.h"

SelectiveWindow::SelectiveWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectiveWindow)
{
    ui->setupUi(this);
}

SelectiveWindow::SelectiveWindow(QWidget *parent, Monopoly *t_m):
    QDialog(parent),
    ui(new Ui::SelectiveWindow)
{
    ui->setupUi(this);
    m = t_m;
    connect(m->mapMonopoly.at(14).get(),&Field::signal_selective, this, &SelectiveWindow::get_win_info);
    connect(m->mapMonopoly.at(19).get(),&Field::signal_selective, this, &SelectiveWindow::get_win_info);
    connect(m->mapMonopoly.at(37).get(),&Field::signal_selective, this, &SelectiveWindow::get_win_info);
}


SelectiveWindow::~SelectiveWindow()
{
    delete ui;
}

void SelectiveWindow::get_win_info(int id_t, int bought_t, std::string group_t, int cost_t, int tax_t, int amount_t)
{
    ui->id->setText(QString::number(id_t));
    ui->amount->setText(QString::number(amount_t));
    ui->bought->setText(QString::number(bought_t));
    ui->cost->setText(QString::number(cost_t));
    ui->group->setText(QString::fromUtf8(group_t.c_str()));
    ui->tax->setText(QString::number(tax_t));
}
