#include <iostream>
using namespace std;

// task 1
/* Поліном від однієї змінної з цілими коефіцієнтами можна подати звʼязним списком, 
впорядкованим за зростанням степені змінної, без зберігання одночленів з нульовими 
коефіцієнтами. Написати функцію, яка знаходить суму двох поліномів. */

// task 2
/* Написати не рекурсивну функцію для друкування відміток вузлів бінарного дерева, поданого у «стандартній формі», 
при його проходженні у «порівневому порядку» (корінь, сини, сини синів, ...). */

// task 3
/* Написати функцію, яка вилучає всі петлі «псевдо графа», поданого «структурою 
суміжності». */

//task1
struct list {
	int num;
	int step;
	list* left;
	list* right;
};

void AddSum(list** head, list** tail, int number, int cont) {
	list* temp = new list;
	temp->num = number;
	temp->left = NULL;
	
	if (*head) {
		temp->power = cont;
		(*tail)->left = temp;
		temp->right = (*tail);
		(*tail) = temp;
	} else {
		temp->power = cont;
		(*head) = temp;
		(*tail) = (*head);
		(*head)->right = NULL;
	}
}

void sumPol(list** head, list** tail, list* head1, list* tail1, list* head2, list* tail2) {
	while (head1 || head2) {
		if (head1->power == head2->power){
			AddSum(head, tail, head1->num + head2->num,head1->power);
			head1 = head1->left;
			head2 = head2->left;
		}
		if (head1->power > head2->power) {
			AddSum(head, tail, head2->num, head2->power);
			head2 = head2->left;
		}
		if (head1->power < head2->power) {
			AddSum(head, tail, head1->num, head1->power);
			head1 = head1->left;
		}
	}
}
