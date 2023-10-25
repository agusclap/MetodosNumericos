#include <iostream>
#include <math.h>
using namespace std;


double g(float x);



int main(int argc, char *argv[]) {
	float xi=0,e=0,tolerancia=0;
	int iter=0;
	float xn=0;
	cout<<"Ingrese punto inicial Xi"<<endl;
	cin>>xi;
	do{
		iter++;
		if(fabs(g(xi+0.01)-g(xi)) >= 1){
			cout<<"No se cumple el criterio de convergencia"<<endl;
			exit(0);
		}else{
			xn = g(xi);
			e = fabs(xi-xn);
			xi = xn;
		}
	} while(e>tolerancia);
	cout<<"raiz de f: "<<xn<<endl;
	cout<<"el error es: "<<e<<endl;
	cout<<"la cantidad de iteraciones es: "<<iter<<endl;
	return 0;
}

double g(float x){
	return pow(-x,2) + 4;
}
