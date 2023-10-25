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
			cout<<"La raiz es: "<<c;
			cout<<"La cantidad de iteraciones es: "<<contador;
			exit (0);
		}
		error=(b-a)/2;
	} while(error>tolerancia);
	cout<<"La raiz es: "<<c;
	cout<<"La cantidad de iteraciones es: "<<contador;
	return 0;
}

double f (double x){
	double resultado=pow(x,10)-1;
	return resultado;
}
