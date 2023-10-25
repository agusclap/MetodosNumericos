#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función para ajustar la función exponencial f(x) = a + bx + ce^x
void ajustarFuncionExponencial(vector<double>& x, vector<double>& y, double& a, double& b, double& c) {
	int n = x.size();
	
	double sum_x = 0.0;
	double sum_y = 0.0;
	double sum_x2 = 0.0;
	double sum_xy = 0.0;
	double sum_ex = 0.0;
	double sum_ey = 0.0;
	double sum_ex2 = 0.0;
	double sum_ey2 = 0.0;
	double sum_eyex = 0.0;
	
	for (int i = 0; i < n; ++i) {
		double xi = x[i];
		double yi = y[i];
		double exi = exp(xi);
		
		sum_x += xi;
		sum_y += yi;
		sum_x2 += xi * xi;
		sum_xy += xi * yi;
		sum_ex += exi;
		sum_ey += yi;
		sum_ex2 += exi * exi;
		sum_ey2 += yi * yi;
		sum_eyex += yi * exi;
	}
	
	// Construir el sistema de ecuaciones lineales
	// Ecuación 1: a * n + b * sum_x + c * sum_ex = sum_y
	// Ecuación 2: a * sum_x + b * sum_x2 + c * sum_ex2 = sum_xy
	// Ecuación 3: a * sum_ex + b * sum_ex2 + c * sum_ex2 = sum_eyex
	
	// Coeficientes del sistema
	double A[3][3] = {
		{static_cast<double>(n), sum_x, sum_ex},
	{sum_x, sum_x2, sum_ex2},
		{sum_ex, sum_ex2, sum_ex2}
	};
	
	// Lados derechos del sistema
	double B[3] = {sum_y, sum_xy, sum_eyex};
	
	// Resolver el sistema de ecuaciones lineales (Ax = B)
	double detA = A[0][0] * (A[1][1] * A[2][2] - A[2][1] * A[1][2])
		- A[0][1] * (A[1][0] * A[2][2] - A[2][0] * A[1][2])
			+ A[0][2] * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);
			
			double detAa = B[0] * (A[1][1] * A[2][2] - A[2][1] * A[1][2])
				- B[1] * (A[0][1] * A[2][2] - A[2][1] * A[0][2])
				+ B[2] * (A[0][1] * A[1][2] - A[1][1] * A[0][2]);
			
			double detAb = A[0][0] * (B[1] * A[2][2] - A[2][1] * B[2])
				- B[0] * (A[1][0] * A[2][2] - A[2][0] * A[1][2])
				+ A[0][2] * (A[1][0] * B[2] - B[1] * A[2][0]);
				
				double detAc = A[0][0] * (A[1][1] * B[2] - B[1] * A[2][1])
					- A[0][1] * (A[1][0] * B[2] - B[1] * A[2][0])
						+ B[0] * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);
					
					a = detAa / detA;
					b = detAb / detA;
					c = detAc / detA;
}

int main() {
	int numDatos;
	cout << "Ingrese el numero de datos: ";
	cin >> numDatos;
	
	vector<double> x(numDatos);
	vector<double> y(numDatos);
	
	cout << "Ingrese los datos (x, y):" << endl;
	for (int i = 0; i < numDatos; ++i) {
		cin >> x[i] >> y[i];
	}
	
	double a, b, c;
	ajustarFuncionExponencial(x, y, a, b, c);
	
	cout << "Los coeficientes de la función exponencial son:" << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	
	return 0;
}
