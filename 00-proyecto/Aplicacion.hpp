#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include "Registro.hpp"
#include "SimpleLinkedList.hpp"
using namespace std;

// Gestor de datos/registros
class Aplicacion{
    private:
        vector<Registro> registros;
        string urlFicheroEntrada;
    public:
        Aplicacion(string urlFicheroEntrada){
            this->urlFicheroEntrada = urlFicheroEntrada;
            this->leer();
        }
        Aplicacion(){
            this->urlFicheroEntrada = "registros.txt";
            this->leer();
        }
        ~Aplicacion(){};
        
        // Lectura
        void leer(){
            string cabecera, linea;
            ifstream f(this->urlFicheroEntrada);
            getline(f, cabecera);
            while(getline(f, linea)){
                // Variable temporal
                Registro r;
                r.leerFichero(linea);
                // Se agrega al contenedor (vector)
                this->registros.push_back(r);
            }
        }

        // Escritura
        void escribir(){
            string cabecera = "usuario,apellido paterno,apellido materno,nombre,dni,estatura,peso,presion sanguinea (mm Hg)";
            ofstream f(this->urlFicheroEntrada);
            f << cabecera << endl;
            // Escritura desde el vector
            for(int i=0; i<registros.size(); i++){
                f << registros[i] << endl;     
            }
        }
        void escribir(Registro r){
            string cabecera = "usuario,apellido paterno,apellido materno,nombre,dni,estatura,peso,presion sanguinea (mm Hg)";
            ofstream f(this->urlFicheroEntrada, ios_base::app); // Agrega el registro al final del fichero
            f << cabecera << endl;
            // Escritura del registro
            f << r << endl;
        }

        // Agregar registro
        void agregarRegistro(){
            cout << "Agregar registro" << endl;
            Registro r;
            r.leerConsola(); // Completar al implementacion en Registro.hpp
            // Agregar a nivel logico
            this->registros.push_back(r);
            // Agregar a nivel fisico
            this->escribir(r);
        }

        // Mostrar registros
        void mostrarRegistros(){
            cout << "Mostrar registros (vector)" << endl;
            for(int i=0; i<this->registros.size(); i++){
                cout << this->registros[i] << endl;
            }
        }
        
        // Buscar registro
        void buscarRegistro(){
            cout << "Buscar registro" << endl;
            // Implementar
            
        }

        // Actualizar registro
        void actualizarRegistro(){
            cout << "Actualizar registro" << endl;
            // Implementar (actualizar logico)
            // ...
            // Actualizar fisico
            this->escribir();
        }

        // Eliminar registro
        void eliminarRegistro(){
            cout << "Eliminar registro" << endl;
            // Implementar (actualizar logico)
            // ...
            // Eliminar fisico (sobreescribir el fichero pero sin el dato)
            this->escribir();
        }
        

        
        
        // Set  (Pseudo set)
        void agregar(Registro r){
            this->registros.push_back(r);
        }

        

        void mostrarMenu(){
            cout << "Menu" << endl;
            cout << "1) Agregar registro (L/F)" << endl;
            cout << "2) Mostrar registros (L)" << endl;
            cout << "3) Buscar registro (L)" << endl;
            cout << "4) Actualizar registro (L/F)" << endl;
            cout << "5) Eliminar registro (L/F)" << endl;
            cout << "6) Salir" << endl;
            cout << "Ingresar opcion: ";
        }

        void iniciar(){
            int opcion;
            int salir = 6;
            do{
                this->mostrarMenu();
                cin >> opcion;
                switch(opcion){
                    case 1:
                        system("CLS");
                        this->agregarRegistro();
                        break;
                    case 2:
                        system("CLS");
                        this->mostrarRegistros();
                        break;
                    case 3:
                        system("CLS");
                        this->buscarRegistro();
                        break;   
                    case 4:
                        system("CLS");
                        this->actualizarRegistro();
                        break;
                    case 5:
                        system("CLS");
                        this->eliminarRegistro();
                        break;
                    case 6:
                        system("CLS");
                        cout << "Hasta pronto" << endl;
                        break;
                    default:
                        system("CLS");
                        cout << "Error! Opcion invalida" << endl;
                        break;

                }
            }while(opcion != salir);
        }
};
