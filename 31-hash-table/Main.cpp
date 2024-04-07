#include "HashTable.hpp"
#include "Persona.hpp"
#include <cmath>

using namespace std;

int hashFunctionFirstChar(Persona p){
    return tolower(p.getNombre()[0]) - 'a';
}

long long int hashFunctionB26(Persona p){
    long long int sum = 0;
    int base = 26;
    for(int i=0; i<p.getNombre().size(); i++){
        int value = tolower(p.getNombre()[i]) - 'a';
        int position = p.getNombre().size() - i - 1;
        int product = value*pow(base, position);
        sum += product;
    }
    return sum;
}

int main(){
    HashTable<long long int, Persona> ht(12, hashFunctionB26);
    ht.insert(Persona("Jose", 20));
    ht.insert(Persona("Ana", 15));
    ht.insert(Persona("Pedro", 18));
    ht.insert(Persona("Marcelo", 19));
    ht.insert(Persona("Lucas", 15));
    ht.insert(Persona("Pablo", 18));
    ht.insert(Persona("Matias", 20));
    ht.insert(Persona("Lucia", 15));
    ht.insert(Persona("Gabriel", 18));
    ht.insert(Persona("Gabriela", 20));
    ht.insert(Persona("Daniela", 15));
    ht.insert(Persona("Domenica", 18));
    
    cout << "Size: " << ht.size() << endl;
    cout << "Elements: " << ht.elements() << endl;
    cout << "Buscando a ana" << endl;
    if(ht.exist(Persona("Ana", 15))){
        cout << "Si esta registrada la informacion de la persona" << endl;
    }else{
        cout << "No esta registrada la informacion de la persona" << endl;
    }
    cout << "Display: " << endl;
    ht.display();
    return 0;
}