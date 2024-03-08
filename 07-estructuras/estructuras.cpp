#include <iostream>
using namespace std;

struct Persona{
    int edad;
    float peso;
    bool esta_casado;
    string nombre;
    int notas[4];
};

void leer_datos(struct Persona &p){
    cout << "Registro de datos" << endl;
    cout << "Edad: "; cin >> p.edad;
    p.peso = 72.5;
    p.esta_casado = false;
    p.nombre = "Jose";
    p.notas[0] = 18;
    p.notas[1] = 20;
    p.notas[2] = 19;
    p.notas[3] = 15;
}

void imprimir_datos(struct Persona p){
    cout << "Informacion registrada" << endl;
    cout << "Edad: " << p.edad << endl;
    cout << "Peso: " << p.peso << endl;
}

int main(){
    struct Persona p;
    leer_datos(p);
    imprimir_datos(p);
    return 0;
}