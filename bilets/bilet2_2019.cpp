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

//task2 
/* Використовуючи відповідний механізм черг або стеків, написати функцію, яка виводить 
відмітки вузлів бінарного дерева, поданого у "стандартній формі", 
по рівнях (починаючи з кореня дерева, далі з синів кореня й далі) */

struct node {
    int num;
    node* left;
    node* right;
};

struct stackTreeElement {
    stackTreeElement* next;
    node* treeNode;
};

void stackTreeAdd(stackTreeElement** tail, node* treeNode) {
    stackTreeElement* temp = new stackTreeElement;
    temp->next = NULL;
    temp->treeNode = treeNode;

    if (*tail) {
        (*tail)->next = temp;
    }
    *tail = temp;
}

void stackTreeDelete(stackTreeElement** head, stackTreeElement** tail) {
    stackTreeElement* temp = *head;
    if (*head == *tail) {
        *tail = NULL;
    }
    *head = (*head)->next;
    delete temp;
}

void stackTreeShow(node* root) {
    if (!root) return;

    stackTreeElement* head = new stackTreeElement;
    head->next = NULL;
    head->treeNode = root;
    stackTreeElement* tail = head;

    bool firstElement = true; // To handle comma placement

    while (head) {
        node* currentNode = head->treeNode;
        if (!firstElement) {
            cout << ", ";
        }
        cout << currentNode->num;
        firstElement = false;

        if (currentNode->left)
            stackTreeAdd(&tail, currentNode->left);
        if (currentNode->right)
            stackTreeAdd(&tail, currentNode->right);

        stackTreeDelete(&head, &tail);
    }
    cout << endl;
}

//task3 
/* Написати функцію для знаходження середнього арифметичного елементів
розрідженої матриці В[20,50] при послідовно-зв'язному індексному зберіганні */

double findMiddleElement (matrix* headM) {
    double number = 0;
    int count;
	while (headM) {
		listI* temp = headM->list;
		while (temp) {
			number += temp->num;
            count++;
			temp = temp->left;
		}
		headM = headM->next;
	}
    if (number != 0)
    	return (number / count);
    return 0;
}
