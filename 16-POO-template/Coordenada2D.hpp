#include <iostream>
using namespace std;
class Coordenada2D{
    private:
        double x;
        double y;
    public:
        Coordenada2D(){}
        Coordenada2D(double x, double y){
            this->x = x;
            this->y = y;
        }
        ~Coordenada2D(){};
        void setX(double x){this->x = x;}
        void setY(double y){this->y = y;}
        double getX(){return this->x;}
        double getY(){return this->y;}
        double calcularDistancia(Coordenada2D c){
            double distancia = sqrt(pow(c.x - this->x, 2) + pow(c.y - this->y, 2));
            return distancia;
        }
        friend ostream &operator << (ostream &os, Coordenada2D c){
            os << c.x << ",";
            os << c.y;
            return os;
        }
};