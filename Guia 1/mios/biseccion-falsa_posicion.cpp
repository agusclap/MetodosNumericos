#include <iostream>
#include <cmath>
#include <iomanip>
void biseccion(double a ,double b,double solucion ,double error , int contador );
void falsaposicion(double a, double b, double solucion, double error, int contador, double solucionAnterior);
double funcion(double f);

using namespace std;
int main(){
    char opcion = ' ';
    double a,b,solucion,error,solucionAnterior=0;
    int contador =0;
    do{
    cout<<"Ingrese el primer intervalo"<<endl;
    cin>>a;
    cout<<"Ingrese el segundo intervalo"<<endl;
    cin>>b;
    cout<<"Seleccione la opcion que desea:\n"<<"a.Biseccion \n"<<"b.Falsa Posicion\n"<<endl;    
    cin>>opcion;

    switch(opcion){
        case 'a':
            biseccion(a,b,solucion,error,contador);
            break;
        case 'b':
        falsaposicion(a,b,solucion,error,contador, solucionAnterior);
            break;
        
         default:
            exit(0);
            break;
    }
  cout<<"Si desea continuar presione s"<<endl;
  cin>>opcion;
}while(opcion=='s');
}
void biseccion(double a, double b,double solucion,double error,int contador){
  
   if(funcion(a)*funcion(b)>0){
    cout<<"No hay raiz";
}
do{
    solucion=(a+b)/2;
    if(funcion(a)*funcion(solucion)>0){
        a=solucion;
}
    else if(funcion(a)*funcion(solucion)<0){
        b=solucion;
    }
    else{
        cout<<"La raiz es"<<solucion<<endl;
        exit(0);
    }
    error = (b-a)/2;
    contador++;

}while(error>1e-5);
cout<<"Raiz \t"<<"Iteraciones \n"<<endl;
std::cout << std::fixed << std::setprecision(5) << solucion<<"\t" <<contador<< std::endl;

}

void falsaposicion(double a,double b, double solucion , double error, int contador,double solucionAnterior){
     
 if (funcion(a) * funcion(b) < 0) {
        // Calculo la solucion
        do {
            
            solucion=(a+b)/2;
        
            if (funcion(a) * funcion(solucion) > 0) {
                a = solucion;
            } else if(funcion(a)*funcion(solucion)<0){
                b = solucion;
            }
            else{
                cout<<"La raiz es:"<<solucion<<endl;
                exit(0);
            }
            
            error = abs((solucion - solucionAnterior));  // Cálculo del error absoluto
            solucionAnterior = solucion;  // Actualizar la solucion anterior
            contador++;

        } while (error > 1e-5);  // Tolerancia de 1e-5

        cout<<"Raiz \t"<<"Iteraciones \n"<<endl;
        std::cout << std::fixed << std::setprecision(5) << solucion<<"\t" <<contador<< std::endl;
}    
     else{
        cout << "No hay solucion." << endl;
    }
}

double funcion(double f){
    double fu = pow(f,10)-1;
    return fu;
}