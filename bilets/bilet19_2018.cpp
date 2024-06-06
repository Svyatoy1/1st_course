#include <iostream>
using namespace std;

//task1
/* В елементах зв'язного списку розміщені цілі числа. Написати функцію, що перевпорядковує список, 
збираючи спочатку всі додатні числа, а потім - інші */

//task2
/* Лінійний список F цілих чисел зберігається як послідовно-зв'язний індексний список так, 
що числа, які мають однакову останню цифру, розміщуються в один підсписок. Написати 
функцію, яка додає до списку елемент зі значенням v, якщо такий елемент у списку відсутній */

//task1
void moveNonPositiveToEnd(list** head, list** tail) {
    list* current = *head;
    list* lastPositive = NULL;

    while (current) {
        if (current->num > 0) {
            if (lastPositive == NULL) {
                lastPositive = current;
            } else {
                if (lastPositive->right != current) {
                    if (current->left) 
			current->left->right = current->right;
                    if (current->right) 
			current->right->left = current->left;
                  
                    current->left = lastPositive;
                    current->right = lastPositive->right;
                  
                    if (lastPositive->right) 
			lastPositive->right->left = current;
                  
                    lastPositive->right = current;
                  
                    if (lastPositive == *tail) 
			*tail = current;
                  
                    lastPositive = current;
                } else {
                    lastPositive = current;
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

// Вузол для індексного списку
struct IndexNode {
    int lastDigit;  // остання цифра чисел у підсписку
    Node* sublist;  // вказівник на підсписок
    IndexNode* next;
};

Node* createNode(int num) {
    Node* newNode = new Node();
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}

IndexNode* createIndexNode(int lastDigit) {
    IndexNode* newIndexNode = new IndexNode();
    newIndexNode->lastDigit = lastDigit;
    newIndexNode->sublist = NULL;
    newIndexNode->next = NULL;
    return newIndexNode;
}

void addIfAbsent(IndexNode*& head, int v) {
    int lastDigit = v % 10;  // Визначаємо останню цифру числа
    IndexNode* current = head;
    IndexNode* prev = NULL;

    // Шукаємо індексний вузол з потрібною останньою цифрою
    while (current && current->lastDigit != lastDigit) {
        prev = current;
        current = current->next;
    }

    if (current) {
        // Індексний вузол знайдено, перевіряємо підсписок
        Node* sublist = current->sublist;
        while (sublist) {
            if (sublist->num == v) {
                // Число вже є у підсписку, нічого не додаємо
                return;
            }
            sublist = sublist->next;
        }
        // Числа немає, додаємо його до підсписку
        Node* newNode = createNode(v);
        newNode->next = current->sublist;
        current->sublist = newNode;
    } else {
        // Індексного вузла немає, створюємо новий
        IndexNode* newIndexNode = createIndexNode(lastDigit);
        newIndexNode->sublist = createNode(v);
        if (prev)
		prev->next = newIndexNode;
        else
        	head = newIndexNode;
        }
    }
}
