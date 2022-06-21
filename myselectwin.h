#ifndef MYSELECTWIN_H
#define MYSELECTWIN_H

#include <QDialog>

namespace Ui {
class mySelectWin;
}

class mySelectWin : public QDialog
{
    Q_OBJECT

public:
    explicit mySelectWin(QWidget *parent = nullptr);
    ~mySelectWin();

private:
    Ui::mySelectWin *ui;
};

#endif // MYSELECTWIN_H
