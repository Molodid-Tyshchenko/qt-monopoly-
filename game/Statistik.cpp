#include "Statistik.h"


Statistik::Statistik(int pl_count) {
	for (int i = 0; i < pl_count; i++)
	pl_points.push_back(0);
}

void Statistik::update_pt(int pl_id, int points) {
	pl_points[pl_id] = points;
}

void Statistik::info() {
    emit signal_stat(pl_points);
}
