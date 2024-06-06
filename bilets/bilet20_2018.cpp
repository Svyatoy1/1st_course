#include <iostream>
using namespace std;

//task1
/* В елементах циклічного списку розміщені цілі числа. Написали функцію, що перевпорядковує список, 
збираючи спочатку всі від'ємні числа, потім - 0, а потім додатні */

//task1
void reorderList(Node** head) {
    if (!head || !*head) {
        return;
    }

    Node* negHead = NULL, *negTail = NULL;
    Node* zeroHead = NULL, *zeroTail = NULL;
    Node* posHead = NULL, *posTail = NULL;
    Node* current = *head;

    do {
        Node* next = current->next;
        if (current->data < 0) {
            if (!negHead) {
                negHead = negTail = current;
            } else {
                negTail->next = current;
                negTail = current;
            }
        } else if (current->data == 0) {
            if (!zeroHead) {
                zeroHead = zeroTail = current;
            } else {
                zeroTail->next = current;
                zeroTail = current;
            }
        } else {
            if (!posHead) {
                posHead = posTail = current;
            } else {
                posTail->next = current;
                posTail = current;
            }
        }
        current = next;
    } while (current != *head);

    // Connect the three lists
    if (negTail) {
        negTail->next = zeroHead ? zeroHead : posHead;
    }
    if (zeroTail) {
        zeroTail->next = posHead;
    }
    if (posTail) {
        posTail->next = negHead ? negHead : zeroHead;
    }

    // Set new head
    if (negHead) {
        *head = negHead;
    } else if (zeroHead) {
        *head = zeroHead;
    } else {
        *head = posHead;
    }

    // Make the list circular again
    Node* temp = *head;
    while (temp->next && temp->next != *head) {
        temp = temp->next;
    }
    temp->next = *head;
}
