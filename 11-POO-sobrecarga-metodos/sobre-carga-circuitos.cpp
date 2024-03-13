#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>
using namespace std;

class circuito{
    private:
        string nombre_del_circuito;
        double r1;
        double r2;
        double r3;
    public:
        circuito(){};
        circuito(string nombre_del_circuito, double r1, double r2 , double r3){
            this->nombre_del_circuito = nombre_del_circuito;
            this->r1 = r1;
            this->r2 = r2;
            this->r3 = r3;
        }
        ~circuito(){};
        void setNombre_del_circuito(string nombre_del_circuito){this->nombre_del_circuito = nombre_del_circuito;}
        void setR1(double r1){this->r1 = r1;}
        void setR2(double r2){this->r2 = r2;}
        void setR3(double r3){this->r3 = r3;}
        string getNombre_del_circuito(string Nombre_del_circuito){return this->nombre_del_circuito;}
        double getR1(double r2){return this-> r1;}
        double getR2(double r2){return this-> r2;} 
        double getR3(double r3){return this-> r3;}
        double resistencias_en_serie(){
            return this->r1 + this->r2 + this->r3; 
        }
        double resistencias_en_paralelo(){
            return 1.0 / (1.0 / this->r1 + 1.0 / this->r2 + 1.0 / this->r3);
        }
        //Sobrecarga operador de escritura
        friend ostream &operator << (ostream &os , circuito c){
            os << "Circuito" << c.nombre_del_circuito << "(";
            os << c.r1 << "," ;
            os << c.r2 << ",";
            os << c.r3 << ")";
            return os;
        }//para ubicarlo en la memoria &os
};

class y{
    private:    
        circuito circuito1; 
        circuito circuito2;
        circuito circuito3;
    public:
        y(circuito c1 , circuito c2 , circuito c3){
            this->circuito1 = c1;
            this->circuito2 = c2;
            this->circuito3 = c3;
        }
        ~y(){};
        friend ostream &operator << (ostream &os, y v){
            os << v.circuito1 << v.circuito1.resistencias_en_serie() << " (en serie), " << v.circuito1.resistencias_en_paralelo() << " (en paralelo)" << endl;
            os << v.circuito2 << v.circuito2.resistencias_en_serie() << " (en serie), " << v.circuito2.resistencias_en_paralelo() << " (en paralelo)" << endl;
            os << v.circuito3 << v.circuito3.resistencias_en_serie() << " (en serie), " << v.circuito3.resistencias_en_paralelo() << " (en paralelo)" << endl;
            return os;
        }
};

class App{
    private:
        vector<y> datos;
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
        void agregar(y v){
            this->datos.push_back(v);
        }
        // Get (Pseudo get)
        void mostrar(){
            for(int i=0; i<datos.size(); i++){
                cout << "v[" << i << "] = " << datos[i] << endl;
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
    circuito A("A",3,4,6);
    circuito B("B",4,5,6);
    circuito C("C",5,6,7);
    y v(A,B,C);
    App app;
    app.agregar(v);
    app.mostrar();
    app.escribir();
    return 0;
}

