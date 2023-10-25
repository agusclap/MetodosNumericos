#include <iostream>
#include <math.h>
using namespace std;

double g(double x);
int main(int argc, char *argv[]) {
	double xv=0, xn=0, error=1,tolerancia;
	int contador=0;
	cout<<"Ingrese xv:"<<endl;
	cin>>xv;
	cout<<"Ingrese tolerancia:"<<endl;
	cin>>tolerancia;
	do{
		contador++;
		if(fabs((g(xv+0.01)-g(xv))/0.01)>=1){
			cout<<"No se cumple el criterio de convergencia"<<endl;
			return 1;
		}else{
			xn=g(xv);
			error=fabs(xv-xn);
			xv=xn;
		}
	} while(error>tolerancia);
	cout<<"La raiz es: "<<xn<<endl;
	cout<<"El error es: "<<error<<endl;
	cout<<"La cantidad de iteraciones es: "<<contador;
	return 0;
}
double g (double x){
	double resultado=pow(-x,2) + 4;//funcion de ejemplo
	return resultado;
}
