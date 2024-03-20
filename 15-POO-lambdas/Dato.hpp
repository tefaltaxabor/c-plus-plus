#include <iostream>
using namespace std;

class Dato{
    private:
        string nombre;
        char sexo;
        double saldo;
    public:
        Dato(){}
        Dato(string nombre, char sexo, double saldo){
            this->nombre = nombre;
            this->sexo = sexo;
            this->saldo = saldo;
        }
        ~Dato(){}
        void setNombre(string nombre){this->nombre = nombre;}
        void setSexo(char sexo){this->sexo = sexo;}
        void setSaldo(double saldo){this->saldo = saldo;}
        string getNombre(){return this->nombre;}
        char getSexo(){return this->sexo;}
        double getSaldo(){return this->saldo;}
        friend ostream &operator << (ostream &os, Dato d){
            os << d.nombre << ",";
            os << d.sexo << ",";
            os << d.saldo;
            return os;
        }

};