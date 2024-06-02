#include <iostream>
using namespace std;

//task1 
/* До лінійного списку F з m цілих чисел, більшість елементів якого дорівнює 0,
   застосоване стисле зберігання. Написати функцію для визначення i-го елемента списку */

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
/* Написати функцію для визначення кількості входження елементів менших за A
   до невпорядкованого бінарного дерева, що зберігається у "стандартній формі" */

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
