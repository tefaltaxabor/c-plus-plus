#include <iostream>
using namespace std;

class Dato{
    private:
        string nombre;
        string dni;
        double saldo;
        char genero;
    public:
        Dato(){}
        Dato(string nombre){
            this->nombre = nombre;
            this->dni = "";
            this->saldo = 0;
            this->genero = '-';
        }
        Dato(string nombre, string dni, double saldo, char genero ){
            this->nombre = nombre;
            this->dni = dni;
            this->saldo = saldo;
            this->genero = genero;
        }
        ~Dato(){}
        void setNombre(string nombre){this->nombre = nombre;}
        void setDni(string dni){this->dni = dni;}
        void setSaldo(double saldo){this->saldo = saldo;}
        void setGenero(char genero){this->genero = genero;}
       
        string getNombre(){return this->nombre;}
        string getDni(){return this->dni;}
        double getSaldo(){return this->saldo;}
        char getGenero(){return this->genero;}
        friend ostream &operator << (ostream &os, Dato d){
            os << d.nombre << ",";
            os << d.dni << ",";
            os << d.saldo << ",";
            os << d.genero;
            return os;
        }

};