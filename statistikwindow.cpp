#include "statistikwindow.h"
#include "ui_statistikwindow.h"

StatistikWindow::StatistikWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatistikWindow)
{
    ui->setupUi(this);
}

StatistikWindow::StatistikWindow(QWidget *parent, Monopoly* m_t) :
    QDialog(parent),
    ui(new Ui::StatistikWindow)
{
    ui->setupUi(this);
    m = m_t;

    stat_buffer.push_back(ui->score1);
    stat_buffer.push_back(ui->score2);
    stat_buffer.push_back(ui->score3);
    stat_buffer.push_back(ui->score4);

    connect(m->stats, &Statistik::signal_stat, this, &StatistikWindow::show_stat);
}

StatistikWindow::~StatistikWindow()
{
    delete ui;
}

void StatistikWindow::show_stat(std::vector<int> scores)
{
    for (int i = 0; i <  scores.size(); i++)
        stat_buffer.at(i)->setText(QString::number(scores.at(i)));
}
