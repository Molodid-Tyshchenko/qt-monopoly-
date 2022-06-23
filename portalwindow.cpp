#include "portalwindow.h"
#include "ui_portalwindow.h"

PortalWindow::PortalWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortalWindow)
{
    ui->setupUi(this);
}

PortalWindow::PortalWindow(QWidget *parent, Monopoly *t_m):
    QDialog(parent),
    ui(new Ui::PortalWindow)
{
    ui->setupUi(this);
    m = t_m;

    connect(m->mapMonopoly.at(8).get(), &Field::signal_portal, this, &PortalWindow::get_portal_info);
    connect(m->mapMonopoly.at(24).get(), &Field::signal_portal, this, &PortalWindow::get_portal_info);
    connect(m->mapMonopoly.at(36).get(), &Field::signal_portal, this, &PortalWindow::get_portal_info);
    connect(m->mapMonopoly.at(43).get(), &Field::signal_portal, this, &PortalWindow::get_portal_info);
}


PortalWindow::~PortalWindow()
{
    delete ui;
}

void PortalWindow::get_portal_info(int id_t)
{
    ui->id->setText(QString::number(id_t));
}
