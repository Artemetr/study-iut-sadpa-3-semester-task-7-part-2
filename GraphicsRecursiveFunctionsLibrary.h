#pragma once
#include "framework.h"
#define _USE_MATH_DEFINES
#include <math.h>

void drawPlanetSystem(HDC hdc, int x, int y, int r, int n, int sat_count, double k_orbit, double k_sat);

void drawTriangle(HDC hdc, int a[], int b[], int c[]);

void drawRecursiveTriangle(HDC hdc, int a[], int b[], int c[], int n);