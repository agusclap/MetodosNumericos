#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


double g(double x);


int main(void) {
	double xi=0,e=0,tolerancia=0,xn=0;
	int iter=0;
	
	cout<<"Ingrese punto inicial Xi"<<endl;
	cin>>xi;
	cout<<"Ingrese la tolerancia"<<endl;
	cin>>tolerancia;
	do{
		iter++;
		if(fabs((g(xi+0.01)-g(xi))/0.01) >= 1){
			cout<<"No se cumple el criterio de convergencia"<<endl;
			exit(0);
		}else{
			xn = g(xi);
			e = fabs(xi-xn);
			xi = xn;
		}
	} while(e>tolerancia);
	cout<<"raiz de f: "<<setprecision(12)<<xn<<endl;
	cout<<"el error es: "<<e<<endl;
	cout<<"la cantidad de iteraciones es: "<<iter<<endl;
	return 0;
}

double g(double x){
	return pow(x,x-cos(x));
}