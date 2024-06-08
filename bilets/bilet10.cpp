#include <iostream>
using namespace std;

//task1
/* Поліном від однієї змінної з цілими коефіцієнтами можна подати зв'язним списком, 
впорядкованим за зростанням степені змінної, без зберігання одночленів із з нульовими 
коефіцієнтами. Написати функцію, яка реалізує обчислення похідної від поліному */

//task1
struct list {
    int num; // coefficient
    int step; // exponent
    list* left; // previous node
    list* right; // next node
};

void derivativePolynom(list** head, list** tail) {
    list* current = (*head);
    while (current) {
        current->num *= current->step;
        current->step--;
        list* next = current->right;
        if (current->step < 0) {
            if (current->left)
                current->left->right = current->right;
            else
                *head = current->right; // Якщо видаляємо перший елемент, оновлюємо голову списку
            }
            if (current->right)
                current->right->left = current->left;
            else
                *tail = current->left; // Якщо видаляємо останній елемент, оновлюємо хвіст списку
            delete current;
        }
        current = next;
    }
}
