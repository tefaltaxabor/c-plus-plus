#include <iostream>
#include <vector>
#include <fstream>
#include "Dato.hpp"
#include <functional>
using namespace std;

// Gestor de datos/registros
class App{
    private:
        vector<Dato> datos;
        string nombre;
        string urlFicheroEntrada;
        string urlFicheroSalidaH;
        string urlFicheroSalidaM;
    public:
        App(string urlFicheroEntrada, string urlFicheroSalidaH, string urlFicheroSalidaM){
            this->urlFicheroEntrada = urlFicheroEntrada;
            this->urlFicheroSalidaH = urlFicheroSalidaH;
            this->urlFicheroSalidaM = urlFicheroSalidaM;
        }
        App(){
            this->urlFicheroEntrada = "datosEntrada.txt";
            this->urlFicheroSalidaH = "datosSalidaH.txt";
            this->urlFicheroSalidaM = "datosSalidaM.txt";

        }
        ~App(){};
        // Set  (Pseudo set)
        void setNombre(string nombre){ this->nombre = nombre; }
        void agregar(Dato d){
            this->datos.push_back(d);
        }
        // Get (Pseudo get)
        void mostrar(){
            for(int i=0; i<datos.size(); i++){
                cout << "v[" << i << "] = " << datos[i] << endl;
            }
        }
        // Lectura
        void leer(){
            string cabecera;
            string nombre;
            string sexo_str; char sexo;
            string saldo_str; double saldo;
            ifstream f(this->urlFicheroEntrada);
            getline(f, cabecera);
            while(getline(f, nombre, ',')){
                getline(f, sexo_str, ',');
                getline(f, saldo_str);
                // Casting
                sexo = sexo_str[0];
                saldo = stod(saldo_str);

                // Variable temporal
                Dato d(nombre, sexo, saldo);

                // Se agrega al contener (vector)
                this->datos.push_back(d);
            }
        }
        // Escribir
        void escribir(function<bool(Dato)> criterio){

            

            string cabecera = "nombre,sexo,saldo";
            ofstream f(this->urlFicheroSalidaH);
            ofstream g(this->urlFicheroSalidaM);
            f << cabecera << endl;
            g << cabecera << endl;
            for(int i=0; i<datos.size(); i++){
                if(criterio(datos[i]) == true)
                    f << datos[i] << endl;
                else
                    g << datos[i] << endl;
            }
        }
    
};