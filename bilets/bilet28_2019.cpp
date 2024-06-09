#include <iostream>
using namespace std;

//task1
/* Написати функцію, яка переміщує найбільший елемент списку у кінець. 
Список заданий однозв'язним представленням */

//task2
/* Написати функцію для знаходження номера рядка матриці з максимальною кількістю 0 
елементів у розрідженої матриці В[20,50] при стислому зв'язному зберіганні */

//task3
/* Множина цілих чисел представлена деревом двійкового пошуку. Написати нерекурсивну функцію, 
що записує у масив цю множину чисел впорядковану за зростанням */

//task1
void moveMaxToEnd(ListNode*& head) {
    if (!head || !head->next) 
        return;
    
    stackNode* current = head;
    stackNode* maxNode = head;
    stackNode* prevMax = NULL;
    stackNode* prev = NULL;

    while (current) {
        if (current->value > maxNode->value) {
            maxNode = current;
            prevMax = prev;
        }
        prev = current;
        current = current->next;
    }

    if (maxNode->next == NULL)
        return;
    if (prevMax)
        prevMax->next = maxNode->next;
    else 
        head = head->next;

    current = head;
    while (current->next) 
        current = current->next;
  
    current->next = maxNode;
    maxNode->next = NULL;
}

//task2
int maxRowWithZeros(MatNode* head) {
    int maxZeros = -1;
    int maxRow = -1;
    int currentRow = 0;
    
    while (head) {
        int zeroCount = 50; // Початково вважати всі елементи нульовими
        ListNode* temp = head->row;
        while (temp) {
            zeroCount--;
            temp = temp->next;
        }
        if (zeroCount > maxZeros) {
            maxZeros = zeroCount;
            maxRow = currentRow;
        }
        head = head->next;
        currentRow++;
    }
    return maxRow;
}

//task3
// Вузол дерева
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

// Вузол стека
struct StackNode {
    TreeNode* treeNode;
    StackNode* next;
};

// Додавання вузла в стек
void pushStack(StackNode** head, StackNode** tail, TreeNode* treeNode) {
    StackNode* newNode = new StackNode;
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Видалення вузла зі стека
void popStack(StackNode** head, StackNode** tail) {
    if (*head == NULL) 
	    return;
    StackNode* temp = *head;
    *head = (*head)->next;
    if (*head == NULL) *tail = NULL;
    delete temp;
}

// Нерекурсивний обхід дерева та запис у масив
void treeToSortedArray(TreeNode* root, int arr[], int& index) {
    StackNode* head = NULL;
    StackNode* tail = NULL;
    TreeNode* current = root;

    while (current || head) {
        while (current) {
            pushStack(&head, &tail, current);
            current = current->left;
        }
        current = head->treeNode;
        arr[index++] = current->value;
        popStack(&head, &tail);
        current = current->right;
    }
}
