#include <iostream>
using namespace std;

/* До лінійного списку F з m цілих чисел, більшість елементів якого дорівнюють 0,
   застосоване "стисле зв'язне зберігання". Написати функцію для визначення кількості
   елементів зі значенням 0, номери яких належать інтервалу [i,j]. */

struct listNode {
    int num;
    listNode* left;
    listNode* right;
};

struct cListNode{
	int index;
	int num;
	cListNode *left;
	cListNode *right;
};

void cListAdd(int value, int index, cListNode** head, cListNode** tail) {
    cListNode* temp = new cListNode;
    temp->num = value;
    temp->index = index;

    if (!(*head)) {
        *head = temp;
        *tail = temp;
        temp->left = NULL;
        temp->right = NULL;
    } else {
        temp->right = *tail;
        temp->left = NULL;
        (*tail)->left = temp;
        *tail = temp;
    }
}

void cListNew(cListNode** cHead, cListNode** cTail, listNode* head) {
    listNode* temp = head;
    int index = 1;

    while (temp) {
        if (temp->num != 0) {
            cListAdd(temp->num, index, cHead, cTail);
        }
        index++;
        temp = temp->left;
    }
}

int findZerosFromTo(int i, int j, cListNode* head) {
    int counter = i;
    int numberOfZeros = 0;
    while (head && head->index <= j) {
        if (head->index >= i) {
            while (counter < head->index) {
                numberOfZeros++;
                counter++;
            }
            counter++; // move to the next expected index
        }
        head = head->left;
    }
    // Account for any remaining zeros in the range
    while (counter <= j) {
        numberOfZeros++;
        counter++;
    }
    return numberOfZeros;
}
