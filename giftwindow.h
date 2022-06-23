#ifndef GIFTWINDOW_H
#define GIFTWINDOW_H

#include "game/Monopoly.h"
#include <QDialog>

namespace Ui {
class GiftWindow;
}

class GiftWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GiftWindow(QWidget *parent = nullptr);
    GiftWindow(QWidget *parent, Monopoly* t_m);
    ~GiftWindow();
public slots:
    void get_info_gift(int id_t);

private:
    Ui::GiftWindow *ui;
    Monopoly *m;
};

#endif // GIFTWINDOW_H
