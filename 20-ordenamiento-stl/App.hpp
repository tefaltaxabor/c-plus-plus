#include <iostream>
#include <vector>
#include <fstream>
#include "Dato.hpp"
#include <functional>
#include "Ordenamiento.hpp"
using namespace std;

// Gestor de datos/registros
class App{
    private:
        vector<Dato> datos;
        string nombre;
        string urlFicheroEntrada;
        string urlFicheroSalida;
    
    public:
        App(string urlFicheroEntrada,  string urlFicheroSalida){
            this->urlFicheroEntrada = urlFicheroEntrada;
            this->urlFicheroSalida = urlFicheroSalida;
        }
        App(){
            this->urlFicheroEntrada = "datos.txt";
            this->urlFicheroSalida = "datosSalida.txt";
          

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
            string dni;
            string genero_str; char genero;
            string saldo_str; double saldo;
            ifstream f(this->urlFicheroEntrada);
            getline(f, cabecera);
            while(getline(f, nombre, ',')){
                getline(f, dni, ',');
                getline(f, saldo_str, ',');
                getline(f,genero_str );
                // Casting
                genero = genero_str[0];
                saldo = stod(saldo_str);

                // Variable temporal
                Dato d(nombre, dni, saldo, genero);

                // Se agrega al contener (vector)
                this->datos.push_back(d);
            }
        }
        
        
        void escribir(){
            string cabecera = "nombre,dni,saldo,genero";
            ofstream f(this->urlFicheroSalida);
            f << cabecera << endl;
            // criterio de comparacion
            for(int i=0; i<datos.size(); i++){
                    f << datos[i] << endl;     
            }
        }
        void ordenar(function<bool(Dato , Dato)> cmp)
        {
            //sort(datos.begin(), datos.end() , cmp);
            shell_sort<Dato>(this->datos, cmp);
            
        }

};