#include <iostream>
using namespace std;

//task1 
/* В елементах зв'язного списку розміщені різні цілі числа. Написати функцію, що роздруковує
   значення елементів, розміщених між найменшим та найбільшим елементами списку */

void printElementsBetweenMinAndMax(Node* head){
    Node* current = head;
    int minIndex = 0;
    int maxIndex = 0;
    int currentIndex = 0;
    Node *minNode = head;
    Node *maxNode = head;

    while (current) {
        if (current->data < minNode->data) {
            minNode = current;
            minIndex = currentIndex;
        } else if (current->data > maxNode->data) {
            maxNode = current;
            maxIndex = currentIndex;
        }
        currentIndex++;
        current = current->next;
    }

    Node* startFrom;
    Node* endBy;
    if (maxIndex > minIndex) {
        startFrom = minNode;
        endBy = maxNode;
    } else {
        startFrom = maxNode;
        endBy = minNode;
    }
    Node* currentToPrint = startFrom;

    while (currentToPrint != endBy->next){
        cout << currentToPrint->data << "->";
        currentToPrint = currentToPrint->next;
    }
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
	stackTree* next;
	node* node;
};

void stackTreeAdd(stackTreeElement** tail,node* node)
{
	stackTreeElement* temp = new stackTreeElement;
	temp->next = NULL;
	temp->node = node;
	(*tail)->next = temp;
	(*tail) = temp;
}

void stackTreeDelete(stackTreeElement** head, stackTreeElement** tail)
{
	stackTreeElement* temp = (*head);
	if ((*head) == (*tail))
	{
		(*tail) = NULL;
	}
	(*head) = (*head)->next;
	delete temp;
}

void stackTreeShow(node* root)
{
	stackTreeElement* head = new stackTreeElement;
	head->next = NULL;
	head->node = root;
	stackTreeElement* tail = head;

	while (head) {
		if (head->node->left)
			stackTreeAdd(&tail, head->node->left);
		if (head->node->right)
			stackTreeAdd(&tail, head->node->right);
		cout << head->node->num << ", ";
		stackTreeDelete(&head, &teil);
	}

}
