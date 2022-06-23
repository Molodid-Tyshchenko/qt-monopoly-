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
    void get_win_info(std::string, std::string, int, int, int, int, int, int, int, int, int);


private slots:
    void on_bSell_clicked();

private:
    Ui::SelectiveWindow *ui;
    Monopoly* m;
};

#endif // SELECTIVEWINDOW_H
