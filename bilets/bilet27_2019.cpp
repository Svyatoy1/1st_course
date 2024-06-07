#include <iostream>
using namespace std;

//task1
/* Поліном від однієї змінної з цілими коефіцієнтами можна подати зв'язним списком, 
впорядкованим за зростанням степені змінної, без зберігання одночленів із з нульовими 
коефіцієнтами. Написати функцію, яка виводить степінь полінома */

//task1
struct Node {
    int coefficient; 
    int exponent;    
    Node* next;      
};

int getPolynomialDegree(Node* head) {
    if (head == NULL) 
        return -1;
    
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    return temp->exponent;
}
