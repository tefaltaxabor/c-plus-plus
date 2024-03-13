#include<iostream>
/*
    Se puede poner tmb como dos atributos pero estoy mas familiarizado con el dia mes y año
    ,ya que podemos tratar a la fecha de nacimiento como un vector de 3 dimensiones
    asi, creo que para poder hacerlo solo con dos atributos seria con tratarlo como
    un pf es el año 2024 (0 , 0 , 2024) y la fecha ( ** , ** , ****) y para obtener 
    la edad seria 2024 - ****, lo mas importante es el año
*/
using namespace std;
class Fecha
{
    private: 

        int dia;
        int mes;
        int anho;
    public:
        Fecha(){}; //metodo vacio
        Fecha(int dia , int mes , int anho)
        {
            
            this->dia = dia;
            this->mes = mes;
            this->anho = anho;
        }
        ~Fecha(){}
        //Setter y Getter
        
        void setDia(int dia){this->dia = dia;}
        void setMes(int mes){this->mes = mes;}
        void setAnho(int anho){this->anho = anho;}
        int getDia(){return this->dia;}
        int getMes(){return this->mes;}
        int getAnho(){return this->anho;}
        //Metodo ah doc
        int calcularAnhosTranscurridos(int anhoActual)
        {
            return anhoActual - this->anho;
        }
};
class Persona
{
    private:
        string nombre;
        string apellido;
        Fecha fechaNacimiento; // Se almacena
        int edad;  // Se genera cada que se realiza la consulta
    public:
        Persona(string nombre, string apellido, Fecha fechaNacimiento)
        {
            this->nombre = nombre;
            this->apellido = apellido;
            this->fechaNacimiento = fechaNacimiento;
        }
        ~Persona(){};
        void setNombre(string nombre){this->nombre = nombre;}
        void setApellido(string apellido){this->apellido = apellido;}
        void setFechaNacimiento(Fecha fechaNacimiento){this->fechaNacimiento = fechaNacimiento;}
        void setEdad(int anhoActual){this->edad = this->fechaNacimiento.calcularAnhosTranscurridos(anhoActual);}
        string getNombre(){return this->nombre;}
        string getApellido(){return this->apellido;}
        int getEdad(int anhoActual)
        {
            this->setEdad(anhoActual); // Primero se setea respecto al anho proporcionado
            return this->edad; // Una vez actualizado el valor, se retorna
        }
};
int main()
{
    int anhoActual = 2024;
    Fecha fechaNacimiento(27, 9, 2004);
    Persona persona1("Gabriel", "Cabrera", fechaNacimiento);
    cout << "Edad: " << persona1.getEdad(anhoActual) << endl;
    return 0;
}
