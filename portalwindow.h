#ifndef PORTALWINDOW_H
#define PORTALWINDOW_H

#include <QDialog>
#include "game/Monopoly.h"

namespace Ui {
class PortalWindow;
}

class PortalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PortalWindow(QWidget *parent = nullptr);
    PortalWindow(QWidget *parent, Monopoly *t_m);
    ~PortalWindow();

   public slots:
    void get_portal_info(int id_t);

private:
    Ui::PortalWindow *ui;
    Monopoly *m;
};

#endif // PORTALWINDOW_H
