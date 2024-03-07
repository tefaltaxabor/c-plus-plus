#include <iostream>
#include <cstdlib>
using namespace std;

int MAX = 100;

void recibir_tamaño_de_matriz (int &n)
{
    do
    {
        cout<<"Ingresar tamaño de matriz n: "; cin>> n;
        if(!(n>0 && n < MAX))
        {
            cout << "n debe ser positivo"<< endl;
        }

    } 
    while (!(n>0 && n < MAX));
    
}
void generar_Matriz_A(int n, int Matriz_A[][MAX]);
void generar_Matriz_A(int n, int Matriz_A[][MAX])
{
    cout << "Matriz A" << endl;
    srand(time(NULL)); // Reiniciar la semilla aleatoria
    int min = 0, max = 10; // "limites"
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Matriz_A[i][j] = rand()%(max-min+1) + min;
        }   
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        {
            cout << Matriz_A[i][j] << "\t";
        }  
        cout << endl;
} 
}
void generar_Matriz_B(int n, int Matriz_B[][MAX]);
void generar_Matriz_B(int n, int Matriz_B[][MAX])
{
    cout << "Matriz B" << endl;
    srand(time(NULL)); // Reiniciar la semilla aleatoria
    int min = 0, max = 10; // "limites"
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Matriz_B[i][j] = rand()%(max-min+1) + min;
        }   
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++){
            cout << Matriz_B[i][j] << "\t";
        }  
        cout << endl;
    }
}
void Suma_de_Matrices(int Matriz_A[][MAX] ,int Matriz_B[][MAX], int n, int Suma_de_Matrices[][MAX]);

void Suma_de_Matrices(int Matriz_A[][MAX] , int Matriz_B[][MAX], int n, int Suma_de_Matrices[][MAX])
{
    
    cout << "Suma_de_A_y_B"<< endl; 
    for (int i = 0 ; i <n; i++)
        {   
            for(int j = 0 ; j < n ; j++)
            {
                Suma_de_Matrices[i][j] = Matriz_A[i][j]  + Matriz_B[i][j];
            }
            cout << endl;
        }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++){
            cout << Suma_de_Matrices[i][j] << "\t";
        }  
        cout << endl;
    }
}

int main()
{
    int n;
    int Matriz_A[MAX][MAX];
    int Matriz_B[MAX][MAX];
    int Suma_de_Matrices[MAX][MAX];
    recibir_tamaño_de_matriz (n);
    generar_Matriz_A(n, Matriz_A);
    generar_Matriz_B(n, Matriz_B);
    Suma_de_Matrices(Matriz_A, n ,Matriz_B, Suma_de_Matrices);
    return 0;
}

