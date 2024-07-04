#include "q.hpp"

/// Aufgabe 2
void Queue::enqueue(int x) {
    this->stack1.push(x);
}

int Queue::dequeue() {
    if(isEmpty()){
        
    }
}

bool Queue::isEmpty() {
    return stack1.empty() && stack2.empty();
}

void printQueue(Queue q) {
    printf("<- ");
    while(!q.isEmpty()) {
        printf("%d ", q.dequeue());
    }
    printf(" <-\n");
}

int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(9);
    q.enqueue(10);
    printQueue(q);
    
}