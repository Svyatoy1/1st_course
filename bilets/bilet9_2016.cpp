#include <iostream>
using namespace std;

//task1
/* Многочлен від однієї змінної з цілими коефіцієнтами можна подати зв'язним списком, 
впорядкованим за зростанням степені змінної, без зберігання одночленів з нульовими
коефіцієнтами. Написати функцію, яка реалізує обчислення похідної від многочлена */

//task1
struct list {
    int num; // коефіцієнт
    int step; // степінь
    list* left; // попередній елемент
    list* right; // наступний елемент
};

void deleteNode(list** node, list** head, list** tail) {
    list* temp = *node;
    if (temp->left) {
        temp->left->right = temp->right;
    } else {
        *head = temp->right;
    }
    if (temp->right) {
        temp->right->left = temp->left;
    } else {
        *tail = temp->left;
    }
    *node = temp->right;
    delete temp;
}

void findDerivative(list** head, list** tail) {
    list* current = *head;
    while (current) {
        current->num *= current->step;
        current->step--;
        if (current->step < 0) {
            deleteNode(&current, head, tail);
        } else {
            current = current->right;
        }
    }
}
