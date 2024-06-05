#include <iostream>
using namespace std;

//task1
/* В елементах двозв'язного списку розміщені цілі числа. Написати функцію, що вилучає 
всі елементи з мінімальним значенням */

//task2
/* Список F з цілих чисел, більшість елементів якого дорівнює 0, представлений своїм зв'язним зберіганням. 
Написати функцію для представлення F стислим зв'язним зберіганням */

//task3
/* Написати функцію для визначення кількості входження елементів із значеннями з інтервалу 
[u,v] до невпорядкованого бінарного дерева, що зберігається у стандартній формі */

//task4
/* Написати функцію для вставки вузла зі значенням v у дерево бінарного пошуку, 
якщо таке значення у ньому відсутнє */

//task5
/* Написати функцію, яка визначає кількість висячих вершин неорієнтованого графа, поданого структурою суміжності */

//task1
// Функція для знаходження мінімального значення в списку
int findMin(Node* head) {
    if (!head) 
        return;
    int minVal = head->data;
    Node* current = head->next;
    while (current) {
        if (current->data < minVal)
            minVal = current->data;
        current = current->next;
    }
    return minVal;
}

// Функція для видалення вузла зі списку
void deleteNode(Node** head, Node* del) {
    if (*head == NULL || del == NULL)
        return;

    if (*head == del)
        *head = del->next;

    if (del->next)
        del->next->prev = del->prev;

    if (del->prev)
        del->prev->next = del->next;

    delete del;
}

// Функція для видалення всіх елементів із мінімальним значенням
void deleteMinElements(Node** head) {
    if (*head == NULL) return;

    int minVal = findMin(*head);
    Node* current = *head;

    while (current) {
        Node* next = current->next;
        if (current->data == minVal)
            deleteNode(head, current);
        current = next;
    }
}

//task2
void fromListToCompactList(list* head, cListNode** cHead, cListNode** cTail) {
    list* current = head;
    int index = 0;

    while (current) {
        if (current->num != 0) {
            cListNode* newNode = new cListNode();
            newNode->index = index;
            newNode->num = current->num;
            newNode->left = NULL;
            newNode->right = NULL;

            if (!*cHead) {
                *cHead = newNode;
                *cTail = newNode;
            } else {
                (*cTail)->right = newNode;
                newNode->left = *cTail;
                *cTail = newNode;
            }
        }
        current = current->right;
        index++;
    }
}

//task3
int countInRange(Node* root, int u, int v) {
    if (root == NULL) 
        return 0;
    
    int count = 0;
    if (root->num >= u && root->num <= v) 
        count = 1;
    
    return count + countInRange(root->left, u, v) + countInRange(root->right, u, v);
}

//task4
// Функція для створення нового вузла
node* createNode(int number) {
    node* newnode = new node;
    newnode->num = number;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Функція для перевірки, чи містить дерево значення v
bool containsNode(node* root, int v) {
    if (!root) return false;
    if (root->num == v) return true;
    if (v < root->num) 
        return containsNode(root->left, v);
    return containsNode(root->right, v);
}

// Функція для вставки вузла зі значенням v, якщо його немає в дереві
void addNode(node*& root, int number) {
    if (!containsNode(root, number)) {
        if (!root) {
            root = createNode(number);
        } else if (number < root->num) {
            if (root->left) {
                addNode(root->left, number);
            } else {
                root->left = createNode(number);
            }
        } else {
            if (root->right) {
                addNode(root->right, number);
            } else {
                root->right = createNode(number);
            }
        }
    }
}
