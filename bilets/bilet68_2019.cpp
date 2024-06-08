#include <iostream>
using namespace std;

//task1
/* Многочлен від трьох змінних з цілими коефіцієнтами можна подати зв'язним списком, 
впорядкованим за зростанням степенів змінних, без зберігання одночленів з нульовими коефіцієнтами. 
Написати функцію, яка обчислює значення многочлена при заданих значеннях змінних */

//task2
/* Написати кількість, яка визначає кількість внутрішніх вершин бінарного дерева, що представлено у стандартній формі */


//task1
//infrastructure to understand
struct polynom {
	int num;
	char var;
	int step;
	polynom* next;
};

void addElement(polynom** head, polynom** tail, int number, int step, char Var){
	polynom* temp = new polynom;
	temp->num = number;
	temp->var = Var;
	temp->step = step;
	temp->next = NULL;
	if ((*head) == NULL) {
		(*head) = temp;
		(*tail) = (*head);
	}
	else {
		(*tail)->next = temp;
		(*tail) = temp;
	}
}

void initPolynom(polynom** head, polynom** tail, int arrX[], int arrY[], int arrZ[], int size) {
	int i = 0;
	int j = 0;
	int k = 0;
	char X = 'x';
	char Y = 'y';
	char Z = 'z';
	while (i <= size || j<= size || k<= size) {
		if (i<=j || i<=k) {
			if(arrX[i] != 0)
				addElement(head, tail, arrX[i], i, X);
			i++;
		}
		if (j<i || j <k) {
			if (arrY[j] != 0)
				addElement(head, tail, arrY[j], j, Y);
			j++;
		}
		if (k<i || k <j) {
			if (arrZ[k] != 0)
				addElement(head, tail, arrZ[k], k, Z);
			k++;
		}
	}
}

//MAIN FUNCTION
int sumFromPolynoms(polynom* head, polynom* tail, int X, int Y, int Z) {
	int sum = 0;
	while (head) {
		if (head->var == 'x')
			sum += head->num * (pow(X, head->step));
		if (head->var == 'y')
			sum += head->num * (pow(Y, head->step));
		if (head->var == 'z')
			sum += head->num * (pow(Z, head->step));
		head = head->next;
	}
	return sum;
}
