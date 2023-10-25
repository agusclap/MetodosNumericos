#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
	int n = 4; // Valor modificable
	double a[4][4];
	double b[4];
	double x[4];
	double factor = 0.0;
	double suma = 0;
	
	// Llenar la matriz 'a' y el arreglo 'b'
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Ingrese el valor de a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
		cout << "Ingrese el valor de b[" << i << "]: ";
		cin >> b[i];
	}
	
	// Imprimir la matriz
	cout << "Matriz:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << "| " << b[i] << endl;
	}
	cout << endl;
	
	// Método de eliminación Gaussiana con pivoteo parcial
	for (int j = 0; j < n - 1; j++) {
		// Encontrar el pivote máximo en la columna
		int max_row = j;
		double max_val = abs(a[j][j]);
		for (int i = j + 1; i < n; i++) {
			if (abs(a[i][j]) > max_val) {
				max_row = i;
				max_val = abs(a[i][j]);
			}
		}
		
		// Intercambiar filas si es necesario
		if (max_row != j) {
			for (int k = 0; k < n; k++) {
				swap(a[j][k], a[max_row][k]);
			}
			swap(b[j], b[max_row]);
		}
		
		// Continuar con la eliminación
		for (int i = j + 1; i < n; i++) {
			factor = -a[i][j] / a[j][j];
			for (int k = j; k < n; k++) {
				a[i][k] += factor * a[j][k];
			}
			b[i] += factor * b[j];
		}
	}
	
	// Calcular el determinante
	double det = 1.0;
	for (int i = 0; i < n; i++) {
		det *= a[i][i];
	}
	cout << "Determinante de la matriz reducida: " << det << endl;
	
	if (det == 0) {
		cout << "Matriz singular" << endl;
		return 0;
	} else {
		x[n - 1] = b[n - 1] / a[n - 1][n - 1];
		for (int i = n - 2; i >= 0; i--) {
			suma = b[i];
			for (int k = i + 1; k < n; k++) {
				suma -= a[i][k] * x[k];
			}
			x[i] = suma / a[i][i];
		}
		
		// Imprimir solución
		cout << "Solucion del sistema de ecuaciones:" << endl;
		for (int i = 0; i < n; i++) {
			cout << "x" << i << " = " << x[i] << "\n";
		}
	}
	
	return 0;
}

