#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QWidget>

namespace Ui {
class MapWindow;
}

class MapWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = nullptr);
    ~MapWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MapWindow *ui;
};

#endif // MAPWINDOW_H
