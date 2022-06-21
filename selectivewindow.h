#ifndef SELECTIVEWINDOW_H
#define SELECTIVEWINDOW_H

#include "game/Monopoly.h"
#include <QDialog>

namespace Ui {
class SelectiveWindow;
}

class SelectiveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SelectiveWindow(QWidget *parent = nullptr);
    SelectiveWindow(QWidget *parent, Monopoly *t_m);
    ~SelectiveWindow();
public slots:
    void get_win_info(int id_t, int bought_t, std::string group_t, int cost_t, int tax_t, int amount_t);

private:
    Ui::SelectiveWindow *ui;
    Monopoly* m;
};

#endif // SELECTIVEWINDOW_H
