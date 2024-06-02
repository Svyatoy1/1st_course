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

struct st
{
	stecT* next;
	node* node;
};

void stecTADD(stecT** teil,node* node)
{
	stecT* temp = new stecT;
	temp->next = NULL;
	temp->node = node;
	(*teil)->next = temp;
	(*teil) = temp;
}

void stecTDell(stecT** head,stecT** teil)
{
	stecT* temp = (*head);
	if ((*head) == (*teil))
	{
		(*teil) = NULL;
	}
	(*head) = (*head)->next;
	delete temp;
}

void StecTShow(node* root)
{
	stecT* head = new stecT;
	head->next = NULL;
	head->node = root;
	stecT* teil = head;

	while (head)
	{
		if (head->node->left)
			stecTADD(&teil, head->node->left);
		if (head->node->right)
			stecTADD(&teil, head->node->right);
		cout << head->node->num << ", ";
		stecTDell(&head, &teil);
	}

}
