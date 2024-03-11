#include<iostream>
#include<fstream>
using namespace std;

void mostrar_notas(int notas[], int n){
    cout << "Notas de los estudiantes" << endl;
    for(int i=0; i<n; i++){
        cout << "Nota " << i+1 << ": " << notas[i] << endl;
    }
}

float calcular_promedio(int notas[], int n){
    float suma = 0;
    for(int i=0; i<n; i++){
        suma += notas[i];
    }
    return suma/n;
}

void mostrar_promedio(int notas[], int n)
{
   cout << "Promedio de las notas" << endl;
   cout << calcular_promedio(notas, n);
}
int main()
{
    string linea;
    int cantidad = 0;
    ifstream g("notas.txt"); // Apertura para lectura
    while(getline(g, linea)){
        cantidad ++;
    }
    g.close(); // Cierre

    int notas[cantidad];
    string nota_str;
    int nota;
    ifstream f("notas.txt"); // Apertura de fichero para lectura
    int i=0;
    while(getline(f, nota_str)){
        nota = stoi(nota_str);
        notas[i] = nota;
        i++;
    }
    f.close(); // Cierre del fichero

    mostrar_notas(notas, cantidad);
    mostrar_promedio(notas, cantidad);

    return 0; 
}