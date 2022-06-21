#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include "ui_mapwindow.h"
#include "game/Monopoly.h"
#include <QWidget>
#include "infowindow.h"

namespace Ui {
class MapWindow;
}

class MapWindow : public QWidget
{
    Q_OBJECT
private:
    int playebles = 0;
    Ui::MapWindow *ui;
    InfoWindow *myInfoWindow;
    Monopoly* m;
    int mPlayers;

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

    void on_bField1_clicked();
    void on_bField2_clicked();
    void on_bField3_clicked();
    void on_bField5_clicked();
    void on_bField6_clicked();
    void on_bField7_clicked();
    void on_bField10_clicked();
    void on_bField11_clicked();
    void on_bField12_clicked();
    void on_bField15_clicked();
    void on_bField16_clicked();
    void on_bField17_clicked();
    void on_bField20_clicked();
    void on_bField21_clicked();
    void on_bField22_clicked();
    void on_bField23_clicked();
    void on_bField25_clicked();
    void on_bField26_clicked();
    void on_bField27_clicked();
    void on_bField28_clicked();
    void on_bField30_clicked();
    void on_bField31_clicked();
    void on_bField32_clicked();
    void on_bField33_clicked();
    void on_bField34_clicked();
    void on_bField35_clicked();
    void on_bField40_clicked();
    void on_bField41_clicked();
    void on_bField42_clicked();





public slots:
    void diceValue(QString, QString);
//    void infoBasicField();
};

#endif // MAPWINDOW_H
