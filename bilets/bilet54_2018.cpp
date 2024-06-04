#include <iostream>
using namespace std;

//task1
/* Многочлен від однієї змінної з цілими коефіцієнтами можна подати зв'язним списком, 
впорядкованим за зростанням степені змінної, без зберігання одночленів із з нульовими 
коефіцієнтами. Написати функцію, яка виводить степінь многочлена */

//task 2
/* До лінійного списку F з m цілих чисел, більшість елементів якого дорівнюють 0,
   застосоване стисле зв'язне зберігання. Написати функцію для визначення номера
   першого за порядком елемента списку F із значенням 0 */

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

//task2
int findFirstZero(Node* head, int m) {
    int currentIndex = 1; //numeration starts from 1
    Node* temp = head;
    
    while (temp && currentIndex < m) {
        if (temp->index == currentIndex) 
            temp = temp->next;
         else 
            return currentIndex;
        currentIndex++;
    }
    
    if (currentIndex < m) 
        return currentIndex; //if we reach end of list, we return index of -1 unless we find zeros
     else 
        return -1;
}
