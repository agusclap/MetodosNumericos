#include <iostream>
#include <cmath>
#include <iomanip>

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
    return (9,81*f)/(14) * (1-exp((-14/f)*7));
}

double derivadaFuncion(double f) { //HAY QUE CAMBIAR EN LUGAR DE LA FUNCION ORIGINAL
    return 9.81/14 - (9.81/14)*exp(-98/f) + (137.67/pow(f,2)) * exp(-98/f);
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

    cout << "La raiz es: " << setprecision(12) << raiz << endl;
    cout << "El error es: " << error << endl;
    cout << "Iteraciones: " << contador << endl;
}