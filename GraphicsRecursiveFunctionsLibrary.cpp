#include "GraphicsRecursiveFunctionsLibrary.h"

void drawPlanetSystem(HDC hdc, int x, int y, int r, int n, int sat_count, double k_orbit, double k_sat)
{
	if (n < 1) {
		return;
	}

	Ellipse(hdc, x - r, y - r, x + r, y + r);
	double r_orbit = k_orbit * r;
	double angle = M_PI * 2.0 / sat_count;

	r = floor(k_sat * r);
	for (int i = 0; i < sat_count; i++)
	{
		double a = i * angle;
		int x1 = x + r_orbit * cos(a);
		int y1 = y + r_orbit * sin(a);
		drawPlanetSystem(hdc, x1, y1, r, n - 1, sat_count, k_orbit, k_sat);
	}
}

void drawLine(HDC hdc, int from[], int to[]) {
	enum { X, Y };

	MoveToEx(hdc, from[X], from[Y], (LPPOINT)NULL);
	LineTo(hdc, to[X], to[Y]);
}

void drawTriangle(HDC hdc, int a[], int b[], int c[])
{
	enum { X, Y };

	drawLine(hdc, a, b);
	drawLine(hdc, b, c);
	drawLine(hdc, c, a);
}

void drawRecursiveTriangle(HDC hdc, int a[], int b[], int c[], int n)
{
	drawTriangle(hdc, a, b, c);

	if (n < 0) {
		return;
	}

	enum {X, Y};
	
	int p[2] = { (b[X] + c[X]) / 2, (b[Y] + c[Y]) / 2 };
	int q[2] = { (a[X] + c[X]) / 2, (a[Y] + c[Y]) / 2 };
	int r[2] = { (b[X] + a[X]) / 2, (b[Y] + a[Y]) / 2 };

	drawRecursiveTriangle(hdc, a, r, q, n - 1);
	drawRecursiveTriangle(hdc, b, p, r, n - 1);
	drawRecursiveTriangle(hdc, c, q, p, n - 1);
}
