#include <iostream>
using namespace std;

struct nodeStack{
	int num; 
	nodeStack* next;
};

void addNode (int value, nodeStack** head, nodeStack** tail){
	nodeStack* temp = new nodeStack;
	temp->num = value;
	if ((*head)==NULL){
		(*head) = temp;
		(*tail) = (*head);
		(*tail)->next = NULL;
	}
	else {
		temp->next = *head;	
		*head = temp;
	}
}

void colaps (nodeStack* head, nodeStack* tail, nodeStack** head1, nodeStack** tail1, nodeStack** head2, nodeStack** tail2){
	if (!head)
    return;
  colaps (head->next, tail, head1, tail1, head2, tail2);
  if (head->num % 2 == 0)
    addNode (head->num, head1, tail1);
  else
    addNode (head->num, head2, tail2);
}
