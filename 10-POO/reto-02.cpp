#include<iostream>

using namespace std;
class Datos_Persona
{
    private: 
        /*
        Se puede poner tmb como dos atributos pero estoy mas familiarizado con el dia mes y año
        ,ya que podemos tratar a la fecha de nacimiento como un vector de 3 dimensiones
        asi, creo que para poder hacerlo solo con dos atributos seria con tratarlo como
        un pf es el año 2024 (0 , 0 , 2024) y la fecha ( ** , ** , ****) y para obtener 
        la edad seria 2024 - ****, lo mas importante es el año
        */
        string nombre;
        string apellido;
        int dia;
        int mes;
        int año;
    public:
        Datos_Persona(){}; //metodo vacio
        Datos_Persona(string nombre, string apellido , int dia , int mes , int año)
        {
            this->nombre = nombre;
            this->apellido = apellido;
            this->dia = dia;
            this->mes = mes;
            this->año = año;
        }
        ~Datos_Persona(){}
        //Setter y Getter
        void setNombre(string nombre){this->nombre = nombre;}
        void setApellido(string apellido){this->apellido = apellido;}
        void setDia(int dia){this->dia = dia;}
        void setMes(int mes){this->mes = mes;}
        void setAño(int año){this->año = año;}
        string getNombre(){return this->nombre;}
        string getApellido(){return this->apellido;}
        int getDia(){return this->dia;}
        int getMes(){return this->mes;}
        int getAño(){return this->año;}
        //Metodo ah doc
        int calcular_edad1()
        {
            return 2024 - this->año;
        }
};
class Persona
{
    private:
        Datos_Persona Nombre_completo;
        Datos_Persona Fecha_de_Nacimiento;
        int calcular_edad;
    public:
        Persona(Datos_Persona Nombre_completo , Datos_Persona Fecha_de_Nacimiento)
        {
            this->Nombre_completo = Nombre_completo;
            this->Fecha_de_Nacimiento = Fecha_de_Nacimiento;
        }
        ~Persona(){};
        void setNombre_completo(Datos_Persona Nombre_completo){this->Nombre_completo = Nombre_completo;}
        void setFecha_de_Nacimiento(Datos_Persona Fecha_de_Nacimiento){this->Fecha_de_Nacimiento = Fecha_de_Nacimiento;}
        void setCalcular_edad(){this->calcular_edad = Fecha_de_Nacimiento.calcular_edad1();}
        int getCalcular_edad()
        {
        return this->calcular_edad;
        }
};
int main()
{
    Datos_Persona nombre_completo("Gabriel", "Cabrera", 27, 9, 2004);
    Datos_Persona fecha_nacimiento("", "", 27, 9, 2004); 
    Persona person(nombre_completo, fecha_nacimiento);
    person.setCalcular_edad();
    cout << "Edad: " << person.getCalcular_edad() << endl;
    return 0;
}
