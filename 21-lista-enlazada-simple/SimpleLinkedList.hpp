#include <iostream>
using namespace std;

template <class T>
class NodeSLL{
    public:
        T data;
        NodeSLL* next;

        NodeSLL(){
            this->next = NULL;
        }

        NodeSLL(T data){
            this->data = data;
            this->next = NULL;
        }
};

template <class T>
class SimpleLinkedList{
    private:
        NodeSLL<T>* head;
    public:
        SimpleLinkedList(){
            this->head = NULL;
        }

        void insert(T data);
        void print();
        //void delete();
};

template <class T>
void SimpleLinkedList<T>::insert(T data){
    // Creando nuevo nodo
    NodeSLL<T>* newNode = new NodeSLL<T>(data);

    // En caso la lista este vacia
    if(this->head == NULL){
        this->head = newNode;
        return; // Finaliza la ejecucion del metodo
    }

    // Cuando hay elementos en la lista
    NodeSLL<T>* temp = this->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    // Ya ubicado en el final, inserto el nuevo nodo
    temp->next = newNode;
}

template <class T>
void SimpleLinkedList<T>::print(){
    NodeSLL<T>* temp = head;

    // En caso este vacia la lista
    if(this->head == NULL){
        cout << "Lista vacia" << endl;
        return;
    }
    
    // En caso la lista tenga elementos
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}