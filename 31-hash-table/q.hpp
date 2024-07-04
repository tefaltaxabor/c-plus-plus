#include <stack>

using std::stack;

class Queue { //qiu
    stack<int> stack1, stack2;

public:

    void enqueue(int x);

    int dequeue();

    bool isEmpty();
};

void printQueue(Queue q);

void sortedInsert(stack<int>& st, int val);

void stackSort(stack<int>& st);

std::string stackString(stack<int> st);

void printStack(stack<int>& st);