#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	int n = 4;
	double a[4][4] = {0}, b[4] = {0}, x[4] = {2.0, 3.0, 4.0, 5.0}, y[4] = {1.0, 0.7, -0.2, -1.0};
	string polynomial = ""; // Aquí almacenaremos el polinomio interpolante
	
	// Llenar la matriz a y el arreglo b
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = pow(x[i], j);
		}
		b[i] = y[i];
	}
	
	// Implementar la eliminación gaussiana para resolver el sistema de ecuaciones.
	for (int i = 0; i < n; i++) {
		// Pivoteo parcial: buscar el máximo elemento en la columna i y cambiar filas
		int maxRow = i;
		for (int j = i + 1; j < n; j++) {
			if (abs(a[j][i]) > abs(a[maxRow][i])) {
				maxRow = j;
			}
		}
		// Intercambiar filas
		if (maxRow != i) {
			swap(a[i], a[maxRow]);
			swap(b[i], b[maxRow]);
		}
		
		// Eliminación gaussiana
		for (int j = i + 1; j < n; j++) {
			double factor = a[j][i] / a[i][i];
			for (int k = i; k < n; k++) {
				a[j][k] -= factor * a[i][k];
			}
			b[j] -= factor * b[i];
		}
	}
	
	// Resolver el sistema de ecuaciones con sustitución hacia atrás.
	double coeficientes[4];
	for (int i = n - 1; i >= 0; i--) {
		coeficientes[i] = b[i];
		for (int j = i + 1; j < n; j++) {
			coeficientes[i] -= a[i][j] * coeficientes[j];
		}
		coeficientes[i] /= a[i][i];
	}
	
	// Construir la ecuación del polinomio interpolante
	for (int i = 0; i < n; i++) {
		string term = to_string(coeficientes[i]);
		if (i > 0) {
			term += "x";
			if (i > 1) {
				term += "^" + to_string(i);
			}
			term += " ";
			if (coeficientes[i] >= 0 && i < n - 1) {
				term = "+ " + term;
			}
		}
		polynomial += term;
	}
	
	cout << "La ecuación del polinomio interpolante es: " << polynomial << endl;
	
	return 0;
}
