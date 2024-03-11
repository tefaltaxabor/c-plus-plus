#include <iostream>
#include <fstream> // Lectura y escritura de ficheros
using namespace std;

struct Persona{
    string nombre;
    int saldo;
    float estatura;
};

void mostrar_datos(struct Persona p){
    cout << "Nombre: " << p.nombre << endl;
    cout << "Saldo: " << p.saldo << endl;
    cout << "Estatura: " << p.estatura << endl << endl;
}

int main()
{
    string s;
    ifstream f("datos.txt");
    cout << "Fichero con datos simples" << endl;
    while(getline(f, s)){
        cout << s << endl;
    }
    
    cout << endl;

    string nombre;
    string saldo_str;
    string estatura_str;
    ifstream g("datos-complejos.txt");
    cout << "Fichero con datos complejos" << endl;
    while(getline(g, nombre, ',')){
        getline(g, saldo_str, ',');
        getline(g, estatura_str);

        struct Persona p;
        p.nombre = nombre;
        p.saldo = stoi(saldo_str);
        p.estatura = stod(estatura_str);

        mostrar_datos(p);
    }
    return 0;
}