#include <iostream>
using namespace std;

int main (void){
    double C0 = 0, C1 = 0 , C2 = 0, C3 = 0, C4 = 0, C5 = 0,
           X0 = 0, X1 = 0 , X2 = 0, X3 = 0, X4 = 0, X5 = 0;
    double a = 0,b = 0;
    double I = 0;
    int puntos = 0;
    cout<<"Ingrese el limite inferior del intervalo"<<endl;
    cin>>a;
    cout<<"Ingrese el limite superior del intervalo"<<endl;
    cin>>b;
    cout<<"Ingrese la cantidad de puntos que desea usar (WARNING: 2 puntos como minimo)"<<endl;
    cin>>puntos;
    switch(puntos){
        /*case 1:
        {
            I = (b-a)/2;
            break;
        }*/
        case 2:
        {
            C0 = 1.0; X0 = -0.577350269;
            C1 = 1.0; X1 = -X0;  
            I = ((b - a) / 2) * (C0 * f((b - a) / 2) * X0 + (b + a) / 2) + C1 * f(((b - a) / 2) * X1 + (b +a ) / 2);
            break;
        }
        case 3:
        {
            C0 = 0.5555556; X0 = -0.774596669;
            C1 = 0.8888889; X1 = 0.0;
            C2 = C0;        X2 = -X0;
            I = ((b - a) / 2) * (C0 * f((b - a) / 2) * X0 + (b + a) / 2) + C1 * f(((b - a) / 2) * X1 + (b + a) / 2) 
                + C2 * f(((b - a) / 2) * X2 + (b + a) / 2);
            break;
        }
        case 4:
        {
            C0 = 0.3478548; X0 = -0.861136312;
            C1 = 0.6521452; X1 = -0.339981044;
            C2 = C1;        X2 = -X1;
            C3 = C0;        X3 = -X0;
            I = ((b - a) / 2) * (C0 * f((b - a) / 2) * X0 + (b + a) / 2) + C1 * f(((b - a) / 2) * X1 + (b + a) / 2) 
                + C2 * f(((b - a) / 2) * X2 + (b + a) / 2) + C3 * f(((b - a) / 2) * X3 + (b + a) / 2);
            break;
        }
        case 5:
        {
            C0 = 0.2369269; X0 = -0.906179846;
            C1 = 0.4786287; X1 = -0.538469310;
            C2 = 0.5688889; X2 = 0.0;
            C3 = C1;        X3 = -X1;
            C4 = C0;        X4 = -X0;
            I = ((b - a)/2) * (C0 * f((b - a) / 2) * X0 + (b + a) / 2) + C1 * f(((b - a) / 2) * X1 + (b + a) / 2) 
                + C2 * f(((b - a) / 2) * X2 + (b + a) / 2) + C3 * f(((b - a) / 2) * X3 + (b + a) / 2) 
                + C4 * f(((b - a) / 2) * X4 + (b + a) / 2);
            break;
        }
        case 6:
        {
            C0 = 0.1713245; X0 = -0.932469514;
            C1 = 0.3607616; X1 = -0.661209386;
            C2 = 0.4679139; X2 = -0.238619186;
            C3 = C2;        X3 = -X2;
            C4 = C1;        X4  = -X1;
            C5 = C0;        X5 = -X0;
            I = ((b - a)/2) * (C0 * f((b - a) / 2) * X0 + (b + a) / 2) + C1 * f(((b - a) / 2) * X1 + (b + a) / 2) 
                + C2 * f(((b - a) / 2) * X2 + (b + a) / 2) + C3 * f(((b - a) / 2) * X3 + (b + a) / 2) 
                + C4 * f(((b - a) / 2) * X4 + (b + a) / 2) + C5 * f(((b - a) / 2) * X5 + (b + a) / 2);
            break;
        }
        default:
        {
            cout<<"La cantidad de puntos debe estar entre 2 y 6"<<endl;
            break;
        }
    }

    cout<<"El resultado de I es: "<<I<<endl;

    return 0;
}

double f(double x){
    return x;
}