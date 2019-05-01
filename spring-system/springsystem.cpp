#include "springsystem.h"



springsys::springsys(double m, double M, double k1, double k2, double k3, double k4, double mu, double x0, double y0, double w, double h) : RungeKutta(8)
{
	this->k1 = k1;
	this->k2 = k2;
	this->k3 = k3;
	this->k4 = k4;

	this->m = m;
	this->M = M;

	this->w = w;
	this->h = h;

	this->mu = mu;

	std::vector<double> Y0(8,0);
	Y0[0] = x0;
	Y0[1] = y0;

	SetInit(0, Y0);
}


springsys::~springsys()
{
}

double springsys::Ftr(double mu, double m, double max)
{
	double F = mu * m * 9.81;
	max = abs(max);
	if (F > max) return -max;
	return -F;
}

std::vector<double> springsys::F(double t, std::vector<double>& Y)
{
	FY[0] = Y[4]; // x' = Vx
	FY[1] = Y[5]; // y' = Vy
	FY[2] = Y[6]; // X' = VX
	FY[3] = Y[7]; // Y' = VY

	// Длины пружин
	double l1 = sqrt(pow(Y[0] - Y[2], 2) + pow(Y[1] - Y[3] - h, 2));
	double l2 = sqrt(pow(Y[0] - Y[2] - w, 2) + pow(Y[1] - Y[3], 2));
	double l3 = sqrt(pow(Y[0] - Y[2], 2) + pow(Y[1] - Y[3] + h, 2));
	double l4 = sqrt(pow(Y[0] - Y[2] + w, 2) + pow(Y[1] - Y[3], 2));

	// Удлинения пружин
	double d1 = l1 - w;
	double d2 = l2 - h;
	double d3 = w - l3;
	double d4 = h - l4;

	// Силы упругости, действующие вдоль осей x и y
	double Fx = Y[0] * (d1 * k1 / l1) + (w - Y[0]) * (d2 * k2 / l2) + Y[0] * (d3 * k3 / l3) + (w - Y[0]) * (d4 * k4 / l4);
	double Fy = (h - Y[1]) * (d1 * k1 / l1) + Y[1] * (d2 * k2 / l2) + (h - Y[1]) * (d3 * k3 / l3) + Y[1] * (d4 * k4 / l4);

	// Рассчет синуса и косинуса направления скорости для проецирования силы трения
	double vvx = Y[6] / sqrt(Y[6] * Y[6] + Y[7] * Y[7]);
	double vvy = Y[7] / sqrt(Y[6] * Y[6] + Y[7] * Y[7]);
	if ((Y[6] == 0) || (Y[7] == 0)) {
		vvx = 0; 
		vvy = 0;
	}
	
	// Рассчет сил трения
	double Ftr_x = Ftr(mu, m + M, Fx) * vvx;
	double Ftr_y = Ftr(mu, m + M, Fy) * vvy;

	FY[6] = (-Fx + Ftr_x) / (M); // VX' = -Fупругости_x + Fтрения_x  / M
	FY[7] = (-Fy + Ftr_y) / (M); // VY' = -Fупругости_y + Fтрения_y  / M

	FY[4] = Fx / m; // Vx' = Fупругости_x / m
	FY[5] = Fy / m; // Vy' = Fупругости_y / m
	

	return FY;
}
