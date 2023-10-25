#include <iostream>
#include <cstdlib>
#include <math.h>

double f(double x);


int main(void){
    double a=0,b=0,t=0,c=0;
    double e=1;
    int iter=0;    
    
    std::cout<<"Ingrese el primer valor del intervalo"<<std::endl;
    std::cin>>a;
    std::cout<<"Ingrese el segundo del intervalo"<<std::endl;
    std::cin>>b;
    std::cout<<"Ingrese la tolerancia deseada"<<std::endl;
    std::cin>>t;
    if(f(a)*f(b)>0){
        std::cout<<"No hay raiz o hay un numero par de raices"<<std::endl;
        exit(1);
    }
    do{
        iter++;
        c=(a+b)/2;
        if(f(a)*f(c) > 0){
            a=c;
        }else if(f(a)*f(c) < 0){
            b=c;
        }else{
            std::cout<<"La raiz es: "<<c<<std::endl;
            exit(1);
        }
        e=(b-a)/2;
    }while(e>t);

    std::cout<<"La raiz es: "<<c<<std::endl;
    std::cout<<"El error es: "<<e<<std::endl;
    std::cout<<"La cantidad de iteraciones es: "<<iter<<std::endl;
    
    return 0;
}

double f(double x){
    return pow(x,10) - 1;
}