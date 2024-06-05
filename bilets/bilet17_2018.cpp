#include <iostream>
using namespace std;

//task1 
/* В елементах списку, що представляється у двозв'язному представленні, розміщені цілі числа. 
Написати функцію копіювання списку, помінявши порядок елементів на обернений */

//task1
Node* createNode(int num) {
    Node* newNode = new Node();
    newNode->num = num;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* copyReversed(Node* head) {
    Node* newHead = NULL;
    Node* newTail = NULL;
    
    Node* temp = head;
    while (temp) {
        Node* newNode = createNode(temp->num);
        newNode->next = newHead;
        if (newHead) 
            newHead->prev = newNode;
        newHead = newNode;
        if (newTail == NULL)
            newTail = newHead;
        temp = temp->next;
    }
    return newHead;
}
