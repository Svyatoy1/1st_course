#include <iostream>
using namespace std;

//task1
/* Здійснити злиття двох впорядкованих списків у зв'язному зберіганні в один, який також впорядкований 
й представлений новим списком */

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
