#ifndef POLYANAWINDOW_H
#define POLYANAWINDOW_H

#include <QDialog>
#include "game/Monopoly.h"

namespace Ui {
class PolyanaWindow;
}

class PolyanaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PolyanaWindow(QWidget *parent = nullptr);
    PolyanaWindow(QWidget *parent, Monopoly *t_m);
    ~PolyanaWindow();
public slots:
    void get_info_polyana(int id_t);

private:
    Ui::PolyanaWindow *ui;
    Monopoly *m;
};

#endif // POLYANAWINDOW_H
