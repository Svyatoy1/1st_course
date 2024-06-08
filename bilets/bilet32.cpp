#include <iostream>
using namespace std;

// task 1
/* Поліном від однієї змінної з цілими коефіцієнтами можна подати звʼязним списком, 
впорядкованим за зростанням степені змінної, без зберігання одночленів з нульовими 
коефіцієнтами. Написати функцію, яка знаходить суму двох поліномів. */

// task 2
/* Написати не рекурсивну функцію для друкування відміток вузлів бінарного дерева, поданого у «стандартній формі», 
при його проходженні у «порівневому порядку» (корінь, сини, сини синів, ...). */

// task 3
/* Написати функцію, яка вилучає всі петлі «псевдо графа», поданого «структурою 
суміжності». */

//task1
struct list {
	int num;
	int step;
	list* left;
	list* right;
};

void AddSum(list** head, list** tail, int number, int cont) {
	list* temp = new list;
	temp->num = number;
	temp->left = NULL;
	
	if (*head) {
		temp->power = cont;
		(*tail)->left = temp;
		temp->right = (*tail);
		(*tail) = temp;
	} else {
		temp->power = cont;
		(*head) = temp;
		(*tail) = (*head);
		(*head)->right = NULL;
	}
}

void sumPol(list** head, list** tail, list* head1, list* tail1, list* head2, list* tail2) {
	while (head1 || head2) {
		if (head1->power == head2->power){
			AddSum(head, tail, head1->num + head2->num,head1->power);
			head1 = head1->left;
			head2 = head2->left;
		}
		if (head1->power > head2->power) {
			AddSum(head, tail, head2->num, head2->power);
			head2 = head2->left;
		}
		if (head1->power < head2->power) {
			AddSum(head, tail, head1->num, head1->power);
			head1 = head1->left;
		}
	}
}

//task2
// Вузол бінарного дерева
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

// Вузол черги
struct QueueNode {
    TreeNode* treeNode;
    QueueNode* next;
};

// Черга для рівневого обходу
struct Queue {
    QueueNode* front;
    QueueNode* rear;
};

// Ініціалізація черги
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Додавання вузла до черги
void enqueue(Queue* q, TreeNode* node) {
    QueueNode* newNode = new QueueNode;
    newNode->treeNode = node;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Видалення вузла з черги
TreeNode* dequeue(Queue* q) {
    if (q->front == NULL)
        return NULL;
    TreeNode* treeNode = q->front->treeNode;
    QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    delete temp;
    return treeNode;
}

// Перевірка на порожність черги
bool isEmpty(Queue* q) {
    return q->front == NULL;
}

// Функція для рівневого обходу дерева та друкування значень вузлів
void printLevelOrder(TreeNode* root) {
    if (root == NULL) 
        return;
    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        TreeNode* current = dequeue(&q);
        cout << current->value << " ";
	    
        if (current->left)
            enqueue(&q, current->left);
        if (current->right)
            enqueue(&q, current->right);
    }
    cout << endl;
}

//task3
void deletePseudograph(grph* graph, int N) {
    for (int i = 0; i < N; i++) {
        node* temp = graph->arr[i];
        node* prev = NULL;
        while (temp) {
            if (temp->num == i + 1) {
                node* comp = temp;
                if (prev)
                    prev->next = temp->next;
                else {
                    temp = temp->next;
                    graph->arr[i] = temp;
                }
                delete comp;
            }
            prev = temp;
            temp = temp->next;
        }
    }
}
