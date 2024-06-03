#include <iostream>
using namespace std;

void AddElementInList(list** head, list** teil, int number) {
	list* temp = new list;
	temp->num = number;
	if (*head) {
		(*head)->right = temp;
		(*teil)->left = temp;
		temp->left = (*head);
		temp->right = (*teil);
		(*teil) = temp;
	} else {
		(*teil) = temp;
		(*head) = (*teil);
		(*head)->left = (*teil);
		(*head)->right = (*teil);
		(*teil)->left = (*head);
		(*teil)->right = (*head);
	}
}

void CopyList(list* head, list* teil, list** headc, list** teilc) {
	do {
		AddOB(headc, teilc, teil->num);
		teil = teil->right;
	} while 
      (teil != head->right);
}
