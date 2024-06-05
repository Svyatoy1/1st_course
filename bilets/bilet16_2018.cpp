#include <iostream>
using namespace std;

//task1
/* В елементах двозв'язного списку розміщені цілі числа. Написати функцію, що вилучає 
всі елементи з мінімальним значенням */

//task2
/* Список F з цілих чисел, більшість елементів якого дорівнює 0, представлений своїм зв'язним зберіганням. 
Написати функцію для представлення F стислим зв'язним зберіганням */

//task1
// Функція для знаходження мінімального значення в списку
int findMin(Node* head) {
    if (!head) 
        return;
    int minVal = head->data;
    Node* current = head->next;
    while (current) {
        if (current->data < minVal)
            minVal = current->data;
        current = current->next;
    }
    return minVal;
}

// Функція для видалення вузла зі списку
void deleteNode(Node** head, Node* del) {
    if (*head == NULL || del == NULL)
        return;

    if (*head == del)
        *head = del->next;

    if (del->next)
        del->next->prev = del->prev;

    if (del->prev)
        del->prev->next = del->next;

    delete del;
}

// Функція для видалення всіх елементів із мінімальним значенням
void deleteMinElements(Node** head) {
    if (*head == NULL) return;

    int minVal = findMin(*head);
    Node* current = *head;

    while (current) {
        Node* next = current->next;
        if (current->data == minVal)
            deleteNode(head, current);
        current = next;
    }
}

//task2
void fromListToCompactList(list** head, list** tail) {
	list* start = (*head);
	while (*head) {
		if ((*head)->num == 0) {
			list* temp = (*head);
			if ((*head)->right == NULL) {
				start = (*head)->left;
				(*head) = (*head)->left;
				(*head)->right = NULL;
				delete temp;
			}
			else if ((*head)->left == NULL) {
				(*tail) = (*tail)->right;
				(*tail)->left = NULL;
				(*head) = (*tail);
				delete temp;
			} 
            else {
				(*head)->left->right = (*head)->right;
				(*head)->right->left = (*head)->left;
				(*head) = (*head)->left;
				delete temp;
			}
		}
		(*head) = (*head)->left;
	}
	(*head) = start;
}
