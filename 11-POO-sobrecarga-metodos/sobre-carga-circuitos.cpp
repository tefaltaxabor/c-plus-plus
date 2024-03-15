#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>
using namespace std;

class Circuito{
    private:
        string nombre_del_circuito;
        double r1;
        double r2;
        double r3;
    public:
        Circuito(){};
        Circuito(string nombre_del_circuito, double r1, double r2 , double r3){
            this->nombre_del_circuito = nombre_del_circuito;
            this->r1 = r1;
            this->r2 = r2;
            this->r3 = r3;
        }
        ~Circuito(){};
        void setNombre_del_circuito(string nombre_del_circuito){this->nombre_del_circuito = nombre_del_circuito;}
        void setR1(double r1){this->r1 = r1;}
        void setR2(double r2){this->r2 = r2;}
        void setR3(double r3){this->r3 = r3;}
        string getNombre_del_circuito(){return this->nombre_del_circuito;}
        double getR1(){return this-> r1;}
        double getR2(){return this-> r2;} 
        double getR3(){return this-> r3;}
        double resistencias_en_serie(){
            return this->r1 + this->r2 + this->r3; 
        }
        double resistencias_en_paralelo(){
            return 1.0 / (1.0 / this->r1 + 1.0 / this->r2 + 1.0 / this->r3);
        }
        //Sobrecarga operador de escritura
        friend ostream &operator << (ostream &os , Circuito c){
            os << c.nombre_del_circuito << ",";
            os << c.r1 << "," ;
            os << c.r2 << ",";
            os << c.r3;
            return os;
        }//para ubicarlo en la memoria &os
};

class App{
    private:
        vector<Circuito> datos;
        string nombre;
        string urlFichero;
    public:
        App(string urlFichero){
            this->urlFichero = urlFichero;
        }
        App(){
            this->urlFichero = "Circuitos.txt";
        }
        ~App(){};
        // Set  (Pseudo set)
        void setNombre(string nombre){ this->nombre = nombre; }
        void agregar(Circuito v){
            this->datos.push_back(v);
        }
        // Get (Pseudo get)
        void mostrar(){
            for(int i=0; i<datos.size(); i++){
                cout << "Circuito " << datos[i].getNombre_del_circuito() << ",";
                cout << "R1 = " << datos[i].getR1() << ", ";
                cout << "R2 = " << datos[i].getR2() << ", ";
                cout << "R3 = " << datos[i].getR3() << endl;
            }
        }
        // Escribir
        void escribir(){
            ofstream f(this->urlFichero);
            for(int i=0; i<datos.size(); i++){
                f << datos[i] << endl;
            }
            f.close();
        }

};
int main(){
    Circuito A("A",3,4,6);
    Circuito B("B",4,5,6);
    Circuito C("C",5,6,7);
    App app;
    app.agregar(A);
    app.agregar(B);
    app.agregar(C);
    app.mostrar();
    app.escribir();
    return 0;
}

