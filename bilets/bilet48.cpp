#include <iostream>
using namespace std;

// task 1
/* В елементах «звʼязного циклічного списку» розміщені цілі числа. Написати
функцію, що розбиває множину поданих чисел на дві: з парними та непарними
значеннями, використовуючи для множин представлення «звʼязними циклічними
списками». */

// task 2
/* Написати функцію для перетворення виразу з цілих чисел та операцій «-», «/»,
записаного у звичайній «інфіксній формі» у представлення в формі ПОЛІЗ.
Потрібний стек реалізувати власноруч. */

// task 3
/* Написати функцію, яка для графа визначає всі вершини, відстань яких від заданої
вершини v становить d. Граф представлений «структурою суміжності». */

//task1
struct list {
	int num;
	list* left;
	list* right;
};

void Add(list** head, list** tail, int number) {
	list* temp = new list;
	temp->num = number;
	if (*head) {
		(*tail)->left = temp;
		(*head)->right = temp;
		temp->right = (*tail);
		temp->left = (*head);
		(*tail) = temp;
	}
	else {
		temp->left = temp;
		temp->right = temp;	
		(*head) = temp;
		(*tail) = (*head);
	}
}

void connection (list** head1, list** tail1, list** head2, list** tail2) {
	if ((*head1)->right != (*tail2)) {
		(*head1)->right->left = (*head1)->left;
		(*head1)->left->right = (*head1)->right;
	} else {
		(*tail1)->left = (*head1)->left;
		(*head1)->left = (*tail1);
	}
	Add(head2, tail2, (*head1)->num);
}

void breaks(list** head_neparni, list** tail_neparni, list** head_parni, list** tail_parni) {
	if ((*head_neparni)->num % 2 == 0) {
		do {
			if ((*head_neparni)->num % 2 != 0) 
				connection (head_neparni, tail_neparni, head_parni, tail_parni);
			(*head_neparni) = (*head_neparni)->left;

		} while ((*tail_neparni)->left != (*head_neparni));
	}
	else {
		do {
			if ((*head_neparni)->num % 2 == 0) 
				connection (head_neparni, tail_neparni, head_parni, tail_parni);
			(*head_neparni) = (*head_neparni)->left;

		} while ((*tail_neparni)->left != (*head_neparni));
	}
}
