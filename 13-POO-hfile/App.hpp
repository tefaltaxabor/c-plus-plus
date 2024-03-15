#include<iostream>
#include<vector>
#include<fstream>
#include "Vector3D.hpp"
using namespace std;

// Gestor de datos/registros
class App{
    private:
        vector<Vector3D> datos;
        string nombre;
        string urlFicheroEntrada;
        string urlFicheroSalida;
    public:§
        App(string urlFicheroEntrada, string urlFicheroSalida){
            this->urlFicheroEntrada = urlFicheroEntrada;
            this->urlFicheroSalida = urlFicheroSalida;
        }
        App(){
            this->urlFicheroEntrada = "datosEntrada.txt";
            this->urlFicheroSalida = "datosSalida.txt";
        }
        ~App(){};
        // Set  (Pseudo set)
        void setNombre(string nombre){ this->nombre = nombre; }
        void agregar(Vector3D v){
            this->datos.push_back(v);
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
            string pi_x_str; double pi_x;
            string pi_y_str; double pi_y;
            string pi_z_str; double pi_z;
            string pf_x_str; double pf_x;
            string pf_y_str; double pf_y;
            string pf_z_str; double pf_z;

            ifstream f(this->urlFicheroEntrada);

            getline(f, cabecera);
            while(getline(f, pi_x_str, ',')){
                getline(f, pi_y_str, ',');
                getline(f, pi_z_str, ',');
                getline(f, pf_x_str, ',');
                getline(f, pf_y_str, ',');
                getline(f, pf_z_str);

                // Casting
                pi_x = stod(pi_x_str);
                pi_y = stod(pi_y_str);
                pi_z = stod(pi_z_str);
                pf_x = stod(pf_x_str);
                pf_y = stod(pf_y_str);
                pf_z = stod(pf_z_str);

                // Variable temporal
                Vector3D v(pi_x, pi_y, pi_z, pf_x, pf_y, pf_z);

                // Se agrega al contener (vector)
                this->datos.push_back(v);
            }
        }
        // Escribir
        void escribir(){
            string cabecera = "pi_x,pi_y,pi_z,pf_x,pf_y,pf_z,modulo";
            ofstream f(this->urlFicheroSalida);
            f << cabecera << endl;
            for(int i=0; i<datos.size(); i++){
                f << datos[i] << endl;
            }
        }

};