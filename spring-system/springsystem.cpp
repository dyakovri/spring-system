#include "springsystem.h"



springsys::springsys(double m, double M, double k1, double k2, double k3, double k4, double mu, double x0, double y0) : RungeKutta(8)
{
	this->k1 = k1;
	this->k2 = k2;
	this->k3 = k3;
	this->k4 = k4;

	this->m = m;
	this->M = M;

	this->mu = mu;

	std::vector<double> Y0(8,0);
	Y0[0] = x0;
	Y0[1] = y0;

	SetInit(0, Y0);
}


springsys::~springsys()
{
}

std::vector<double> springsys::F(double t, std::vector<double>& Y)
{
	FY[0] = Y[4]; // x' = Vx
	FY[1] = Y[5]; // y' = Vy
	FY[2] = Y[6]; // X' = VX
	FY[3] = Y[7]; // Y' = VY


	double vvx = Y[6] / sqrt(Y[6] * Y[6] + Y[7] * Y[7]);
	double vvy = Y[7] / sqrt(Y[6] * Y[6] + Y[7] * Y[7]);
	if ((Y[6] == 0) || (Y[7] == 0)) {
		vvx = 0; 
		vvy = 0;
	}

	double Fup_x = Fup(k1+k3, Y[0]);
	double Fup_y = Fup(k2 + k4, Y[1]);
	double Ftr_x = Ftr(mu, m + M, Fup_x) * vvx;
	double Ftr_y = Ftr(mu, m + M, Fup_y) * vvy;

	FY[6] = (Fup_x + Ftr_x) / M;
	FY[7] = (Fup_y + Ftr_y) / M;

	FY[4] = (-Fup_x - M * FY[6]) / m;
	FY[5] = (-Fup_y - M * FY[7]) / m;
	

	return FY;
}
