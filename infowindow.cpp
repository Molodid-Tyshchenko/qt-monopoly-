#include "infowindow.h"
#include "ui_infowindow.h"

InfoWindow::InfoWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);
}

InfoWindow::InfoWindow(QWidget *parent, Monopoly *t_m) :
    QWidget(parent),
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);
    m = t_m;



    connect(m->mapMonopoly.at(1).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(2).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(3).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(5).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(6).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(7).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(10).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(11).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(12).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(15).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(16).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(17).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(20).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(21).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(22).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(23).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(25).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(26).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(27).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(28).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(30).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(31).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(32).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(33).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(34).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(35).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(40).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(41).get(), &Field::signal, this, &InfoWindow::fromBasicField);
    connect(m->mapMonopoly.at(42).get(), &Field::signal, this, &InfoWindow::fromBasicField);

}

InfoWindow::~InfoWindow()
{
    delete ui;
}

void InfoWindow::openInfo(int i)
{
//    ui->name->setText(QString::fromStdString(m->mapMonopoly.at(i)->getName()));
//    ui->type->setText(QString::fromStdString(m->mapMonopoly.at(i)->getGroup()));
//    ui->currentLevel->setText(QString::number(m->mapMonopoly.at(i)->getLevel()));
//    //здесь должен быть владелец
//    ui->buy->setText(QString::number(m->mapMonopoly.at(i)->getCost()));
//    ui->upgrade->setText(QString::number(m->mapMonopoly.at(i)->getCostUpgrade()));
//    ui->downgrade->setText(QString::number(m->mapMonopoly.at(i)->getCostDowngrade()));
//    ui->sell->setText(QString::number(m->mapMonopoly.at(i)->getCostSell()));
//    ui->firstLevel->setText(QString::number(m->mapMonopoly.at(i)->getTax1()));
//    ui->secondLevel->setText(QString::number(m->mapMonopoly.at(i)->getTax2()));
//    ui->thirdLevel->setText(QString::number(m->mapMonopoly.at(i)->getTax3()));
//    ui->fourthLevel->setText(QString::number(m->mapMonopoly.at(i)->getTax4()));
//    ui->fifthLevel->setText(QString::number(m->mapMonopoly.at(i)->getTax5()));


}

void InfoWindow::fromBasicField(std::string name, std::string type, int currentLevel, int buy, int upgrade,
                                 int downgrade, int sell, int firstLevel, int secondLevel, int thirdLevel, int fourthLevel, int fifthLevel)

{
    ui->name->setText(QString::fromStdString(name));
    ui->type->setText(QString::fromStdString(type));
    ui->currentLevel->setText(QString::number(currentLevel));
        //здесь должен быть владелец
    ui->buy->setText(QString::number(buy));
    ui->upgrade->setText(QString::number(upgrade));
    ui->downgrade->setText(QString::number(downgrade));
    ui->sell->setText(QString::number(sell));
    ui->firstLevel->setText(QString::number(firstLevel));
    ui->secondLevel->setText(QString::number(secondLevel));
    ui->thirdLevel->setText(QString::number(thirdLevel));
    ui->fourthLevel->setText(QString::number(fourthLevel));
    ui->fifthLevel->setText(QString::number(fifthLevel));

}
