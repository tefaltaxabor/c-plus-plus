#include <vector>
#include <iostream>
using namespace std;

template <class K, class V>
class HashEntity{
    private:
        K key;
        V value;
    public:
        HashEntity(){}
        HashEntity(K key, V value){
            this->key = key;
            this->value = value;
        }
        ~HashEntity(){}
        K getKey(){ return this->key; }
        V getValue(){ return this->value; }
};

template <class K, class V>
class HashTable{
    private:
        vector<vector<HashEntity<K, V> > > table;
        K(*hashFunction)(V); // Funcion hash
        int quantity;
        int length;
    public:
        HashTable(int length, K(*hashFunction)(V)){
            this->length = length;
            this->table.resize(length); // Se dimensiona la tabla hash
            this->quantity = 0;
            this->hashFunction = hashFunction;
        }
        ~HashTable(){}
        int size(){
            return this->length;
        }
        int elements(){
            return this->quantity;
        }
        int hash(K key){ // Devuelve la posicion en la tabla hash (vector)
            return key % this->length;
        }
        void insert(V value){
            K key = this->hashFunction(value);
            // Creo un hash entity
            HashEntity<K, V> e(key, value);
            // Ubicamos el elemento de hashTable que tenga un key igual
            this->table[this->hash(key)].push_back(e); // Me ubico en la posicion key, e inserto al value el elemento e
            this->quantity ++;
        }
        bool exist(V value){
            K key = this->hashFunction(value);
            for(int i=0; i<this->table[this->hash(key)].size(); i++){
                if(this->table[this->hash(key)][i].getValue() == value){
                    return true;
                }
            }
            return false;
        }
        void display(){
            for(int i=0; i<this->table.size(); i++){
                cout << i << "\t";
                for(int j=0; j<this->table[i].size(); j++){
                    cout << "(";
                    cout << "Key: " << this->table[i][j].getKey() << ", ";
                    cout << "Value: " << this->table[i][j].getValue();
                    cout << ") ";
                }
                cout << endl;
            }
        }
};