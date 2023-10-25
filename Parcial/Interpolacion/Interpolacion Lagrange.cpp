#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int xp=0, n=4;//n valor modificable segun el caso
	double prod=0, suma=0;
	double x[4]={2.0,3.0,4.0,5.0}, y[4]={1.0,0.7,-0.2,-1.0};
	cout<<"Ingresar xp"<<endl;
	cin>>xp;
	for(int k=0;k<n;k++){
		prod=1;
		for(int j=0;j<n;j++){
			if(j!=k){
				prod=prod*((xp-x[j])/(x[k]-x[j]));
			}
		}
		suma=suma+y[k]*prod;
	}
	cout<<"El valor interpolado es: "<<suma;
	return 0;
}

