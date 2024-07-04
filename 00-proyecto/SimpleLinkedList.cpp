template <class T>
SimpleLinkedList<T>::~SimpleLinkedList(){
    while(this->head){
        NodeSLL<T>* next = this->head->next;
        delete this->head;
        this->length--;
        this->head = next;
    }
}

template <class T>
void SimpleLinkedList<T>::insertHead(T data){
    // Creando nuevo nodo cuyo next sea el head
    NodeSLL<T>* newNode = new NodeSLL<T>(data, this->head);
    // Se agrega el nuevo nodo al inicio
    this->head = newNode;
    this->length++;
    return; // Finaliza la ejecucion del metodo
}

template <class T>
void SimpleLinkedList<T>::insertPos(T data, int pos){
    // En caso sea una posicion invalida
    if(pos<0 || pos>this->length) return;
    if(pos == 0){
        this->insertHead(data);
    }else{
        NodeSLL<T>* temp = this->head;
        for(int i=0; i<pos; i++){
            temp = temp->next;
        }
        NodeSLL<T>* newNode = new NodeSLL<T>(data, temp->next);
        temp->next = newNode;
        this->length++;
    }
    
}

template <class T>
void SimpleLinkedList<T>::insertEnd(T data){
    this->insertPos(data, this->length);
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

template <class T>
T SimpleLinkedList<T>::getByPos(int pos){
    if(0<=pos && pos<this->length){
        NodeSLL<T>* temp = this->head;
        for(int i=0; i<pos; i++){
            temp = temp->next;
        }
        return temp->data;
    }
}

template <class T>
int SimpleLinkedList<T>::getLength(){
    return this->length;

}
/*
template <class T>
int SimpleLinkedList<T>::search(T d, function<int(T, T)> cmp){
    NodeSLL<T>* temp = this->head;
    int pos = 0;
    while(temp != NULL){
        if(cmp(temp->data, d) == 0){ // Comparacion por criterio lambda
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}
*/
template <class T>
void SimpleLinkedList<T>::update(T data, int pos){
    NodeSLL<T>* temp = this->head;
    int i = 0;
    if(0<=pos && pos<=this->length){ // Se valida la posicion
        while(temp != NULL){
            if(i == pos){ // Comparacion de posiciones
                temp->data = data;
                return; // Termina la ejecucion del metodo
            }
            temp = temp->next;
            i++;
        }
    }
}

template <class T>
void SimpleLinkedList<T>::deleteByPos(int pos){
    
    
    if(0<=pos && pos<=this->length){ // Se valida la posicion
        if(pos == 0){
            NodeSLL<T>* aux = this->head; // Se crea el aux para liberar la memoria luego
            this->head = this->head->next; // Se actualiza el head
            delete aux; // Se libera el espacio de memoria reservado para el antiguo head
        }else{
            NodeSLL<T>* temp = this->head;
            int i = 0;
            while(temp != NULL){
                if(i == pos-1){ // Nos ubicamos en la posicion pos-1
                    NodeSLL<T>* aux = temp->next; // Se crea el aux para liberar la memoria luego
                    temp->next = aux->next;
                    delete aux;
                    return; // Termina la ejecucion del metodo
                }
                temp = temp->next;
                i++;
            }
        }
        
    }
}