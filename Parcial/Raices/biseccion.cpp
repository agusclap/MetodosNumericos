#include <iostream>
#include <math.h>
using namespace std;


double f(double x);
int main(int argc, char *argv[]) {
	double a, b, c, tolerancia, error=1;
	cout<<"Ingrese a:"<<endl;
	cin>>a;
	cout<<"Ingrese b:"<<endl;
	cin>>b;
	cout<<"Ingrese tolerancia:"<<endl;
	cin>>tolerancia;
	if(f(a)*f(b)>0){
		cout<<"No hay raiz"<<endl;
		return 1;
	}
	do{
		c=(a+b)/2;
		if(f(a)*f(c)>0){
			a=c;
		}else if(f(a)*f(c)<0){
			b=c;
		}else if(f(a)*f(c)==0){
			cout<<"La raiz es: "<<c;
		}
		error=(b-a)/2.0;
	} while(error>tolerancia);
	cout<<"La raiz es: "<<c;
	return 0;
}

double f (double m){
	const double g = 9.81;
	const double c = 14.0;
	const double t = 7.0;

	return (g * m / c) * (1- exp(-c * t / m)) - 35.0;
}
