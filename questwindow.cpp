#include "questwindow.h"
#include "ui_questwindow.h"

QuestWindow::QuestWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestWindow)
{
    ui->setupUi(this);
}

QuestWindow::QuestWindow(QWidget *parent, Monopoly *t_m):
    QDialog(parent),
    ui(new Ui::QuestWindow)
{
    ui->setupUi(this);
    m=t_m;

    connect(m->mapMonopoly.at(4).get(), &Field::signal_question, this, &QuestWindow::get_info_quest);
    connect(m->mapMonopoly.at(13).get(), &Field::signal_question, this, &QuestWindow::get_info_quest);
    connect(m->mapMonopoly.at(29).get(), &Field::signal_question, this, &QuestWindow::get_info_quest);
    connect(m->mapMonopoly.at(39).get(), &Field::signal_question, this, &QuestWindow::get_info_quest);
}

QuestWindow::~QuestWindow()
{
    delete ui;
}

void QuestWindow::get_info_quest(int id_t)
{
    ui->id->setText(QString::number(id_t));
}
