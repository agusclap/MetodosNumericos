#include <iostream>
#include <math.h>
using namespace std;

// Trapecio Simple Iaprox=Iex

double function(double x);
void trapecio();
void simpson();

int main (void){
   char seguir = ' ';
   int opcion = 0;

   do{
        cout<<"Asegure de haber definido su funcion!\nMENU DE OPCIONES:\n 1) Trapecio Compuesta\n 2) Simpson Compuesta"<<endl;
        cin>>opcion;
        switch(opcion){
            case 0:
                break;
            case 1:
                trapecio();
                break;
            case 2:
                simpson();
                break;
            default:
                cout<<"Ingrese una opción valida"<<endl;
            
        }
        cout<<"Desea seguir con el programa ? y/n"<<endl;
        cin>>seguir;
   }while(seguir=='y' || seguir == 'Y');

    return 0;
}   

void trapecio(){
    double a=0,b=0; // integration limits
    double intervale = 0, suma = 0 , Iaprox=0;
    
    cout<<"Ingrese a y b"<<endl;
    cin>>a;
    cin>>b;
    cout<<"Ingrese numero de subintervalos"<<endl;
    cin>>intervale;
    double h = (b-a)/ intervale;
    suma = function(a) + function(b);
    for(int i=1;i<intervale;++i){
        suma = suma + 2*function(a+i*h);
    }
    Iaprox=suma * (h/2);
    cout<<"Iaprox = "<<Iaprox<<endl;
    
    //cout<<"Error : "<<error<<endl;
}

void simpson(){
    double x = 0 , a = 0, b = 0 , suma = 0, i = 0;
    int intervale = 0;
    cout<<"Ingrese el limite inferior"<<endl;
    cin>>a;
    cout<<"Ingrese el limite superior"<<endl;
    cin>>b;
    cout<<"Ingrese el numero de subintervalos (WARNING: El numero tiene que ser par)"<<endl;
    cin>>intervale;
    if(intervale % 2 != 0)
        exit(0);
    
    double h = (b-a)/intervale;
    suma = function(a) + function(b);

    for(i=0;i<(intervale/2); ++i){
        x = a + 2*i*h;
        suma = suma + 2*function(x) + 4*function(x-h);
    }
    suma = h/3 * (suma + 4*function(b-h));
    
    cout<<"Resultado: "<<suma<<endl;
    // El error se calcula si la integral es facil de resolver
}

double function(double x)
{
    return pow(x,2) + 1; // function
}

