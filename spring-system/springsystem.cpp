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

std::vector<double> springsys::get_spring_begin(int num)
{
	std::vector<double> coords(2);

	switch (num)
	{
	case 0:
		coords[0] = Y[2];
		coords[1] = Y[3] + h;
		break;
	case 1:
		coords[0] = Y[2] + w;
		coords[1] = Y[3];
		break;
	case 2:
		coords[0] = Y[2];
		coords[1] = Y[3] - h;
		break;
	case 3:
		coords[0] = Y[2] - w;
		coords[1] = Y[3];
		break;
	default:
		break;
	}

	return coords;
}

std::vector<double> springsys::F(double t, std::vector<double>& Y)
{
	FY[0] = Y[4]; // x' = Vx
	FY[1] = Y[5]; // y' = Vy
	FY[2] = Y[6]; // X' = VX
	FY[3] = Y[7]; // Y' = VY

	// Длины пружин
	/*double l1 = sqrt(pow(Y[0] - Y[2], 2) + pow(Y[1] - Y[3] - h, 2));
	double l2 = sqrt(pow(Y[0] - Y[2] - w, 2) + pow(Y[1] - Y[3], 2));
	double l3 = sqrt(pow(Y[0] - Y[2], 2) + pow(Y[1] - Y[3] + h, 2));
	double l4 = sqrt(pow(Y[0] - Y[2] + w, 2) + pow(Y[1] - Y[3], 2));*/

	double l1 = sqrt(pow(Y[0] - get_spring_begin(0)[0], 2) + pow(Y[1] - get_spring_begin(0)[1], 2));
	double l2 = sqrt(pow(Y[0] - get_spring_begin(1)[0], 2) + pow(Y[1] - get_spring_begin(1)[1], 2));
	double l3 = sqrt(pow(Y[0] - get_spring_begin(2)[0], 2) + pow(Y[1] - get_spring_begin(2)[1], 2));
	double l4 = sqrt(pow(Y[0] - get_spring_begin(3)[0], 2) + pow(Y[1] - get_spring_begin(3)[1], 2));


	// Удлинения пружин
	double d1 = l1 - w;
	double d2 = l2 - h;
	double d3 = w - l3;
	double d4 = h - l4;

	// Силы упругости, действующие вдоль осей x и y
	double F1x = k1 * (Y[0] - Y[2]) * ((h) / sqrt(pow(Y[0] - Y[2], 2) + pow(Y[3] + h - Y[1], 2)) - 1);
	double F2x = -k2 * (Y[2] - Y[0] + w) * ((w) / sqrt(pow(Y[2] - Y[0] + w, 2) + pow(Y[1] - Y[3], 2)));
	double F3x = -k3 * (Y[0] - Y[2]) * (1 - (h) / sqrt(pow(Y[0] - Y[2], 2) + pow(Y[1] + h - Y[3], 2)));
	double F4x = -k4 * (Y[2] - Y[0] + w) * (1 - (w) / sqrt(pow(Y[0] - Y[2] + w, 2) + pow(Y[1] - Y[3], 2)));

	double F1y = -k1 * (Y[3] - Y[1] + h) * ((h) / sqrt(pow(Y[0] - Y[2], 2) + pow(Y[3] + h - Y[1], 2)) - 1);
	double F2y = k2 * (Y[1] - Y[3]) * ((w) / sqrt(pow(Y[2] - Y[0] + w, 2) + pow(Y[1] - Y[3], 2)));
	double F3y = -k3 * (Y[1] - Y[3] + h) * (1 - (h) / sqrt(pow(Y[0] - Y[2], 2) + pow(Y[1] + h - Y[3], 2)));
	double F4y = -k4 * (Y[1] - Y[3]) * (1 - (w) / sqrt(pow(Y[0] - Y[2] + w, 2) + pow(Y[1] - Y[3], 2)));

	double Fx = F1x + F2x + F3x + F4x;
	double Fy = F1y + F2y + F3y + F4y;

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
