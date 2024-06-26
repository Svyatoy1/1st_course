#include <iostream>
using namespace std;

//task1 
/* До лінійного списку F з m цілих чисел, більшість елементів якого дорівнює 0,
   застосоване стисле зберігання. Написати функцію для визначення i-го елемента списку */

//task2 
/* Написати функцію для визначення кількості входження елементів менших за A
   до невпорядкованого бінарного дерева, що зберігається у "стандартній формі" */

//task3 
/* Написати функцію, яка перевіряє зв'язніть неорієнтованого графа, поданого структурою суміжності */


//task1

struct cListNode {
    int index;
    int num;
    cListNode* left;
    cListNode* right;
};

int getElementAtIndex(cListNode* cHead, int i) {
    cListNode* temp = cHead;
    while (temp) {
        if (temp->index == i) {
            return temp->num;
        }
        temp = temp->left;
    }
    return 0; // якщо елемент з таким індексом не знайдено, повертаємо 0

//task2 

struct node {
    int num;
    node* left;
    node* right;
};

void countLessThan(node* root, int number, int* count) {
    if (!root) {
        return;
    }
    if (root->num < number) {
        (*count)++;
    }
    countLessThan(root->left, number, count);
    countLessThan(root->right, number, count);
}

//task3 

void DFS(grph graph, int active, bool check[8]) {
    check[active - 1] = true;

    node* temp = graph.arr[active - 1];
    while (temp) {
        if (!check[temp->num - 1])
            DFS(graph, temp->num, check);
        temp = temp->next;
    }
}

bool isGraphConnected(grph& graph) {
    bool check[8] = {false};
   
    int startNode = 1;
    DFS(graph, startNode, check);
   
    for (int i = 0; i < 8; i++) {
        if (!check[i]) {
            return false;
        }
    }
    return true;
}
