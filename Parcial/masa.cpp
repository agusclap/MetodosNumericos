#include <iostream>
#include <cmath>

using namespace std;

double f(double m);

int main() {
    double a, b, c, tolerancia, error = 1, contador = 0;
    cout << "Ingrese a:" << endl;
    cin >> a;
    cout << "Ingrese b:" << endl;
    cin >> b;
    cout << "Ingrese tolerancia:" << endl;
    cin >> tolerancia;

    if (f(a) * f(b) > 0) {
        cout << "No hay raíz en el intervalo dado." << endl;
        return 1;
    }

    do {
        contador ++;
        c = (a + b) / 2;
        if (f(a) * f(c) > 0) {
            a = c;
        } else if (f(a) * f(c) < 0) {
            b = c;
        } else if (f(a) * f(c) == 0) {
            cout << "La raíz es: " << c << endl;
            return 0;
        }
        error = (b - a) / 2.0;
    } while (error > tolerancia);

    cout << "La raíz aproximada es: " << c << endl;
    cout << "La cantidad de iteraciones es: " << contador << endl;
    return 0;
}

double f(double m) {
    const double g = 9.81;
    const double c = 14.0;
    const double t = 7.0;

    return (g * m / c) * (1 - exp(-c * t / m)) - 35.0;
}
