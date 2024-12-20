#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <tgmath.h>

using namespace std;

class frequency
{
public:
	void getF();
	void getData();
	void gradient();
	void aGradient();
	void bGradient();
	void cGradient();
	void dGradient();
	void gGradient();
	void setK();
	double Error();
	double deriv();
	void setP();

private:
	double f, a, b, c, d, e, g, h, k, l, r;
	double y[9390], p[9390], o[9387];
};

