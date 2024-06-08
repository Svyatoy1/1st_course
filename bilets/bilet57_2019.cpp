#include <iostream>
using namespace std;

//task1
/* Написати функцію, яка вилучає з списку у зв'язному представленні всі вузли, 
розташовані у позиціях кратних 5 */

//task2
/* Написати функцію, яка вилучає з списку у зв'язному представленні всі вузли, 
розташовані у позиціях кратних 5 */

//task1
struct listI {
	int num;
	int index;
	listI* left;
	listI* right;
};

void deleteNodeFromList(listI** head, listI** tail) {
	listI* temp = (*head);
	if ((*head) == (*tail)) {
		(*tail) = (*tail)->right;
		(*tail)->left = NULL;
		(*head) = (*tail);
	}
	else {
		(*head)->right->left = (*head)->left;
		(*head)->left->right = (*head)->right;
		(*head) = temp->left;
	}
	delete temp;
}


void deleteDivisibleByFive(listI** head, listI** tail) {
	listI* start = (*head);
	while (*head) {
		if (*head && ((*head)->index) % 5 == 0)
		    deleteNodeFromList(head, tail);
		(*head) = (*head)->left;
	}
	(*head) = start;
}
