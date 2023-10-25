#include <iostream>
#include <cmath>

using namespace std;

// Definicion de funciones
float funcionPuntoFijo(float x);
float valorAbsoluto(float x);
float aproximacionDerivada(float x);

// Funcion principal para el metodo de punto fijo
void metodoPuntoFijo(float valorInicial, float tolerancia);

int main() {
    float tolerancia, valorInicial;
    int nRaices, contadorRaices = 1;
    tolerancia = 0.0001;
    
    cout << "Ingrese el numero de raices reales que tiene la funcion: ";
    cin >> nRaices;
    
    while (contadorRaices <= nRaices) {
        if (contadorRaices > 1) {
            cout << "\nSiguiente raiz.\n";
        }
        cout << "Ingrese el valor inicial de x para la raiz #" << contadorRaices << ": ";
        cin >> valorInicial;
        cout << "Ingrese la tolerancia deseada: ";
        cin >> tolerancia;
        metodoPuntoFijo(valorInicial, tolerancia);
        contadorRaices++;
    }
}

// Implementacion del metodo de punto fijo
void metodoPuntoFijo(float valorInicial, float tolerancia) {
    float error = 1 , raizAproximada, diferencia;
    int iteracion = 1;
    
    while (error > tolerancia) {
        if (iteracion == 1000 || valorAbsoluto(aproximacionDerivada(valorInicial)) >= 1) {
            cout << "La funcion no converge." << endl;
            exit(0);
        } else {
            raizAproximada = funcionPuntoFijo(valorInicial);
            diferencia = raizAproximada - valorInicial;
            error = valorAbsoluto(diferencia);
            valorInicial = raizAproximada;
            iteracion++;
        }
    } 
    
    cout << "La raiz encontrada es: " << raizAproximada << endl;
}

// Definicion de la funcion de punto fijo g(x)
float funcionPuntoFijo(float x) {
    return pow(x,2)+x-4;
}

// Calculo del valor absoluto
float valorAbsoluto(float x) {
    if (x < 0) {
        x = -x;
    }
    return x;
}

// Aproximacion de la derivada de la funcion de punto fijo g(x)
float aproximacionDerivada(float x) {
    double h = 0.01;
    return (funcionPuntoFijo(x + h) - funcionPuntoFijo(x - h)) / (2 * h);
}