#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n = 4; // Valor modificable
	int a[4][4];
	int b[4];
	int x[4];
	float factor = 0.0;
	int suma = 0;
	
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
	
	// Método de eliminación Gaussiana
	for (int j = 0; j < n - 1; j++) {
		for (int i = j + 1; i < n; i++) {
			factor = -a[i][j] / a[j][j];
			for (int k = j; k < n; k++) {
				a[i][k] += factor * a[j][k];
			}
			b[i] += factor * b[j];
		}
	}
	
	// Calcular el determinante
	float det = 1.0;
	for (int i = 0; i < n; i++) {
		det *= a[i][i];
	}
	cout<<"Determinante de la matriz: "<<det<<endl;
	
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
