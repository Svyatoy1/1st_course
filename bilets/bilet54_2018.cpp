#include <iostream>
using namespace std;

//task1
/* Многочлен від однієї змінної з цілими коефіцієнтами можна подати зв'язним списком, 
впорядкованим за зростанням степені змінної, без зберігання одночленів із з нульовими 
коефіцієнтами. Написати функцію, яка виводить степінь многочлена */

//task2
/* До лінійного списку F з m цілих чисел, більшість елементів якого дорівнюють 0,
   застосоване стисле зв'язне зберігання. Написати функцію для визначення номера
   першого за порядком елемента списку F із значенням 0 */

//task3
/* Написати функцію для визначення кількості вхдження елементів більших за а
до невпорядкованого бінарного дерева, що зберігається у стандартній формі */

//task4
/* Написати функцію для визначення найменшого значення у вузлах непорожнього дерева бінарного пошуку */

//task5
/* Написати функцію, яка визначає кількість ізольованих вершин неорієнтованого графа, 
поданого структурою суміжності */

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
int findFirstZero(Node* head, int m) {
    int currentIndex = 1; //numeration starts from 1
    Node* temp = head;
    
    while (temp && currentIndex < m) {
        if (temp->index == currentIndex) 
            temp = temp->next;
         else 
            return currentIndex;
        currentIndex++;
    }
    
    if (currentIndex < m) 
        return currentIndex; //if we reach end of list, we return index of -1 unless we find zeros
     else 
        return -1;
}

//task3
struct node {
    int num;
    node* left;
    node* right;
};

void countMoreThan(node* root, int A, int* count) {
    if (!root)  
        return;
	
    if (root->num > A) 
        (*count)++;
    
    countLessThan(root->left, A, count);
    countLessThan(root->right, A, count);
}

//task4
int findMinInTree(node* root) {
	if (root->left == NULL)
		return root->num;
	return findMinInTree(root->left);
}

//task5
int countIsolatedVertices(grph graph) {
    int isolatedCount = 0;
    for (int i = 0; i < 8; i++) {
        if (graph.arr[i] == NULL)
            isolatedCount++;
    }
    return isolatedCount;
}
