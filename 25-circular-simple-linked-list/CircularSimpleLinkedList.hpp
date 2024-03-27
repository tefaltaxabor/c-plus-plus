#include <iostream>
#include <functional>
using namespace std;

template <class T>
class NodeCSLL{
    public:
        T data;
        NodeCSLL* next;

        NodeCSLL(){
            this->next = NULL;
        }

        NodeCSLL(T data, NodeCSLL* next = NULL){
            this->data = data;
            this->next = next;
        }
};

template <class T>
class CircularSimpleLinkedList{
    private:
        NodeCSLL<T>* head;
        NodeCSLL<T>* tail;
        int length;
        
    public:
        CircularSimpleLinkedList(){
            this->head = NULL;
            this->tail = NULL;
            this->length = 0;
            
        }
        void ~CircularSimpleLinkedList();
        void insertHead(T data);
        void insertTail(T data);
        void insertPos(T data, int pos);
        void insertEnd(T data);
        T getByPos(int pos);
        void print();
        int getLength();
        int search(T d, function<int(T, T)> cmp);
        //void delete();
};

#include "CircularSimpleLinkedList.cpp"



