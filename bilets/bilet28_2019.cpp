#include <iostream>
using namespace std;

//task1
/* Написати функцію, яка переміщує найбільший елемент списку у кінець. 
Список заданий однозв'язним представленням */

//task2
/* Написати функцію для знаходження номера рядка матриці з максимальною кількістю 0 
елементів у розрідженої матриці В[20,50] при стислому зв'язному зберіганні */

//task3
/* Множина цілих чисел представлена деревом двійкового пошуку. Написати нерекурсивну функцію, 
що записує у масив цю множину чисел впорядковану за зростанням */

//task1
void moveMaxToEnd(ListNode*& head) {
    if (!head || !head->next) 
        return;

    stackNode* current = head;
    stackNode* maxNode = head;
    stackNode* prevMax = NULL;
    stackNode* prev = NULL;

    // Знайти найбільший елемент і його попередник
    while (current) {
        if (current->value > maxNode->value) {
            maxNode = current;
            prevMax = prev;
        }
        prev = current;
        current = current->next;
    }

    if (maxNode->next == NULL)
        return;

    if (prevMax)
        prevMax->next = maxNode->next;
    else 
        head = head->next;

    current = head;
    while (current->next) 
        current = current->next;
  
    current->next = maxNode;
    maxNode->next = NULL;
}
