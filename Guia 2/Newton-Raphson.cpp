#include <iostream>
#include <math.h>
using namespace std;

double f(double x);
double fp(double x);//fprima
int main(int argc, char *argv[]) {
	double xv=0, xn=0, error=1, tolerancia;//xv=xvieja xn=xnueva
	int contador=0;
	cout<<"Ingrese xv:"<<endl;
	cin>>xv;
	cout<<"Ingrese tolerancia:"<<endl;
	cin>>tolerancia;
	do{
		contador++;
		if(fabs(fp(xv))<pow(10,-5)){
			cout<<"Derivada muy pequenia"<<endl;
			return 0;
		}else{
			xn=xv-((f(xv))/(fp(xv)));
			error=fabs(xn-xv);
			xv=xn;
		}
	} while(error>tolerancia && contador < 10000);
	cout<<"La raiz es: "<<xn;
	cout<<"El error es: "<<error;
	cout<<"La cantidad de iteraciones es: "<<contador;
	return 0;
}

double f(double x){
	double resultado=2*x + log(x) - sin(3*x);//funcion ejemplo
	return resultado;
}
double fp(double x){//esta debe ser la derivada de la funcion
	double resultado=fabs((3*f(x)-4*f(x-0.01) + f(x-2*0.01))/2*0.01);//funcion ejemplo
	return resultado;
}
