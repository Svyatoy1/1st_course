#include <iostream>
using namespace std;

//task1
/* В елементах циклічного списку розміщені цілі числа. Написали функцію, що перевпорядковує список, 
збираючи спочатку всі від'ємні числа, потім - 0, а потім додатні */

//task2
/* Лінійний список F цілих чисел зберігається як послідовно-зв'язний індексний список так, 
що числа, які мають дві однакові останні цифри, розміщуються в один підсписок. Написати 
функцію, яка вилучає з списку елемент зі значенням v, якщо він присутній */

void moveList(list** head, list** tail) {
    list* current = *head;
    list* lastNegative = NULL;

    while (current) {
        if (current->num < 0) {
            if (lastNegative == NULL) {
                lastNegative = current;
            } else {
                if (lastNegative->right != current) {
                    if (current->left) 
			current->left->right = current->right;
                    if (current->right) 
			current->right->left = current->left;
                  
                    current->left = lastNegative;
                    current->right = lastNegative->right;
                  
                    if (lastNegative->right) 
			lastNegative->right->left = current;
                  
                    lastNegative->right = current;
                  
                    if (lastNegative == *tail) 
			*tail = current;
                  
                    lastNegative = current;
                } else {
                    lastNegative = current;
                }
            }
        }
        current = current->right;
    }
}

//task2
struct Node {
    int num;
    Node* next;
};

struct IndexNode {
    int key;  // Останні дві цифри числа
    Node* sublist;
    IndexNode* next;
};

IndexNode* findIndexNode(IndexNode* head, int key) {
    while (head && head->key != key)
        head = head->next;
    return head;
}

void deleteFromSublist(Node** sublist, int v) {
    Node* current = *sublist;
    Node* prev = NULL;

    while (current) {
        if (current->num == v) {
            if (prev)
                prev->next = current->next;
            else
                *sublist = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void deleteElement(IndexNode** head, int v) {
    int key = v % 100;  // Визначення останніх двох цифр числа
    IndexNode* indexNode = findIndexNode(*head, key);

    if (indexNode) {
        deleteFromSublist(&(indexNode->sublist), v);

        // Якщо підсписок порожній, видаляємо індексний вузол
        if (indexNode->sublist == NULL) {
            if (*head == indexNode) 
                *head = indexNode->next;
            else {
                IndexNode* temp = *head;
                while (temp->next != indexNode)
                    temp = temp->next;s
                temp->next = indexNode->next;
            }
            delete indexNode;
        }
    }
}
