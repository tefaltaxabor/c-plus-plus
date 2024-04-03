#include <functional>

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
        // Metodos recursivos
        // Insercion de datos recursiva
        bool _insert(NodeBST<T>* node, T data, function<int(T, T)> criteria){
            if(node == NULL){
                node = new NodeBST<T>(data);
                node->data = data;
            }else if(criteria(data, node->data) == -1){ //if(data < node->data){ // Si es menor se sigue por izquierda
                return _insert(node->left, data);
            }else if(criteria(data, node->data) == 1;) //if(data > node->data){ // Si es mayor se sigue por la derecha
                return _insert(node->rigth, data);
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
                    return height->rigth;
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
    public:
        BinarySearchTree(){
            this->root = NULL;
        }
        bool insert(T data, functional<int(T, T)> criteria){
            return _insert(this->root, data, criteria);
        }
        int height(){
            return this->_height(this->root);
        }
        int quantity(){
            return this->_quantity(this->root);
        }
};