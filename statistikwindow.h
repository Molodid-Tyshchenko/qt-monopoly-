#ifndef STATISTIKWINDOW_H
#define STATISTIKWINDOW_H

#include "game/Monopoly.h"
#include <QDialog>

namespace Ui {
class StatistikWindow;
}

class StatistikWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StatistikWindow(QWidget *parent = nullptr);
    StatistikWindow(QWidget *parent, Monopoly*);
    ~StatistikWindow();
public slots:
    void show_stat(std::vector <int>);

private:
    Ui::StatistikWindow *ui;
    Monopoly* m;
    std::vector<QLabel*> stat_buffer;
};

#endif // STATISTIKWINDOW_H
