#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	double xp=0; 
	int n=4;
	double suma = 0;
	double a[4][4]={0}, b[4]={0}, x[4]={2.0,3.0,4.0,5.0}, y[4]={1.0,0.7,-0.2,-1.0};
	//LLenar la matriz a y el arreglo b
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=pow(x[i],j);
		}
		b[i]=y[i];
	}
	// Implementar la eliminaci�n gaussiana para resolver el sistema de ecuaciones.
	for (int i = 0; i < n; i++) {
		// Pivoteo parcial: buscar el m�ximo elemento en la columna i y cambiar filas
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
		
		// Eliminaci�n gaussiana
		for (int j = i + 1; j < n; j++) {
			double factor = a[j][i] / a[i][i];
			for (int k = i; k < n; k++) {
				a[j][k] -= factor * a[i][k];
			}
			b[j] -= factor * b[i];
		}
	}
	// Resolver el sistema de ecuaciones con sustituci�n hacia atr�s.
	double coeficientes[4];
	for (int i = n - 1; i >= 0; i--) {
		coeficientes[i] = b[i];
		for (int j = i + 1; j < n; j++) {
			coeficientes[i] -= a[i][j] * coeficientes[j];
		}
		coeficientes[i] /= a[i][i];
	}
	// Calcular los coeficientes del polinomio y evaluar el polinomio en xp.
	double resultado = 0;
	for (int i = 0; i < n; i++) {
		resultado += coeficientes[i] * pow(xp, i);
	}
	
	cout << "El valor interpolado es: " << resultado << endl;
	
	return 0;
}

