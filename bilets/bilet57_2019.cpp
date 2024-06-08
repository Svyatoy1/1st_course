#include <iostream>
using namespace std;

//task1
/* Написати функцію, яка вилучає з списку у зв'язному представленні всі вузли, 
розташовані у позиціях кратних 5 */

//task2
/* Написати функцію для перетворення виразу з цілих чисел та операцій "+", "*", 
записаного у звичайній інфіксній формі у представленні форми ПОЛІЗ. 
Потрібний стек реалізуват власноруч */

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

//task2
struct poliz {
	char element;
	poliz* next;
};

void polizAdd(poliz** head, char el) {
	poliz* adder = new poliz;
	adder->element = el;
	adder->next = (*head);
	(*head) = adder;
}

char getElement(poliz** head) {
	char element = (*head)->element;
	poliz* temp = (*head);
	(*head) = (*head)->next;
	delete temp;
	return element;
}

void initPoliz(char in[100], char out[100]) {
	poliz* head = NULL;
	int i = 0;
	int j = 0;

	while (in[i]) {
		while (in[i] && (in[i] != '-' && in[i] != '/')) {
			out[j] = in[i];
			i++; 
			j++;
		}
		out[j] = ' ';
		j++;
		if (in[i]) {
			while (head && (head->element == '/' || (head->element == in[i]))) {
				out[j] = getElement(&head);
				j++;
			}
			polizAdd(&head, in[i]);
			i++;
		}
	}

	while (head){
		out[j] = getElement(&head);
		j++;
	}
}
