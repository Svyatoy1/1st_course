#include <iostream>
using namespace std;

//task1 
/* Стек S у зв'язному зберіганні містить цілі числа. Створити два стеки S1 та S2,
   перемістивши до першого всі парні числові значення, а до другого - непарні,
   зберігаючи попередній взаємний порядок*/

struct nodeStack{
	int num; 
	nodeStack* next;
};

void addNode (int value, nodeStack** head, nodeStack** tail){
	nodeStack* temp = new nodeStack;
	temp->num = value;
	if ((*head)==NULL){
		(*head) = temp;
		(*tail) = (*head);
		(*tail)->next = NULL;
	}
	else {
		temp->next = *head;	
		*head = temp;
	}
}

void colaps (nodeStack* head, nodeStack* tail, nodeStack** head1, nodeStack** tail1, nodeStack** head2, nodeStack** tail2){
	if (!head)
		return;
  	colaps (head->next, tail, head1, tail1, head2, tail2);
  	if (head->num % 2 == 0)
  		addNode (head->num, head1, tail1);
  	else
   		addNode (head->num, head2, tail2);
}

//task2 
/* Написати функцію для знаходження значення мінімального елемента розрідженої матриці
   В[20,50] при послідовно-зв'язному індексному зберіганні*/

// Структура для представлення елемента в рядку
struct listI {
    int num;
    listI* next;
};

// Структура для представлення рядка в матриці
struct matrix {
    listI* list;
    matrix* next;
};

int searchMinElement (matrix* headM){
	int min = headM->list->num;
	while (headM){
		listI* temp = headM->list;
		while (temp){
			if (temp->num < min)
				min = temp->num;
			temp = temp->next;
		}
		headM = headM->next;
	}
	if (min>0)
		return min;
	else
		return 0;
}
