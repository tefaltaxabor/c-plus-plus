#include <iostream>

using namespace std;

template <class T>
class NodeQueue{
    public:
        T data;
        NodeQueue<T>* next;

        NodeQueue(T data){
            this->data = data;
            this->next = NULL;
        }
        ~NodeQueue(){}
};

template <class T>
class Queue{
    private:
        NodeQueue<T>* front;
        NodeQueue<T>* back;
        int length;
    public:
        Queue(){
            this->back = NULL;
            this->front = this->back;
            this->length = 0;
        }
        ~Queue(){}

        int size(){
            return this->length;
        }

        T getFront(){
            return this->front->data;
        }

        T getBack(){
            return this->back->data;
        }

        bool empty(){
            if(this->size() ==0) return true;
            else return false;
        }

        void push(T data){ // Encolar
            // Se crea un temporal
            NodeQueue<T>* temp = new NodeQueue<T>(data);

            // Si la cola esta vacia, el nuevo nodo seria el front y back a la vez
            if(this->front == NULL){
                this->back = temp;
                this->front = this->back;
                this->length ++;
                return;
            }else{ // Sino se agrega el nuevo nodo al final de la cola (se actulaiza back)
                this->back->next = temp; // El next de vigente backl es el nuevo nodo
                this->back = temp; // Se actualiza el back con el nuevo nodo
                this->length ++;
            }
        }

        void pop(){
            // Si la cola esta vacia
            if(this->front == NULL){
                cout << "La cola esta vacia" << endl;
                return;
            }else{
                // Almacenamos el nodo front y luego lo reemplazamos por su next
                T data = this->front->data; // Se lamacena para mostrar (si fuese necesario)
                NodeQueue<T>* temp = this->front;
                this->front = this->front->next;

                // Si el front es null, el de atras lo debe ser tambien (cola vacia)
                if(this->front == NULL){
                    this->back = NULL;
                }

                // Se libera memoria
                delete (temp);
                this->length --;
                cout << "Se decolo " << data << endl;
            }
        }
        void display(){
            if(this->empty() == false){
                NodeQueue<T>* temp = this->front;
                while(temp != NULL){
                    cout << temp->data << " -> ";
                    temp = temp->next;
                }
                cout << "NULL" << endl;
            }else{
                cout << "No hay elementos en la cola" << endl;
            }
        }
};