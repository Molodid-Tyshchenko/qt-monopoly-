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

void SelectiveWindow::get_win_info(std::string name, std::string type, int currentLevel, int owner,
                                   int buy, int sell, int firstLevel, int secondLevel, int thirdLevel, int idPlayer, int idField)
{
    if(owner != idPlayer+1)
        ui->bSell->setEnabled(false);

    else
        ui->bSell->setEnabled(true);

    ui->currentPlayer->setText(QString::number(idPlayer+1));
    ui->currentField->setText(QString::number(idField));

    ui->name->setText(QString::fromStdString(name));
    ui->type->setText(QString::fromStdString(type));
    ui->currentLevel->setText(QString::number(currentLevel));
    ui->owner->setText(QString::number(owner));

    ui->buy->setText(QString::number(buy));

    ui->sell->setText(QString::number(sell));
    ui->firstLevel->setText(QString::number(firstLevel));
    ui->secondLevel->setText(QString::number(secondLevel));
    ui->thirdLevel->setText(QString::number(thirdLevel));


}

void SelectiveWindow::on_bSell_clicked()
{
    int idField = ui->currentField->text().toInt();
    int idPlayer = ui->currentPlayer->text().toInt() - 1;

    //std::cout << idPlayer << std::endl;
    m->mapMonopoly[idField]->pressToButton(m->players[idPlayer], "qwe");
}

