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

    connect(ui->bSell, SIGNAL(clicked()), this, SLOT(slotForButtons()));
    connect(ui->bUpgrade, SIGNAL(clicked()), this, SLOT(slotForButtons()));
    connect(ui->bDowngrade, SIGNAL(clicked()), this, SLOT(slotForButtons()));


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



void InfoWindow::fromBasicField(std::string name, std::string type, int currentLevel, int owner, int buy, int upgrade,
                                 int downgrade, int sell, int firstLevel, int secondLevel, int thirdLevel, int fourthLevel,
                                int fifthLevel, int idPlayer, int idField)

{
    if(owner != idPlayer+1) {
        ui->bSell->setEnabled(false);
        ui->bUpgrade->setEnabled(false);
        ui->bDowngrade->setEnabled(false);
    }

    else {
        ui->bSell->setEnabled(true);
        ui->bUpgrade->setEnabled(true);
        ui->bDowngrade->setEnabled(true);
    }

    ui->currentPlayer->setText(QString::number(idPlayer+1));
    ui->currentField->setText(QString::number(idField));

    ui->name->setText(QString::fromStdString(name));
    ui->type->setText(QString::fromStdString(type));
    ui->currentLevel->setText(QString::number(currentLevel));
    ui->owner->setText(QString::number(owner));
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

void InfoWindow::slotForButtons()
{

    int idField = ui->currentField->text().toInt();
    int idPlayer = ui->currentPlayer->text().toInt() - 1;

    QPushButton* button = (QPushButton*) QObject::sender();
    QString buttonText = button->text();

    std::string str = buttonText.toStdString();

    m->mapMonopoly[idField]->pressToButton(m->players[idPlayer], str);



}
