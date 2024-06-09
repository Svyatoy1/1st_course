#include <iostream>
using namespace std;

//task1
/* В елементах циклічного списку розміщені цілі числа. Написати функцію, 
що розбиває множину поданих чисел на дві: з парними та непарними значеннями, 
використовуючи для множин представлення циклічними списками*/

//task2
/* Лінійний список F цілих чисел зберігається як послідовно-зв'язний індексний список так, 
що числа, які мають 2 однакові останні цифри, розміщуються в один підсписок. Написати 
функцію, що обчислює кількість елементів списку F зі значенням v */

//task3
/* Написати не рекурсивну функцію (з використанням стека) для друкування відміток вузлів 
бінарного дерева поданого у стандартній формі, при його проходженні в оберненому порядку */

//task4
/* Написати функцію, щоб обчсилює суму числових значень у вершмнах дерева двійкового
пошуку більших за v */

//task5
/* Написати функцію, яка визначає кількість вершин степені 3 неорієнтованого графа, 
поданого структурою суміжності */


//task1
struct list {
	int num;
	list* left;
	list* right;
};

void Add(list** head, list** tail, int number) {
	list* temp = new list;
	temp->num = number;
	if (*head) {
		(*tail)->left = temp;
		(*head)->right = temp;
		temp->right = (*tail);
		temp->left = (*head);
		(*tail) = temp;
	}
	else {
		temp->left = temp;
		temp->right = temp;	
		(*head) = temp;
		(*tail) = (*head);
	}
}

void connection (list** head1, list** tail1, list** head2, list** tail2) {
	if ((*head1)->right != (*tail2)) {
		(*head1)->right->left = (*head1)->left;
		(*head1)->left->right = (*head1)->right;
	} else {
		(*tail1)->left = (*head1)->left;
		(*head1)->left = (*tail1);
	}
	Add(head2, tail2, (*head1)->num);
}

void breaks(list** head_neparni, list** tail_neparni, list** head_parni, list** tail_parni) {
	if ((*head_neparni)->num % 2 == 0) {
		do {
			if ((*head_neparni)->num % 2 != 0) 
				connection (head_neparni, tail_neparni, head_parni, tail_parni);
			(*head_neparni) = (*head_neparni)->left;

		} while ((*tail_neparni)->left != (*head_neparni));
	}
	else {
		do {
			if ((*head_neparni)->num % 2 == 0) 
				connection (head_neparni, tail_neparni, head_parni, tail_parni);
			(*head_neparni) = (*head_neparni)->left;

		} while ((*tail_neparni)->left != (*head_neparni));
	}
}

//task 2
struct NumberNode {
    int value;
    NumberNode* next;
};

struct IndexNode {
    int key; 
    IndexNode* next; 
    NumberNode* sublist; 
};

int countOccurrences(IndexNode* head, int value) {
    int key = value % 100; 

    IndexNode* current = head;
    while (current && current->key != key) 
        current = current->next;

    if (current == NULL) 
        return 0; // 
    
    NumberNode* sublist = current->sublist;
    int count = 0;
    while (sublist) {
        if (sublist->value == value) 
            count++;
        sublist = sublist->next;
    }
    return count;
}

//task 3
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
    if (*stack == NULL)
        return;

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

//task4
int sumGreaterThan(Node* root, int v) {
    if (root == NULL)
        return 0;

    int sum = 0;
    if (root->num > v) {
        sum += root->num;
        sum += sumGreaterThan(root->right, v);
        sum += sumGreaterThan(root->left, v);
    } else
        sum += sumGreaterThan(root->right, v);
	
    return sum;
}

//task5
int countDegreeThreeVertices(grph graph) {
    int count = 0;

    for (int i = 0; i < 8; i++) { //assuning graph has 8 vertices
        int degree = 0;
        node* temp = graph.arr[i];
        while (temp) {
            degree++;
            temp = temp->next;
        }
        if (degree == 3) 
            count++;
    } 
    return count;
}

int main() {
    // for testing task 3
    Node* root = new Node{1, NULL, NULL};
    root->left = new Node{2, NULL, NULL};
    root->right = new Node{3, NULL, NULL};
    root->left->left = new Node{4, NULL, NULL};
    root->left->right = new Node{5, NULL, NULL};
    root->right->left = new Node{6, NULL, NULL};
    root->right->right = new Node{7, NULL, NULL};

    reversePostOrder(root);

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
