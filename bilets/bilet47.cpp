#include <iostream>
using namespace std;

// task 1
/* Написати функцію для впорядкування за зростаючим порядком елементів списку у
зв'язному зберіганні, використовуючи «сортування вибором». */

// task 2
/* Використовуючи відповідний механізм черг або стеків, написати функцію, яка виводить
відмітки вузлів бінарного дерева, поданого у стандартній формі, по рівнях (починаючи з
кореня дерева, далі з синів кореня й далі). */

// task 3
/* Написати функцію, яка перевіряє суміжність двох заданих вершин у неорієнтованому
графі, що поданий структурою суміжності. */

//task1
void selectionSort(DoublyLinkedList& list) {
    // Отримуємо головний вузол списку
    Node* head = list.getHead();
    if (head == NULL) 
        return;
    Node* start = head;
    while (start) {
        Node* minNode = start;
        Node* current = start->next;
        while (current) {
            if (current->data < minNode->data)
                minNode = current;
            current = current->next;
        }
        if (minNode != start) {
            int temp = start->data;
            start->data = minNode->data;
            minNode->data = temp;
        }
        start = start->next;
    }
}

//task2
struct q{
	q* next;
	node* nd;
};

void qAdd(q** head, q** tail, node* nod){
	q* temp = new q;
	temp->next = NULL;
	temp->nd = nod;
	(*tail)->next = temp;
	*tail = temp;
}

void qDel(q** head, q** tail){
	q* temp = *head;
	if (*head == *tail)
		*tail = NULL;
	*head = (*head)->next;
	delete temp;
}

void printByLevel (node* root){
	q* head;
	q* tail;
	head = new q;
	head->next = NULL;
	head->nd = root;
	tail = head;	
	while (head) {
		if (head->nd->left)
			qAdd(&head, &tail, head->nd->left);
		if (head->nd->right)
			qAdd(&head, &tail, head->nd->right);			
		cout << head->nd->data<<"; ";
		qDel(&head, &tail);	
	}
}

//task3
bool areVerticesAdjacent(grph& graph, int ver1, int ver2) {
    node* temp = graph.arr[ver1 - 1];
    while (temp) {
        if (temp->num == ver2)
            return true;
        temp = temp->next;
    }
    return false;
}
