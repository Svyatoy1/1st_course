#include <iostream>
using namespace std;

// task 1
/* Написати функцію для впорядкування за зростаючим порядком елементів списку у
зв'язному зберіганні, використовуючи «сортування вибором». */

// task 2
/* Використовуючи відповідний механізм черг або стеків, написати функцію, яка виводить
відмітки вузлів бінарного дерева, поданого у стандартній формі, по рівнях (починаючи з
кореня дерева, далі з синів кореня й далі). */

// task 3
/* Написати функцію, яка перевіряє суміжність двох заданих вершин у неорієнтованому
графі, що поданий структурою суміжності. */

//task1
void selectionSort(DoublyLinkedList& list) {
    // Отримуємо головний вузол списку
    Node* head = list.getHead();
    if (head == NULL) 
        return;
    Node* start = head;
    while (start) {
        Node* minNode = start;
        Node* current = start->next;
        while (current) {
            if (current->data < minNode->data)
                minNode = current;
            current = current->next;
        }
        if (minNode != start) {
            int temp = start->data;
            start->data = minNode->data;
            minNode->data = temp;
        }
        start = start->next;
    }
}
