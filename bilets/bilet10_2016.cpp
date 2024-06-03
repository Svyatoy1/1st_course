#include <iostream>
using namespace std;

void AddElementInList(list** head, list** tail, int number) {
	list* temp = new list;
	temp->num = number;
	if (*head) {
		(*head)->right = temp;
		(*tail)->left = temp;
		temp->left = (*head);
		temp->right = (*tail);
		(*tail) = temp;
	} else {
		(*tail) = temp;
		(*head) = (*tail);
		(*head)->left = (*tail);
		(*head)->right = (*tail);
		(*tail)->left = (*head);
		(*tail)->right = (*head);
	}
}

void CopyList(list* head, list* tail, list** headc, list** tailc) {
	do {
		AddElementInList(headc, tailc, tail->num);
		tail = tail->right;
	} while 
      (tail != head->right);
}
