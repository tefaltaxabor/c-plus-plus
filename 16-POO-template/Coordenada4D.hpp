#include <iostream>
using namespace std;
class Coordenada4D{
    private:
        double x;
        double y;
        double z;
        double w;
    public:
        Coordenada4D(){}
        Coordenada4D(double x, double y, double z, double w){
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }
        ~Coordenada4D(){}
        void setX(double x){this->x = x;}
        void setY(double y){this->y = y;}
        void setZ(double z){this->z = z;}
        void setW(double w){this->w = w;}
        double getX(){return this->x;}
        double getY(){return this->y;}
        double getZ(){return this->z;}
        double getW(){return this->w;}
        double calcularDistancia(Coordenada4D& c){
            double distancia = sqrt(pow(c.x - this->x, 2) + pow(c.y - this->y, 2) + pow(c.z - this->z, 2) + pow(c.w - this->w, 2));
            return distancia;
        }
        friend ostream &operator << (ostream &os,Coordenada4D& c){
            os << c.x << ",";
            os << c.y << ",";
            os << c.z << ",";
            os << c.w;
            return os;
        }
};