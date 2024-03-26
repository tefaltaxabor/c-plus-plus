template <class T>
class NodeDLL{
    private:
        T data; // value, info
    public:
        NodeDLL<T>* next;
        NodeDLL<T>* prev;
        // Prototipos
        NodeDLL(T data);
        ~NodeDLL();
        T getData();
};

template <class T>
class DoublyLinkedList{
    private:
        NodeDLL<T>* head;
        NodeDLL<T>* tail;
        int length;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        int getLength(); // size()
        T getHead();
        T getTail();
        void insertAsTail(T data);
        void insertAsHead(T data);
        void getByPos(int pos);
        void print();
        void printReverse();
};

#include <DoublyLinkedList.cpp>