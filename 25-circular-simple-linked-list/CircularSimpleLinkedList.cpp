template <class T>
void CircularSimpleLinkedList<T>::~SimpleLinkedList(){
    while(this->head){
        NodeDLL<T>* next = this->head->next;
        delete this->head;
        this->length--;
        this->head = next;
    }
}

template <class T>
void CircularSimpleLinkedList<T>::insertHead(T data){
    // Creando nuevo nodo cuyo next sea el head
    NodeSLL<T>* newNode = new NodeSLL<T>(data, this->head);
    // Se agrega el nuevo nodo al inicio
    this->head = newNode;
    this->tail->next = this->head;
    this->length++;
    return; // Finaliza la ejecucion del metodo
}

template <class T>
void CircularSimpleLinkedList<T>::insertPos(T data, int pos){
    // En caso sea una posicion invalida
    if(pos<0 || pos>this->length) return;
    if(pos == 0){
        this->insertHead(data);
    }else if(pos == this>length){
        this->insertTail(data);
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
void CircularSimpleLinkedList<T>::insertEnd(T data){
    this->insertPos(data, this->length);
}

template <class T>
void CircularSimpleLinkedList<T>::print(){
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
T CircularSimpleLinkedList<T>::getByPos(int pos){
    if(0<=pos && pos<this->length){
        NodeSLL<T>* temp = this->head;
        for(int i=0; i<pos; i++){
            temp = temp->next;
        }
        return temp->data;
    }
}

template <class T>
int CircularSimpleLinkedList<T>::getLength(){
    return this->length;

}

template <class T>
int CircularSimpleLinkedList<T>::search(T d, function<int(T, T)> cmp){
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

template <class T>
void CircularSimpleLinkedList<T>::insertTail(T data){
    // Creando nuevo nodo cuyo next sea el head
    NodeSLL<T>* newNode = new NodeSLL<T>(data, this->head);
    // Se agrega el nuevo nodo al inicio
    this->tail->next = newNode;
    this->tail = newNode;
    this->length++;
    return; // Finaliza la ejecucion del metodo
}