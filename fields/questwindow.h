#ifndef QUESTWINDOW_H
#define QUESTWINDOW_H

#include <QDialog>

namespace Ui {
class QuestWindow;
}

class QuestWindow : public QDialog
{
    Q_OBJECT

public:
    explicit QuestWindow(QWidget *parent = nullptr);
    ~QuestWindow();

private:
    Ui::QuestWindow *ui;
};

#endif // QUESTWINDOW_H
