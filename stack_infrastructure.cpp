#include <iostream>
using namespace std;

struct nodeStack{
	int num; 
	nodeStack* next;
};

void addNode (int value, nodeStack** head){
	nodeStack* temp = new nodeStack;
	temp->num = value;
	temp->next = *head;	
	*head = temp;
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
