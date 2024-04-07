#include <functional>
#include <iostream>
using namespace std;

template <class T>
class NodeBST{
    public:
        T data;
        NodeBST<T>* left;
        NodeBST<T>* rigth;
        NodeBST(T data){
            this->data = data;
            this->left = NULL;
            this->rigth = NULL;
        
        }
        NodeBST(T data, NodeBST<T>* left, NodeBST<T> rigth){
            this->data = data;
            this->left = left;
            this->rigth = rigth;
        }
        ~NodeBST(){
            delete this->left;
            delete this->rigth;
        }
        
};

template <class T>
class BinarySearchTree{
    private:
        // Atributos
        NodeBST<T>* root;
        void (*process)(T); // Puntero a funcion
        // Metodos recursivos
        // Insercion de datos recursiva
        bool _insert(NodeBST<T>* &node, T data, function<int(T, T)> criteria){
            if(node == NULL){
                node = new NodeBST<T>(data);
                node->data = data;
            }else if(criteria(data, node->data) == -1){ //if(data < node->data){ // Si es menor se sigue por izquierda
                return _insert(node->left, data, criteria);
            }else if(criteria(data, node->data) == 1){ //if(data > node->data){ // Si es mayor se sigue por la derecha
                return _insert(node->rigth, data, criteria);
            }else{
                return false;
            }
            return true;
        }
        // Calculo de altura recursivo
        int _height(NodeBST<T>* node){
            if(node == NULL){ // Caso conocido
                return 0;
            }else{ // Casos recursivos
                int height_left, height_rigth;
                height_left = 1 + _height(node->left);
                height_rigth = 1 + _height(node->rigth);
                if(height_left > height_rigth){
                    return height_left;
                }else{
                    return height_rigth;
                }
            }  
        }
        // Calculo de cantidad recursivo
        int _quantity(NodeBST<T>* node){
            if(node == NULL){ // Caso conocido
                return 0;
            }else{ // Casos recursivos
                int quantity_left, quantity_rigth;
                quantity_left = _quantity(node->left);
                quantity_rigth = _quantity(node->rigth);
                return 1 + quantity_left + quantity_rigth;
            }  
        }
        void _inOrder(NodeBST<T>* node){
            if(node == NULL){
                return;
            }else{
                _inOrder(node->left);
                process(node->data);
                _inOrder(node->rigth);
            }
        }
         void _preOrder(NodeBST<T>* node){
            if(node == NULL){
                return;
            }else{
                process(node->data);
                _preOrder(node->left);
                _preOrder(node->rigth);
            }
        }
         void _postOrder(NodeBST<T>* node){
            if(node == NULL){
                return;
            }else{
                _postOrder(node->left);
                _postOrder(node->rigth);
                process(node->data);
            }
        }
        bool _search(NodeBST<T>* &node, T data, function<int(T, T)> criteria){
            if(node == NULL){ // Nodo hoja
                return false;
            }else if(criteria(data, node->data) == 0){ // Se encontro el valor en el nodo actual
                return true;
            }else if(criteria(data, node->data) == -1){ //if(data < node->data){ // Si es menor se sigue por izquierda
                return _search(node->left, data, criteria);
            }else if(criteria(data, node->data) == 1){ //if(data > node->data){ // Si es mayor se sigue por la derecha
                return _search(node->rigth, data, criteria);
            }
        }
        void _display(string prefix, NodeBST<T>* node, bool isLeft){
            if(node != NULL){
                cout << prefix; // Se muestra el prefijo
                if(isLeft == true){ // Si es izquierdo
                    cout << "|--";
                    cout << node->data << endl; // Se muestra la data
                    _display(prefix+"|   ", node->rigth, false);
                    _display(prefix+"|   ", node->left, true);
                    
                }else{
                    cout << "'--";
                    cout << node->data << endl; // Se muestra la data
                    _display(prefix+"    ", node->rigth, false);
                    _display(prefix+"    ", node->left, true);
                    
                }
            }
        }
    public:
        BinarySearchTree(){
            this->root = NULL;
        }
        void setProcess(void(*functionPointer)(T)){
            this->process = functionPointer;
        }
        bool insert(T data, function<int(T, T)> criteria){
            return _insert(this->root, data, criteria);
        }
        bool search(T data, function<int(T, T)> criteria){
            return _search(this->root, data, criteria);
        }
        int height(){
            return this->_height(this->root);
        }
        int quantity(){
            return this->_quantity(this->root);
        }
        void inOrder(){
            return _inOrder(this->root);
        }
        void preOrder(){
            return _preOrder(this->root);
        }
        void postOrder(){
            return _postOrder(this->root);
        }
        void display(NodeBST<T>* node){
            _display("", node, false);
        }
        void display(){
            _display("", this->root, false);
        }
};