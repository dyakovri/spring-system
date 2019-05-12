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

double springsys::Fdx(double mu, double m, double max)
{
	double Fd = mu * m * 9.81;
	
	if ((Y[6] != 0) && (Y[7] != 0))
		Fd = Fd * Y[6] / sqrt(Y[6] * Y[6] + Y[7] * Y[7]);
	else 
		Fd = 0;
	
	if (Y[6] == 0) 
		if (Fd > max)
			return -max;
	
	return -Fd;

}


double springsys::Fdy(double mu, double m, double max)
{
	double Fd = mu * m * 9.81;

	if ((Y[6] != 0) && (Y[7] != 0))
		Fd = Fd * Y[7] / sqrt(Y[6] * Y[6] + Y[7] * Y[7]);
	else
		Fd = 0;

	if (Y[7] == 0) 
		if (Fd > max) 
			return -max;

	return -Fd;

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
	double x = Y[0];
	double y = Y[1];

	FY[0] = Y[4]; // x' = Vx
	FY[1] = Y[5]; // y' = Vy
	FY[2] = Y[6]; // X' = VX
	FY[3] = Y[7]; // Y' = VY

	/*double Fd = mu*(M + m)*9.81;
	double Fdx, Fdy;
	if ((Fdx != 0) && (Fdy != 0)) {
		Fdx = Fd * Y[6] / sqrt(Y[6] * Y[6] + Y[7] * Y[7]);
		Fdy = Fd * Y[7] / sqrt(Y[6] * Y[6] + Y[7] * Y[7]);
	}
	else {
		Fdx = 0;
		Fdy = 0;
	}*/

	double F1x = +k1 * x;
	double F2x = -k2 * x;
	double F3x = +k3 * x;
	double F4x = +k4 * x;

	double F1y = -k1 * y;
	double F2y = +k2 * y;
	double F3y = +k3 * y;
	double F4y = +k4 * y;

	FY[6] = (+F1x + F2x + F3x + F4x + Fdx(mu, M + m, +F1x + F2x + F3x + F4x)) / M;		// VX' = sum FMx
	FY[7] = (+F1y + F2y + F3y + F4y + Fdy(mu, M + m, +F1y + F2y + F3y + F4y)) / M;		// VY' = sum FMy

	FY[4] = (-F1x - F2x - F3x - F4x - m * FY[6]) / m;	// Vx' = sum Fmx
	FY[5] = (-F1y - F2y - F3y - F4y - m * FY[7]) / m;	// Vy' = sum Fmy

	return FY;
}
