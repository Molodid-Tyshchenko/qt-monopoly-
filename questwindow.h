#ifndef QUESTWINDOW_H
#define QUESTWINDOW_H

#include <QDialog>
#include "game/Monopoly.h"

namespace Ui {
class QuestWindow;
}

class QuestWindow : public QDialog
{
    Q_OBJECT

public:
    explicit QuestWindow(QWidget *parent = nullptr);
    QuestWindow(QWidget *parent, Monopoly* t_m);
    ~QuestWindow();
public slots:
    void get_info_quest(int id_t);

private:
    Ui::QuestWindow *ui;
    Monopoly *m;
};

#endif // QUESTWINDOW_H
