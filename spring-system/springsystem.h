#pragma once
#include "RungeKutta.h"

class springsys :
	public RungeKutta
{
private:
	double k1, k2, k3, k4;
	double m, M;
	double w, h;
	double mu;

public:
	springsys(double m, double M, double k1, double k2, double k3, double k4, double mu, double x0, double y0, double w, double h);
	~springsys();

	double get_x() { return Y[0]; }
	double get_y() { return Y[1]; }
	double get_X() { return Y[2]; }
	double get_Y() { return Y[3]; }

	double Fup(double k, double dx) { return k * dx; }
	double Ftr(double mu, double m, double max);

	// ������������ ����� RungeKutta
	virtual std::vector<double> F(double t, std::vector<double>& Y) override;
};

