#include <iostream>
using namespace std;

//task1
/* Поліном від однієї змінної з цілими коефіцієнтами можна подати зв'язним списком, 
впорядкованим за зростанням степені змінної, без зберігання одночленів із з нульовими 
коефіцієнтами. Написати функцію, яка виводить степінь полінома */

//task2
/* Написати функцію для реалізації поелементного додавання двох розріджених матриць,
при послідовно-зв'язному індексному зберіганні */

//task3
/* Написати функцію для вилучення вузла зі значенням v дерева бінарного пошуку, 
якщо таке значення у ньому присутнє */

//task1
struct Node {
    int coefficient; 
    int exponent;    
    Node* next;      
};

int getPolynomialDegree(Node* head) {
    if (head == NULL) 
        return -1;
    
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    return temp->exponent;
}

//task2
struct Node {
    int value;
    int row;
    int col;
    Node* prev;
    Node* next;
};

struct MatrixRow {
    Node* nodes;
    MatrixRow* next;
};

void addNode(Node** head, Node** tail, int value, int row, int col) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->row = row;
    newNode->col = col;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (*head) {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    } else {
        *head = newNode;
        *tail = *head;
    }
}

void addMatrices(MatrixRow* matA, MatrixRow* matB, MatrixRow** resultHead, MatrixRow** resultTail) {
    while (matA || matB) {
        Node* nodeA = NULL;
        Node* nodeB = NULL;
        if (matA) nodeA = matA->nodes;
        if (matB) nodeB = matB->nodes;
        Node* resHead = NULL;
        Node* resTail = NULL;
        MatrixRow* newRow = new MatrixRow;

        while (nodeA || nodeB) {
            if (nodeA && nodeB && nodeA->row == nodeB->row && nodeA->col == nodeB->col) {
                addNode(&resHead, &resTail, nodeA->value + nodeB->value, nodeA->row, nodeA->col);
                nodeA = nodeA->next;
                nodeB = nodeB->next;
            } else if (nodeB && (!nodeA || (nodeA->row > nodeB->row || (nodeA->row == nodeB->row && nodeA->col > nodeB->col)))) {
                addNode(&resHead, &resTail, nodeB->value, nodeB->row, nodeB->col);
                nodeB = nodeB->next;
            } else {
                addNode(&resHead, &resTail, nodeA->value, nodeA->row, nodeA->col);
                nodeA = nodeA->next;
            }
        }

        newRow->nodes = resHead;
        newRow->next = NULL;
        if (*resultHead) {
            (*resultTail)->next = newRow;
            *resultTail = newRow;
        } else {
            *resultHead = newRow;
            *resultTail = *resultHead;
        }

        if (matA) matA = matA->next;
        if (matB) matB = matB->next;
    }
}

//task3
void DeleteV(node** root, int number, node** prev) {
	if(!(*root))
		return;

	if ((*root)->num == number) {
		node* temp = (*root);
		if ((*root)->left == NULL && (*root)->right == NULL) {
			if (*prev) {
				if ((*prev)->left == (*root))
					(*prev)->left == NULL;
				else
					(*prev)->right = NULL;
			}
			delete temp;
		}
		else if ((*root)->left && (*root)->right) {
			node* iter = (*root)->right;
			node* previter = NULL;
			while (iter->left) {
				previter = iter;
				iter = iter->left;
			}
			(*root)->num = iter->num;
			if ((*prev) == NULL)
				(*root)->right = (*root)->right->right;
			if(previter)
				previter->left = NULL;
			if ((*root)->right == iter)
				if ((*root)->right->right)
					(*root)->right = (*root)->right->right;
				else
					(*root)->right = NULL;
			delete iter;
		}
		else {
			if ((*prev)->left == (*root)) {
				if ((*root)->left)
					(*prev)->left = (*root)->left;
				else
					(*prev)->left = (*root)->right;
			}
			else {
				if ((*root)->left)
					(*prev)->right = (*root)->left;
				else
					(*prev)->right = (*root)->right;
			}
			delete temp;
		}
		return;
	}
	(*prev) = (*root);
	if ((*root)->num > number )
		DeleteV(&((*root)->left), number, prev);
	else 
		DeleteV(&((*root)->right), number, prev);
}
