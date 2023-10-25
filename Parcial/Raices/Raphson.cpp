#include <iostream>
#include <cmath>

using namespace std;

double funcionRapshon(double);//MODIFICAR EN FUNCION DE CADA FUNCION
double derivadaFuncion(double);//MODIFICAR EN FUNCION DE CADA FUNCION
void metodoRapshon(double, double);

int main() {
	double valorInicial, tolerancia;
	
	cout << "Ingrese el valor inicial:" << endl;
	cin >> valorInicial;
	cout << "Ingrese la tolerancia deseada:" << endl;
	cin >> tolerancia;
	
	metodoRapshon(valorInicial, tolerancia);
	
	return 0;
}

double funcionRapshon(double f) {
	return 2*f + log(f) - sin(3*f);
}

double derivadaFuncion(double f) { //HAY QUE CAMBIAR EN LUGAR DE LA FUNCION ORIGINAL
	double h = 0.01;
	return (3* funcionRapshon(f) - 4* funcionRapshon(f-h) + funcionRapshon(f-2*h))/(2*h);
}

void metodoRapshon(double valorInicial, double tolerancia) {
	double error;
	int contador = 0;
	double raiz = valorInicial;
	
	do {
		raiz = valorInicial - (funcionRapshon(valorInicial) / derivadaFuncion(valorInicial));
		error = abs((raiz - valorInicial) / raiz);
		valorInicial = raiz;
		contador++;
	} while (error > tolerancia);
	
	cout << "La raiz es: " << raiz << endl;
	cout << "El error es: " << error << endl;
	cout << "Iteraciones: " << contador << endl;
}
