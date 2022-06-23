#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include "ui_mapwindow.h"
#include "game/Monopoly.h"
#include <QWidget>
#include "infowindow.h"
#include "selectivewindow.h"
#include "ui_selectivewindow.h"
#include "questwindow.h"
#include "ui_questwindow.h"
#include "game/Monopoly.h"
#include "vadimwindow.h"
#include "ui_vadimwindow.h"
#include "ui_giftwindow.h"
#include "giftwindow.h"
#include "portalwindow.h"
#include "ui_portalwindow.h"
#include "polyanawindow.h"
#include "ui_polyanawindow.h"

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
    SelectiveWindow *mySelecWin;
    VadimWindow *myVadimWin;
    GiftWindow *myGiftWin;
    PolyanaWindow *myPolyanaWin;
    QuestWindow *myQWin;
    PortalWindow *myPortalWin;

    std::vector<QPushButton*> map_storage;

    Monopoly* m;
    int mPlayers;

public:
    explicit MapWindow(QWidget *parent = nullptr);
    MapWindow(QWidget *parent, Monopoly* t_m);
    void create_field();
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





    void on_bField14_clicked();

    void on_bField19_clicked();

    void on_bField37_clicked();

    void on_bField4_clicked();

    void on_bField13_clicked();

    void on_bField29_clicked();

    void on_bField39_clicked();

    void on_bField18_clicked();

    void on_bField8_clicked();

    void on_bField24_clicked();

    void on_bField36_clicked();

    void on_bField43_clicked();

    void on_bField38_clicked();

    void on_bField9_clicked();



public slots:
    void diceValue(QString, QString);
    void changeColor(int, int);
    void update_pos(int,int);
//    void infoBasicField();
};

#endif // MAPWINDOW_H
