#include <iostream>
using namespace std;

//task1
/* Здійснити злиття двох впорядкованих списків у зв'язному зберіганні в один, який також впорядкований 
й представлений новим списком */

//task2
/* Написати функцію для побудови послідовно-зв'язного індексного зберігання розрідженої матриці 
В[10,40] за звичайним представленням двовимірним масивом */

//task1
ListNode* mergeSortedLists(ListNode* list1, ListNode* list2) {
    if (!list1) return l2;
    if (!list2) return l1;

    ListNode* mergedHead = NULL;
    ListNode* mergedTail = NULL;

    if (list1->data <= list2->data) {
        mergedHead = mergedTail = list1;
        list1 = list1->next;
    } else {
        mergedHead = mergedTail = list2;
        list2 = list2->next;
    }

    while (list1 && list2) {
        if (list1->data <= list2->data) {
            mergedTail->next = list1;
            mergedTail = list1;
            list1 = list1->next;
        } else {
            mergedTail->next = list2;
            mergedTail = list2;
            list2 = list2->next;
        }
    }

    if (list1)
        mergedTail->next = list1;
    else 
        mergedTail->next = list2;

    return mergedHead;
}

//task2
struct ListNode {
    int value;
    int rowIndex;
    int colIndex;
    ListNode* next;
    ListNode* prev;
};

struct MatNode {
    ListNode* rowList;
    MatNode* next;
};

void AddElement(ListNode** head, ListNode** tail, int value, int rowIndex, int colIndex) {
    ListNode* newNode = new ListNode;
    newNode->value = value;
    newNode->rowIndex = rowIndex;
    newNode->colIndex = colIndex;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head) {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    } else {
        *head = newNode;
        *tail = newNode;
    }
}

ListNode* CreateRowList(ListNode** head, ListNode** tail, const int rowIndex, const int arr[], const int length) {
    for (int i = 0; i < length; i++) {
        if (arr[i] != 0)
            AddElement(head, tail, arr[i], rowIndex, i);
    }
    return *head;
}

void CreateSparseMatrix(MatNode** headMat, MatNode** tailMat, int numRows, int numCols, int matrix[10][40]) {
    for (int i = 0; i < numRows; i++) {
        ListNode* rowHead = NULL;
        ListNode* rowTail = NULL;
        MatNode* newMatNode = new MatNode;
        newMatNode->rowList = CreateRowList(&rowHead, &rowTail, i, matrix[i], numCols);
        newMatNode->next = NULL;

        if (*headMat) {
            (*tailMat)->next = newMatNode;
            *tailMat = newMatNode;
        } else {
            *headMat = newMatNode;
            *tailMat = newMatNode;
        }
    }
}
