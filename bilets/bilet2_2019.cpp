#include <iostream>
using namespace std;

//task1
/* Написати функцію для впорядкування елементів однозв'язного списку за зростанням */

nodeStack* insertionSort(nodeStack* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    nodeStack* sorted = NULL;
    nodeStack* current = head;

    while (current) {
        nodeStack* next = current->next;

        if (sorted == NULL || current->num < sorted->num) {
            current->next = sorted;
            sorted = current;
        } else {
            nodeStack* temp = sorted;
            while (temp->next != NULL && temp->next->num < current->num) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}
