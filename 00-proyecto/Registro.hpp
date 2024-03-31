#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Registro{
    private:
        string usuario;
        string aPaterno;
        string aMaterno;
        string nombres;
        string dni;
        double estaturaM;
        double pesoKg;
        double presionMmhg;
    public:
        Registro(){}
        Registro(string usuario){
            this->usuario = usuario;
            this->aPaterno = "";
            this->aMaterno = "";
            this->nombres = "";
            this->dni = "";
            this->estaturaM = -1;
            this->pesoKg = -1;
            this->presionMmhg = -1;
        }

        Registro(string usuario, string aPaterno, string aMaterno, string nombres, string dni, double estaturaM, double pesoKg, double presionMmhg){
            this->usuario = usuario;
            this->aPaterno = aPaterno;
            this->aMaterno = aMaterno;
            this->nombres = nombres;
            this->dni = dni;
            this->estaturaM = estaturaM;
            this->pesoKg = pesoKg;
            this->presionMmhg = presionMmhg;
        }
        
        ~Registro(){}

        void leerFichero(string linea){
            cout << "Linea: " << linea << endl;
            string usuario;
            string aPaterno;
            string aMaterno;
            string nombres;
            string dni;
            double estaturaM; string estaturaM_str;
            double pesoKg; string pesoKg_str;
            double presionMmhg; string presionMmhg_str;
            stringstream linea_ss(linea);
            while(getline(linea_ss, usuario, ',')){
                getline(linea_ss, aPaterno, ',');
                getline(linea_ss, aMaterno, ',');
                getline(linea_ss, nombres, ',');
                getline(linea_ss, dni, ',');
                getline(linea_ss, estaturaM_str, ',');
                getline(linea_ss, pesoKg_str, ',');
                getline(linea_ss, presionMmhg_str);
                // Casting de tipos
                estaturaM = stod(estaturaM_str);
                pesoKg = stod(pesoKg_str);
                presionMmhg = stod(presionMmhg_str);
                this->usuario = usuario;
                this->aPaterno = aPaterno;
                this->aMaterno = aMaterno;
                this->nombres = nombres;
                this->dni = dni;
                this->estaturaM = estaturaM;
                this->pesoKg = pesoKg;
                this->presionMmhg = presionMmhg;
            }
        }
        // Leer (desde consola)
        void leerConsola(){
            string usuario;
            string aPaterno;
            string aMaterno;
            string nombres;
            string dni;
            double estaturaM;
            double pesoKg;
            double presionMmhg;
            cout << "Usuario: "; cin >> usuario;
            cout << "Apellido Paterno"; cin >> aPaterno;
            cout << "Apellido Materno"; cin >> aMaterno;
            cout << "Nombres"; cin >> nombres;
            cout << "DNI"; cin >> dni;
            cout << "Estatura en metros"; cin >> estaturaM;
            cout << "Peso en Kg"; cin >> pesoKg;
            cout << "Presion en Mmhg"; cin >> presionMmhg;
        }
        /*
        void setNombre(string nombre){this->nombre = nombre;}
        void setDni(string dni){this->dni = dni;}
        void setSaldo(double saldo){this->saldo = saldo;}
        void setGenero(char genero){this->genero = genero;}
       
        string getNombre(){return this->nombre;}
        string getDni(){return this->dni;}
        double getSaldo(){return this->saldo;}
        char getGenero(){return this->genero;}
        */
        friend ostream &operator << (ostream &os, Registro r){
            os << r.usuario << ",";
            os << r.aPaterno << ",";
            os << r.aMaterno << ",";
            os << r.nombres << ",";
            os << r.dni << ",";
            os << r.estaturaM << ",";
            os << r.pesoKg << ",";
            os << r.presionMmhg;
            return os;
        }

};