#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QWidget>
#include "game/Monopoly.h"
namespace Ui {
class InfoWindow;
}

class InfoWindow : public QWidget
{
    Q_OBJECT

public:
    explicit InfoWindow(QWidget *parent = nullptr);
    InfoWindow (QWidget *parent, Monopoly *t_m);
    ~InfoWindow();
    void openInfo(int i);

private:
    Ui::InfoWindow *ui;
    Monopoly* m;

public slots:
    void fromBasicField(std::string, std::string, int, int, int, int, int, int, int, int, int, int);
};



#endif // INFOWINDOW_H
