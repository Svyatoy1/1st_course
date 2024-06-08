#include <iostream>
using namespace std;

//task1
/* В елементах зв'язного циклічного списку розміщені цілі числа. Напсиати функцію,
що впорядковує список, збираючи спочатку всі непарні числа, а потім - парні*/

//task2
/* Написати функцію для знаходження номера рядка матриці з максимальною кількістю 0 
елементів у розрідженої матриці В[20,50] при стислому зв'язному зберіганні */

//task3
/* Множина цілих чисел представлена деревом двійкового пошуку. Написати нерекурсивну функцію, 
що записує у масив цю множину чисел впорядковану за зростанням */

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
