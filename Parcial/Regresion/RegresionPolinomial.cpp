#include<iostream>
#include<math.h>
using namespace std;
double** generateNodeMatrix(int);
void printNodes(double**,int);
double* eliminacionGaussiana(double**, double[], int);
void printmatrix(double**,int,int);

int main()
{
    int n=0,p=0;
    
    cout<<"Ingresa la cantidad de nodos: ";
    cin>>n;
    double** nodes=generateNodeMatrix(n);
    printNodes(nodes,n);

    cout<<"Ingresa grado de polinomio para la regresion polinomial: ";
    cin>>p;

    if(p>n) cout<<"Advertencia datos insuficientes para el grado del polinomio";
    
    //Armado de matriz A y b
    double** matrixA=(double**)malloc((p+1)*sizeof(double*));
    if(matrixA==NULL)exit(1);
    for(int ii =0;ii<p+1;ii++)
    {
        matrixA[ii]=(double*)malloc((p+1)*sizeof(double));
        if(matrixA[ii]==NULL)exit(1);
    }

    double* vectorB = (double*)malloc((p+1)*sizeof(double));
    if(vectorB==NULL)exit(1);

    //cargando valores
    for(int l=0;l<p+1;l++)//recorrer filas
    {
        double sumaxy=0;//para b
        for(int i =0;i<n;i++)
            sumaxy+=pow(nodes[i][0],l)*nodes[i][1];
        vectorB[l]=sumaxy;
        for(int m=0;m<p+1;m++) //recorrer columnas
        {
            double sumax=0;//para A
            for(int i=0;i<n;i++)
                sumax+=pow(nodes[i][0],l+m);
            matrixA[l][m]=sumax;
        }
    }

    //calcular valores
    double* a=eliminacionGaussiana(matrixA,vectorB,p+1);

    //impresion del polinomio:
    cout<<"P(X)=";
    for(int ii=0;ii<p+1;ii++)
    {
        if(ii<p)
            cout<<"("<<a[ii]<<")x(X)^"<<ii<<"+";
        else
            cout<<"("<<a[ii]<<")x(X)^"<<ii;
    }
    cout<<"\n";
    return 0;

}

double** generateNodeMatrix(int num)
{
    double** nodes;

    nodes = (double**) malloc (num * sizeof(double*));
    if(nodes == NULL)exit(1);
    for(int ii=0;ii<num;ii++)
    {
        nodes[ii]=(double*)malloc(2*sizeof(double));
        if(nodes[ii]==NULL)exit(1);
        cout<<"Ingresa el x"<<ii<<": ";
        cin>>nodes[ii][0];
        cout<<"Ingresa el y"<<ii<<": ";
        cin>>nodes[ii][1];
        cout<<"\n";

    }
    cout<<"nodos cargados\n";
    return nodes;
}

double* eliminacionGaussiana(double** matrixA, double vectorB[], int n)
{
    cout<<"Original: \n";
    printmatrix(matrixA,n,n);

    //triangulacion
    for(int j=0; j<(n-1);j++)
    {
        //pivoteo
        int p=j;
        if(fabs(matrixA[j][j]) < 10e-5)
        {
            //cout<<"-pivoteo executado j:"<<j<<" Elemento: "<<matrixA[j][j]<<" valor abs:<<"<<fabs(matrixA[j][j])<<"\n";
            for(int i=j+1;i<n;i++)
            {
                if(fabs(matrixA[i][j])>fabs(matrixA[j][j]))
                {
                    p=i;
                }
            }
            for(int m=0;m<n;m++)
            {
                double swap = matrixA[p][m];
                matrixA[p][m] = matrixA[j][m];
                matrixA[j][m] = swap;
            }
            double swap = vectorB[p];
                vectorB[p] = vectorB[j];
                vectorB[j] = swap;
        }
        //-fin del pivoteo

        for(int i = j+1;i<n;i++)
        {
            if(matrixA[j][j] == 0)
            {
                cout<<"Cero en el denominador"<<"A["<<j<<"]["<<j<<"], posible error valor demasiado pequeño\n";
                exit(1);
            }
            double factor= (-matrixA[i][j]/matrixA[j][j]);
            for(int k=j;k<n;k++)
            {
                matrixA[i][k]= matrixA[i][k] + factor * matrixA[j][k];
            }
            vectorB[i]=vectorB[i] + factor*vectorB[j];
        }
    }
    //calcular determinante
    double det=1;
    for(int i =0;i<n;i++)
    {
        det *= matrixA[i][i];
    }
    if(det == 0)
    {
        cout<<"Matriz singular\n";
        exit(1);
    }
    else //retrosustitucion
    {
        double* x=(double*)malloc(n*sizeof(double));
        if(x==NULL)exit(1);
        x[n-1]= vectorB[n-1]/matrixA[n-1][n-1];
        for(int i=n-2;i>-1;i--)
        {
            double suma = vectorB[i];
            for(int k = i+1;k<n;k++)
            {
                suma = suma - matrixA[i][k]*x[k];
            }
            x[i] = suma/matrixA[i][i];
        }
        cout<<"Matriz:\n";
        printmatrix(matrixA,n,n);
        return x;
    }
    
}

void printNodes(double** nodes,int num)
{
    for(int ii=0;ii<num;ii++)
        cout<<"x"<<ii<<":"<<nodes[ii][0]<<" y"<<ii<<":"<<nodes[ii][1]<<"\n";
}
void printmatrix(double **matrix,int fil,int col)
{
    for(int ii=0;ii<fil;ii++)
    {
        for(int jj=0;jj<col;jj++)
            cout<<matrix[ii][jj]<<"\t";
        cout<<"\n";
    }
}