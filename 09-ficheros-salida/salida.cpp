/*
Dados los datos apellidos, nombres e ingresos por sueldo, consultorias y regalias
calcular el total de ingresos por persona y almacenarlo en un fichero
con el formato:
nombre completo,ingreso total
...
Ana Gomez Suarez,7510.90
...
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Persona{
    string apellidos;
    string nombres;
    double sueldo;
    double consultorias;
    double regalias;
    double ingresos_totales;
};

void leer_datos(vector<struct Persona> &datos){
    string cabecera;
    string apellidos;
    string nombres;
    string sueldo_str; double sueldo;
    string consultorias_str; double consultorias;
    string regalias_str; double regalias;
    ifstream f("datos.txt");
    getline(f, cabecera);
    while(getline(f, apellidos, ',')){
        getline(f, nombres, ',');
        getline(f, sueldo_str, ',');
        getline(f, consultorias_str, ',');
        getline(f, regalias_str);
        // Casting de datos
        sueldo = stod(sueldo_str);
        consultorias = stod(consultorias_str);
        regalias = stod(regalias_str);
        // Variable temporal
        struct Persona p;
        p.apellidos = apellidos;
        p.nombres = nombres;
        p.sueldo = sueldo;
        p.consultorias = consultorias;
        p.regalias = regalias;
        p.ingresos_totales = p.sueldo + p.consultorias + p.regalias;
        // Agregado a la variable vector
        datos.push_back(p);
    }
    f.close();
}

void escribir_datos(vector<struct Persona> datos){
    int n = datos.size();
    ofstream f("datos-salida.txt"); // Chanca los datos que hayan en el fichero
    // ofstream f("datos-salida.txt", ios_base::app); // Agrega datos al final del fichero (no chanca datos)
    f << "Nombres completos,Ingresos totales" << endl;
    for(int i=0; i<n; i++){
        f << datos[i].nombres << " " << datos[i].apellidos << ",";
        f << datos[i].ingresos_totales << endl;
    }
    f.close();
}

int main(){
    vector<struct Persona> datos;
    leer_datos(datos);
    escribir_datos(datos);
    return 0;
}