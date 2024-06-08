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

//task2
// Додавання вузла в стек
void pushStack(StackNode** head, StackNode** tail, TreeNode* treeNode) {
    StackNode* newNode = new StackNode;
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        newNode->next = *tail;
        *tail = newNode;
    }
}

// Видалення вузла зі стека
void popStack(StackNode** head, StackNode** tail) {
    if (*tail == NULL) 
	    return;
    StackNode* temp = *tail;
    *tail = (*tail)->next;
    if (*tail == NULL) 
	    *head = NULL;
    delete temp;
}

// Функція для зворотного проходження дерева
void traverseReverse(TreeNode* root, StackNode** head, StackNode** tail) {
    if (root == NULL) 
	    return;
    StackNode* stack = NULL;
    pushStack(&stack, &stack, root);

    while (stack) {
        TreeNode* currentNode = stack->treeNode;
        popStack(&stack, &stack);
        pushStack(head, tail, currentNode);
        if (currentNode->left != NULL) 
            pushStack(&stack, &stack, currentNode->left);
        if (currentNode->right != NULL) 
            pushStack(&stack, &stack, currentNode->right);
    }
}

// Функція для друкування відміток вузлів у зворотному порядку
void printReverse(TreeNode* root) {
    StackNode* head = NULL;
    StackNode* tail = NULL;
    traverseReverse(root, &head, &tail);
    while (tail) {
        cout << tail->treeNode->value << ", ";
        popStack(&head, &tail);
    }
    cout << endl;
}

//task3
void DFS(grph graph, int vertex, bool visited[10]) { //assuming graph has 10 vertices
    visited[vertex - 1] = true;
    Node* temp = graph.arr[vertex - 1];
    while (temp) {
        if (!visited[temp->num - 1])
            DFS(graph, temp->num, visited);
        temp = temp->next;
    }
}

// Функція для виведення досяжних вершин з даної вершини
void reachableVertices(grph graph, int startVertex, bool visited[10]) {
    DFS(graph, startVertex, visited);
    cout << "The vertices reachable from vertex " << startVertex << " are: ";
    for (int i = 0; i < 10; i++) {
        if (visited[i]) {
            cout << i + 1 << ", ";
        }
    }
    cout << endl;
}
