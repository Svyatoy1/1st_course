#include <iostream>
using namespace std;

// task 1
/* В елементах звʼязного циклічного списку розміщені цілі числа. Написати функцію, що 
впорядковує список, збираючи спочатку всі непарні числа, а потім - парні. */

// task 2
/* Написати не рекурсивну функцію (з використанням стека) для друкування відміток вузлів 
бінарного дерева, поданого у «стандартній формі», при його проходженні у «оберненому порядку». */

// task 3
/* Знайти всі вершини графа, що поданий структурую суміжності, які досяжні від заданої вершини. */

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

//task 2
struct Node {
    int value;
    Node* left;
    Node* right;
};

struct NodeStack {
    Node* node;
    NodeStack* next;
};

void addNodeInStack(NodeStack** stack, Node* node) {
    NodeStack* newStackNode = new NodeStack;
    newStackNode->node = node;
    newStackNode->next = *stack;
    *stack = newStackNode;
}

Node* pop(NodeStack** stack) {
    if (*stack == NULL) {
        return NULL;
    }
    NodeStack* topNode = *stack;
    Node* treeNode = topNode->node;
    *stack = topNode->next;
    delete topNode;
    return treeNode;
}

void reversePostOrder(Node* root) {
    if (root == NULL) 
        return;
        
    NodeStack* stack1 = NULL;
    NodeStack* stack2 = NULL;

    addNodeInStack(&stack1, root);

 // обхід дерева в оберненому порядку
    while (stack1) {
        Node* node = pop(&stack1);
        addNodeInStack(&stack2, node);
        if (node->left) 
            addNodeInStack(&stack1, node->left);
        if (node->right) 
            addNodeInStack(&stack1, node->right);
	}
	
	// вивід порядку вузлів
    while (stack2) {
        Node* node = pop(&stack2);
        cout << node->value << " ";
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
