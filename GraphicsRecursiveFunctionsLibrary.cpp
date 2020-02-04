#include "GraphicsRecursiveFunctionsLibrary.h"

void drawPlanetSystem(HDC hdc, int x, int y, int r, int n, int sat_count)
{
	if (n < 1) {
		return;
	}

	Ellipse(hdc, x - r, y - r, x + r, y + r);

	double r_orbit = (3.0 / 2.0 * r) + r;
	double angle = M_PI * 2.0 / sat_count;

	for (int i = 0; i < sat_count; i++) {
		double a = i * angle;
		int x1 = x + r_orbit * cos(a);
		int y1 = y + r_orbit * sin(a);
		drawPlanetSystem(hdc, x1, y1, (r / 2.0), n - 1, sat_count);
	}
}
