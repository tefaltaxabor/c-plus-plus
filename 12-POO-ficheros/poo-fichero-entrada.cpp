#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>
using namespace std;

// Clase de tipo dato/registro
class Punto3D
{
    private://Atributos
        double x;
        double y;
        double z;
    public: // metodo constructor
        Punto3D(){}; // constructor vacio
        Punto3D(double x, double y , double z) 
        {
            this->x = x; 
            this->y = y;
            this->z = z;
        }
        ~Punto3D(){}
        // Setter y Getter 
        void setX(double x) { this->x = x; }
        void setY(double y) { this->y = y; }
        void setZ(double z) { this->z = z; }
        double getX(){ return this->x; }
        double getY(){ return this->y; }
        double getZ(){ return this->z; }
        //metodos ah doc
         double calcular_distancia_origen()
        {
            return sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
        }
        // Sobrecargar la escritura (1.2, 3.4, 7.9) -> 1.2,3.4,7.9
         friend ostream &operator << (ostream &os, Punto3D p){
            os << p.x << ",";
            os << p.y << ",";
            os << p.z;
            return os;
        }
};

class Vector3D
{
    private:
        Punto3D pi;
        Punto3D pf;
        double modulo;
    public:
        Vector3D(double pi_x, double pi_y, double pi_z, double pf_x, double pf_y, double pf_z)
        {
            this->pi = Punto3D(pi_x, pi_y, pi_z);
            this->pf = Punto3D(pf_x, pf_y, pf_z);
        }
        Vector3D(Punto3D pi , Punto3D pf)
        {
            this->pi = pi;
            this->pf = pf;
        }
        ~Vector3D(){};
        void setPi(Punto3D pi){this->pi = pi;}
        void setPf(Punto3D pf){this->pf = pf;}
        void setModulo(){ this->modulo = sqrt(  pow(this->pf.getX() - this->pi.getX(), 2) + pow(this->pf.getY()-this->pi.getY(),2) + pow(this->pf.getZ() - this->pi.getZ() , 2) );};
        Punto3D getPi(){return this->pi;}
        Punto3D getPf(){return this->pf;}
        double getModulo(){
            this->setModulo();
            return this->modulo;
        }
        friend ostream &operator << (ostream &os, Vector3D v){
            v.setModulo(); // Actualiza el valor del atributo modulo antes de usarlo
            os << v.pi << ",";
            os << v.pf << ",";
            os << v.modulo;
            return os;
        }
};

// Gestor de datos/registros
class App{
    private:
        vector<Vector3D> datos;
        string nombre;
        string urlFicheroEntrada;
        string urlFicheroSalida;
    public:
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


int main()
{
    App app;
    app.leer();
    app.mostrar();
    app.escribir();
    return 0;
}