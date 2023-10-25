#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
	int n = 3;
	double a[3][3]={4,-1,1,
	4,-8,1,	
	-2,1,5};
	double b[3]={7,-21,15};
	double xn[3];
	double xv[3];
	int contador = 0;
	double tol = 0.00001; // Tolerancia
	
	// Comprobación de diagonal dominante
	for (int i = 0; i < n; i++) {
		double suma = 0;
		for (int j = 0; j < n; j++) {
			if (j != i) {
				suma += fabs(a[i][j]);
			}
		}
		if (fabs(a[i][i]) <= suma) {
			cout << "La matriz no es diagonalmente dominante" << endl;
			if (a[i][i] == 0) {
				cout << "Ceros en la diagonal" << endl;
				exit(1); // Salir con un codigo de error
			}
		}
	}
	
	double e = tol+1;
	
	do{
		for (int i = 0; i < n; i++) {
			double suma = 0;
			for (int j = 0; j < n; j++) {
				if (j != i) {
					suma += a[i][j] * xv[j];
				}
			}
			xn[i] = (b[i] - suma) / a[i][i];
		}
		
		double suma = 0;
		for (int i = 0; i < n; i++) {
			suma += pow(xn[i] - xv[i], 2);
		}
		e = sqrt(suma);
		
		for (int i = 0; i < n; i++) {
			xv[i] = xn[i];
		}
		contador++;
	}while (e > tol);
	for (int i = 0; i < n; i++) {
		cout << "Xn" << i << " = " << xn[i] << endl;
	}
	cout << "Cantidad de iteraciones = " << contador << endl;
	cout << "Error = " << e << endl;
	
	return 0;
}
