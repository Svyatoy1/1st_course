#include <iostream>
using namespace std;

//task1 
/* В елементах списку, що представляється у двозв'язному представленні, розміщені цілі числа. 
Написати функцію копіювання списку, помінявши порядок елементів на обернений */

//task2
/* До лінійного списку F з m цілих чисел, більшість елементів якого дорівнюють 0, 
застосоване стисле зв'язне зберігання. Написати функцію для визначення кількості 
невід'ємних елементів списку F, номери яких належать інтервалу [i,j] */

//task 3
/* Написати функцію для перевірки входження значення а до елементів невпорядкованого
бінарного дерева, що зберігається у стандартній формі */

//task 4
/* Написати функцію для визначення найбільшого значення у вузлах непорожнього
дерева бінарного пошуку, що менше за v */

//task1
Node* createNode(int num) {
    Node* newNode = new Node();
    newNode->num = num;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* copyReversed(Node* head) {
    Node* newHead = NULL;
    Node* newTail = NULL;
    
    Node* temp = head;
    while (temp) {
        Node* newNode = createNode(temp->num);
        newNode->next = newHead;
        if (newHead) 
            newHead->prev = newNode;
        newHead = newNode;
        if (newTail == NULL)
            newTail = newHead;
        temp = temp->next;
    }
    return newHead;
}

//task2
int countNonNegative(Node* head, int i, int j) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        if (temp->index >= i && temp->index <= j && temp->value >= 0)
            count++;
        temp = temp->next;
    }
    return count;
}

//task3
bool findNodeOfBinaryTree(node* root, int num) {
    if (!root) return false;

    if (root->num == num) {
        cout << "Number: " << root->num << ", level: " << *height << endl;
        return true;
    }

    bool foundInLeft = findNodeOfBinaryTree(root->left, num);
    if (foundInLeft) return true;

    bool foundInRight = findNodeOfBinaryTree(root->right, num);
    if (foundInRight) return true;
	
    return false;
}

//task 4
int findMaxLessThanV(node* root, int v) {
    int maxVal = -1; // Початкове значення, яке вказує на відсутність результату
    while (root) {
        if (root->num < v) {
            maxVal = root->num;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return maxVal;
}
