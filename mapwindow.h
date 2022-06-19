#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include "ui_mapwindow.h"
#include "game/Monopoly.h"
#include <QWidget>

namespace Ui {
class MapWindow;
}

class MapWindow : public QWidget
{
    Q_OBJECT
private:
    int playebles = 0;
    Ui::MapWindow *ui;
    Monopoly* m;

public:
    explicit MapWindow(QWidget *parent = nullptr);
    MapWindow(QWidget *parent, Monopoly* t_m);
    void set_play_num(int p_t);
    int get_play_num(){
        return playebles;
    }
    ~MapWindow();

private slots:



    void on_bRollDice_clicked();
};

#endif // MAPWINDOW_H
