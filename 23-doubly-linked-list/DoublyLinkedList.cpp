// NodeDLL implementacion

template <class T>
NodeDLL<T>::NodeDLL(T data){
    this->data = data;
}

template <class T>
T NodeDLL<T>::getData(){
    return this->data;
}

template <class T>
NodeDLL<T>::~NodeDLL(){}

// DoublyLinkedList implementacion

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}   

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    while(this->head){
        NodeDLL<T>* next = this->head->next;
        delete this->head;
        this->length--;
        this->head = next;
    }
}

template <class T>
int DoublyLinkedList<T>::getLength(){
    return this->length;
}   

template <class T>
T DoublyLinkedList<T>::getHead(){
    return this->head;
}
template <class T>
T DoublyLinkedList<T>::getTail(){
    return this->tail;
}

template <class T>
void DoublyLinkedList<T>::insertAsTail(T data){
    NodeDLL<T>* newNode = new NodeDLL<T>(data); // prev y next NULL
    if(this->head == NULL){
        this->head = newNode;
        this->tail = this->head;
        this->length++;
    }else{
        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
        this->length++;
    }
}

template <class T>
void DoublyLinkedList<T>::insertAsHead(T data){
    NodeDLL<T>* newNode = new NodeDLL<T>(data); // prev y next NULL
    if(this->head == NULL){
        this->head = newNode;
        this->tail = this->head;
        this->length++;
    }else{
        this->head->prev = newNode;
        newNode->next = this->head;
        this->head = newNode;
        this->length++;
    }
}  

template <class T>
void DoublyLinkedList<T>::insertPos(T data, int pos){
    // En caso sea una posicion invalida
    if(pos<0 || pos>this->length) return;
    if(pos == 0){
        this->insertAsHead(data);
        
    }else if (pos == this->length) {
        this->insertAsTail(data);
    }else {
        NodeDLL<T>* temp = this->head;
        for(int i=0; i<pos; i++){
            temp = temp->next;
        }
        NodeDLL<T>* newNode = new NodeDLL<T>(data);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
        length++;
    }
    
}

template <class T>
T DoublyLinkedList<T>::getByPos(int pos){
    if(pos == 0){
        return this->head;
    }else if(pos == this->length-1){
        return this->tail;
    }else if(pos < this->length/2){
        NodeDLL<T>* temp = this->head;
        int i=0;
        while(temp != NULL){
            if(i == pos){
                return temp->data;
            }else{
                i++;
                temp = temp->next;
            }
        }
    }else{
        NodeDLL<T>* temp = this->tail;
        int i=this->length - 1;
        while(temp != NULL){
            if(i == pos){
                return temp->data;
            }else{
                i--;
                temp = temp->prev;
            }
        }
    }
}  
//Impresion normal : {head ; next ; next ; .. ; tail}
template <class T>
void DoublyLinkedList<T>::print(){
    NodeDLL<T>* temp = this->head;
    while(temp != NULL){
        cout << temp->getData() << endl;
        temp = temp->next;
    }
}  
//Impresion inversa: {tail ; prev ; prev ; .. ; head}
template <class T>
void DoublyLinkedList<T>::printReverse(){
    NodeDLL<T>* temp = this->tail;
    while(temp != NULL){
        cout << temp->getData() << endl;
        temp = temp->prev;
    }
}  