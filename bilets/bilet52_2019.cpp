#include <iostream>
using namespace std;

//task1
/* В елементах зв'язного циклічного списку розміщені цілі числа. Напсиати функцію,
що впорядковує список, збираючи спочатку всі непарні числа, а потім - парні*/

//task2
/* Написати нерекурсивну функцію (з використанням стека) для друкування відміток вузлів 
бінарного дерева, поданого у стандартній формі, при його проходженні у оберненому порядку */

//task3
/* Знайти всі вершини графа, що поданий структурою суміжності, які досяжні від заданої вершини */

//task1
void sortCycleList(list** head, list** tail) {
	list* start = (*head);
	list* end = (*tail);
	do {
		if ((*head)->num % 2 == 0) {
			list* temp = (*head);
			if ((*head)->right == (*tail)) {
				start = (*head)->left;
				(*tail) = temp;
			}
			else {
				(*head)->left->right = (*head)->right;
				(*head)->right->left = (*head)->left;
				(*head) = temp->left;
				(*tail)->left = temp;
				temp->right = (*tail);
				temp->left = start;
				(*tail) = temp;
			}
		}
		(*head) = (*head)->left;
	} while ((*head) != end);
  
	(*head) = start;
}
