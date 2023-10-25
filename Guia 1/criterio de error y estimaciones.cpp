#include <iostream>
#include <math.h>
using namespace std;

double f(double x);
int main(int argc, char *argv[]) {
	double a, b, c,cv=a, tolerancia, error=1;
	cout<<"Ingrese a:"<<endl;
	cin>>a;
	cout<<"Ingrese b:"<<endl;
	cin>>b;
	cout<<"Ingrese tolerancia:"<<endl;
	cin>>tolerancia;
	if(f(a)*f(b)>0){
		cout<<"No hay raiz"<<endl;
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
		error= abs(c-cv);
		cv=c;
	} while(error>tolerancia);
	cout<<"La raiz es: "<<c;
	return 0;
}
double f (double x){
	double resultado=2*x;
	return resultado;
}
