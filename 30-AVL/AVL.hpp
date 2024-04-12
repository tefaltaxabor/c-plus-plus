#include <algorithm>
#include <functional>

using namespace std;

template <class T>
class NodeAVL{
    public:
        T data;
        NodeAVL<T>* left;
        NodeAVL<T>* right;
        int height;
        NodeAVL(T data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
            this->height = 0;
        }
        NodeAVL(){
            this->left = NULL;
            this->right = NULL;
            this->height = 0;
        }
        ~NodeAVL(){}
};

template <class T>
class AVL{
    private:
        NodeAVL<T>* root;
        void (*process)(T); // Generalmente utilizado para display
        void _inOrder(NodeAVL<T>* node){
            if(node == NULL){
                return;
            }else{
                _inOrder(node->left);
                process(node->data);
                _inOrder(node->right);
            }
        }
         void _preOrder(NodeAVL<T>* node){
            if(node == NULL){
                return;
            }else{
                process(node->data);
                _preOrder(node->left);
                _preOrder(node->right);
            }
        }
         void _postOrder(NodeAVL<T>* node){
            if(node == NULL){
                return;
            }else{
                _postOrder(node->left);
                _postOrder(node->right);
                process(node->data);
            }
         }
         int _height(NodeAVL<T>* node){
            if(node == NULL){ // Caso conocido
                return -1;
            }else{ // Casos recursivos
                int height_left, height_right;
                height_left = 1 + _height(node->left);
                height_right = 1 + _height(node->right);
                if(height_left > height_right){
                    return height_left;
                }else{
                    return height_right;
                }
            }  
        }
         bool _insert(NodeAVL<T>* &node, T data, function<int(T, T)> criteria){
            if(node == NULL){
                node = new NodeAVL<T>(data);
                node->data = data;
            }else if(criteria(data, node->data) == -1){ //if(data < node->data){ // Si es menor se sigue por izquierda
                return _insert(node->left, data, criteria);
            }else if(criteria(data, node->data) == 1){ //if(data > node->data){ // Si es mayor se sigue por la derecha
                return _insert(node->right, data, criteria);
            }else{
                return false;
            }
            // Balaceo AVL
            this->_balance(node);
            return true;
        }
        
        // Rotaciones
        void _rotateRight(NodeAVL<T>* &node){
            NodeAVL<T>* n = node->left;
            node->left = n->right;
            n->right = node;
            node = n; // Se chanca el node
            // Actualizar altura
            node->right->height = _height(node->right);
            node->height =  1 + max(node->left->height, node->right->height);
        }
        
        void _rotateLeft(NodeAVL<T>* &node){
            NodeAVL<T>* n = node->right;
            node->right = n->left;
            n->left = node;
            node = n; // Se chanca el node
            // Actualizar altura
            node->left->height = _height(node->left);
            node->height =  1 + max(node->left->height, node->right->height);
        }

        void _balance(NodeAVL<T>* &node){
            int h_left = _height(node->left);
            int h_right = _height(node->right);
            int bf = h_right - h_left;
            if(bf < -1){ // Esta desbalanceado a la izquierda
                // Se valida si necesita o no una rotacion previa
                int hh_left = _height(node->left->left);
                int hh_right = _height(node->left->right);
                if(hh_left < hh_right){ // Se requiere rotacion doble
                    _rotateLeft(node->left);
                }
                // Rotacion a la derecha
                _rotateRight(node);
            }else if(bf > 1){ // Esta desbalanceado a la derecha
                // Se valida si necesita o no una rotacion previa
                int hh_left = _height(node->right->left);
                int hh_right = _height(node->right->right);
                if(hh_left > hh_right){ // Se requiere rotacion doble
                    _rotateRight(node->right);
                }
                // Rotacion a la derecha
                _rotateLeft(node);
            }
            // Actualizacion de las alturas de los nodos
            h_left = _height(node->left);
            h_right = _height(node->right);
            node->height = 1+max(h_left, h_right);
            
        }
    public:
        AVL(void(*process)(T)){
            this->process = process;
            this->root = NULL;
        }
        ~AVL(){}
        void inOrder(){
            return _inOrder(this->root);
        }
        void preOrder(){
            return _preOrder(this->root);
        }
        void postOrder(){
            return _postOrder(this->root);
        }
        bool insert(T data, function<int(T, T)> criteria){
            return _insert(this->root, data, criteria);
        }
        int height(){
            return this->_height(this->root);
        }
};