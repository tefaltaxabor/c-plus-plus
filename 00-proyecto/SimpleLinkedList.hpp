#include <iostream>
#include <functional>
using namespace std;

template <class T>
class NodeSLL{
    public:
        T data;
        NodeSLL* next;

        NodeSLL(){
            this->next = NULL;
        }

        NodeSLL(T data, NodeSLL* next = NULL){
            this->data = data;
            this->next = next;
        }
};

template <class T>
class SimpleLinkedList{
    private:
        NodeSLL<T>* head;
        int length;
        
    public:
        SimpleLinkedList(){
            this->head = NULL;
            this->length = 0;
            
        }
        ~SimpleLinkedList();
        // CRUD/Create
        void insertHead(T data);
        void insertPos(T data, int pos);
        void insertEnd(T data);
        // CRUD/Read
        T getByPos(int pos);
        void print();
        int getLength();
        //int search(T d, function<int(T, T)> cmp);
        // CRUD/Update
        void update(T data, int pos);
        // CRUD/Delete
        void deleteByPos(int pos);
        //void delete();
};

#include "SimpleLinkedList.cpp"



