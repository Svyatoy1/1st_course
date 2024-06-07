#include <iostream>
using namespace std;

//task1
/* В елементах циклічного списку розміщені цілі числа. Написали функцію, що перевпорядковує список, 
збираючи спочатку всі від'ємні числа, потім - 0, а потім додатні */

//task2
/* Лінійний список F цілих чисел зберігається як послідовно-зв'язний індексний список так, 
що числа, які мають дві однакові останні цифри, розміщуються в один підсписок. Написати 
функцію, яка вилучає з списку елемент зі значенням v, якщо він присутній */

//task3
/* Написати функцію для визначення висоти невпорядкованого бінарного дерева, що зберігається у стандартній формі */

//task4
/* Написати функцію для визначення кількості входжень значень з інтервалу [v, u] до дерева бінарного пошуку */

//task5
/* Написати функцію, що перевіряє зв'язний граф, поданий "стурктурою суміжності", на ейлеровість */

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

//task3
int height(Node* root) {
    if (root == NULL) 
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else 
        return rightHeight + 1;
}

//task4
int countInRange(Node* root, int v, int u) {
    if (root == NULL)
        return 0;

    int count = 0;
    if (root->num >= v && root->num <= u)
        count++;

    if (root->num > v)
        count += countInRange(root->left, v, u);

    if (root->num < u)
        count += countInRange(root->right, v, u);

    return count;
}

//task5
bool isEulerian(grph graph){
   for (int i = 0; i<10; i++) { // assuming graph has 10 vertices
      int step = 0;   
      node* temp = graph.arr[i];
      while (temp) {
         step++;
         temp = temp->next;
      } 
      if (step%2 != 0)
         return false;
      }
      return true;
}
