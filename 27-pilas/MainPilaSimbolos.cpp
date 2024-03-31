#include "Stack.hpp"

class Simbolo{
    public:
        char s;
        Simbolo(){}
        Simbolo(char s){
            this->s = s;
        }
        ~Simbolo(){}
};
class Aplicacion{
    private:
        string expresion; // "Hola (mensaje) como estan {(Adios)}"
        Stack<Simbolo> stackSimbolos;
        string simbolosApertura;
        string simbolosCierre;
    public:
        Aplicacion(string expresion, string simbolosApertura, string simbolosCierre){
            this->expresion = expresion;
            this->simbolosApertura = simbolosApertura;
            this->simbolosCierre = simbolosCierre;
            this->stackSimbolos.resize(this->expresion.size());
        }
        ~Aplicacion(){}
        int esDeApertura(char simbolo){
            // Se recorre el vector  de simbolos de apertura para uicar a cual de ellos corrresponde el simbolo
            for(int i=0; i<this->simbolosApertura.size(); i++){
                if(simbolo == this->simbolosApertura[i]){
                    return i;
                }
            }
            return -1;
        }
        int esDeCierre(char simbolo){
            // Se recorre el vector  de simbolos de cierre para uicar a cual de ellos corrresponde el simbolo
            for(int i=0; i<this->simbolosCierre.size(); i++){
                if(simbolo == this->simbolosCierre[i]){
                    return i;
                }
            }
            return -1;
        }
        bool estaBalanceado(){
            for(int i=0; i<this->expresion.size(); i++){
                char simbolo = this->expresion[i];
                int posSimbAp = esDeApertura(simbolo);
                int posSimbCi = esDeCierre(simbolo);
                if(posSimbAp != -1){ // Es simbolo de apertura
                    this->stackSimbolos.push(Simbolo(simbolo));
                }else if(posSimbCi != -1){ // simbolo de cierre
                    int posSimbApTop = esDeApertura(this->stackSimbolos.top().s); // /s se agrega para acceder al caracter
                    if(posSimbCi == posSimbApTop){ // Si el simbolo de cierre encuentra en la tapa su correspondiente pero de apertura
                        this->stackSimbolos.pop(); // Se desapila
                    }else{
                        return false;
                    }
                }
            }
            // ANALIZAMOS SI AUN QUEDAN ELEMENTOS SIN DESAPILAR EN LA PILA
            if(this->stackSimbolos.isEmpty() == true){
                return true;
            }else{
                return false;
            }
        }
        void analizar(){
            if(this->estaBalanceado() == true){
                cout << "La expresion esta correctamente balanceada" << endl;
            }else{
                cout << "La expresion no esta balanceada" << endl;
            }
        }
};

int main(){
    Aplicacion a("{}(>)(a)[]", "([<{", ")]>}");
    a.analizar();
    return 0;
}