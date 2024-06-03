#include <iostream>
using namespace std;

//task1
/* В елементах циклічного списку розміщені цілі числа. Написати функцію копіювання списку, 
помінявши порядок елементів на оберенений*/

//task 2
/* До лінійного списку F з m цілих чисел, більшість елементів якого дорівнюють 0,
   застосоване "стисле зв'язне зберігання". Написати функцію для визначення кількості
   елементів зі значенням 0, номери яких належать інтервалу [i,j]. */

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
