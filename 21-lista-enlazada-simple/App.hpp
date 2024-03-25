#include <iostream>
#include <vector>
#include "SimpleLinkedList.hpp"
#include <fstream>
#include "Dato.hpp"
#include <functional>
#include "Ordenamiento.hpp"
using namespace std;

// Gestor de datos/registros
class App{
    private:
        vector<Dato> datos;
        SimpleLinkedList<Dato> datosSLL;
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
            cout << "Datos (vector)" << endl;
            for(int i=0; i<this->datos.size(); i++){
                cout << this->datos[i] << endl;
            }
        }
        void mostrarSLL(){
            cout << "Datos (SLL)" << endl;
            //this->datosSLL.print();
            for(int i=0; i<this->datosSLL.getLength(); i++){
                cout << this->datosSLL.getByPos(i) << endl;
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
        
        void llenarSLL(){
            for(auto e: this->datos){ // Recorro el vector
                this->datosSLL.insertPos(e, 0); // Lleno en la SLL
            }
        }
        
        void escribir(){
            string cabecera = "nombre,dni,saldo,genero";
            ofstream f(this->urlFicheroSalida);
            f << cabecera << endl;
            // Escritura desde el vector
            for(int i=0; i<datos.size(); i++){
                f << datos[i] << endl;     
            }
        }
        void ordenar(function<bool(Dato , Dato)> cmp)
        {
            // Ordenamiento de los datos del vector
            //sort(datos.begin(), datos.end() , cmp);
            shell_sort<Dato>(this->datos, cmp);
            
        }

        void buscarPorNombre(string nombre){
            auto cmp = [](Dato d1, Dato d2){
                if(d1.getNombre() == d2.getNombre()) return 0;
                else return -1;
            };
            Dato d(nombre);
            int pos = this->datosSLL.search(d, cmp);
            if(pos != -1){
                cout << "Dato encontrado en la posicion " << pos << endl;
            }else{
                cout << "No se encontro el dato" << endl;
            }
        }

};