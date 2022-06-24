#include <iostream>
#include <QWidget>
#include <vector>
#include "../players/AbstractPlayer.h"

class Statistik : public QWidget {
    Q_OBJECT
public:
	Statistik(int pl_count);
	void info();
	void update_pt(int pl_id, int points);

private:
	std::vector <int> pl_points;

signals:
    void signal_stat(std::vector <int>);
};
