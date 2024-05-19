#include <iostream>
using namespace std;

// functions for infrastructure

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

void showStack (nodeStack* head){
	nodeStack* temp = head;
	while (temp){
	    cout << temp->num << endl;
		temp = temp->next;
	}
}

void delStack (nodeStack** head){
	while (head){
		nodeStack* tempDel = *head;
		*head = (*head)->next;
		delete tempDel;
	}
}

int main () {
	nodeStack* head = NULL;
	for (int i = 0; i<10; i++){
		addNode (i, &head);
	}
	
	showStack (head);
	delStack (&head);	
	return 0;
}
