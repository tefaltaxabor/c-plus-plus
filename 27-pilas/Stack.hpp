#include <iostream>

using namespace std;

template <class T>
class NodeStack{
    public:
        T data;
        NodeStack<T>* next;

        NodeStack<T>(){}
        NodeStack<T>(T data, NodeStack<T>* next){
            this->data = data;
            this->next = next;
        }
        ~NodeStack<T>(){}// Agregar destructor
};

template <class T>
class Stack{
    private:
        NodeStack<T>* head;
        int length; // Tamanho de la pila
        int elements; // Numero de elementos apilados
    public:
        Stack(int length){
            this->head = NULL;
            this->length = length;
            this->elements = 0;
        }
        void setHead(NodeStack<T>* head){this->head = head;}
        void setLength(int length){this->length = length;}
        void setElements(int elements){this->elements = elements;}

        ~Stack(){}// Agregar destructor

        bool isFull(){
            if(this->length == this-> elements) return true;
            else return false;
        }
        bool isEmpty(){
            if(this->elements == 0) return true;
            else return false;
        }
        T top(){
            return this->head;
        }
        void push(T data){
            if(this->isFull() == false){
                NodeStack<T>* temp = new NodeStack<T>(data, this->head);
                this->head = temp;
                this->elements++;
            }else{
                cout << "La pila esta llena" << endl;
            }
        }
        void pop(){
            if(this->isEmpty() == false){
                NodeStack<T>* temp = this->head;
                this->head = this->head->next;
                temp->next = NULL;
                delete temp;
                this->elements--;
            }else{
                cout << "La pila esta vacia" << endl;
            }
        }

        int size(){
            return this->length;
        }

        void resize(int length){
            this->length = length;
        }

        void display(){
            if(this->isEmpty() == false){
                NodeStack<T>* temp = this->head;
                while(temp != NULL){
                    cout << temp->data << endl;
                    cout << " |" << endl;
                    cout << " V " << endl;
                    temp = temp->next;
                }
                cout << "NULL" << endl;
            }else{
                cout << "No hay elementos en la pila" << endl;
            }
            
            
        }
        
};