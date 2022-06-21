#ifndef VADIMWINDOW_H
#define VADIMWINDOW_H

#include <QDialog>
#include "game/Monopoly.h"

namespace Ui {
class VadimWindow;
}

class VadimWindow : public QDialog
{
    Q_OBJECT

public:
    explicit VadimWindow(QWidget *parent = nullptr);
    VadimWindow(QWidget *parent, Monopoly *t_m);
    ~VadimWindow();
public slots:
    void get_info_vadim(int id_t);

private:
    Ui::VadimWindow *ui;
    Monopoly *m;
};

#endif // VADIMWINDOW_H
