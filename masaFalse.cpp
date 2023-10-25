#include <iostream>
#include <math.h>
using namespace std;
double f(double x);
int main(int argc, char *argv[]) {
	double a, b, c, tolerancia, error=1;
	int contador=0;
	cout<<"Ingrese a:"<<endl;
	cin>>a;
	cout<<"Ingrese b:"<<endl;
	cin>>b;
	cout<<"Ingrese tolerancia:"<<endl;
	cin>>tolerancia;
	if(f(a)*f(b)>0){
		cout<<"No hay raiz"<<endl;
		return 0;
	}
	do{
		c=(a*f(b)-b*f(a))/(f(b)-f(a));
		contador++;
		if(f(a)*f(c)>0){
			a=c;
		}else if(f(a)*f(c)<0){
			b=c;
		}else{
			cout<<"La raiz es: "<<c << endl;
			cout<<"La cantidad de iteraciones es: "<<contador << endl;
			exit (0);
		}
		error=(b-a)/2;
	} while(error>tolerancia);
	cout<<"La raiz es: "<< c << endl;
	cout<<"La cantidad de iteraciones es: "<<contador;
	return 0;
}

double f(double m) {
    const double g = 9.81;
    const double c = 14.0;
    const double t = 7.0;
    
    return (g * m / c) * (1 - exp(-c * t / m)) - 35.0;
}