#include <iostream>
using namespace std;

//task1
/* Поліном від однієї змінної з цілими коефіцієнтами можна подати зв'язним списком, 
впорядкованим за зростанням степені змінної, без зберігання одночленів із з нульовими 
коефіцієнтами. Написати функцію, яка реалізує обчислення похідної від поліному */

//task2
/* Написати функцію для сортування масиву методом "визначення позиції". 
(1. Порівняннями кожного елемента з іншими визначають кількість менших за нього (k). 
Це визначає місце елемента у впорядкованому масиві (k+1). 2. Переставляють елементи згідно з їх місцями) */

//task3
/* Побудувати "дерево двійкового пошуку" за заданою множиною цілих чисел й занумерувати 
його вершини згідно з обходом у "симетричному порядку" */

//task1
struct list {
    int num; // coefficient
    int step; // exponent
    list* left; // previous node
    list* right; // next node
};

void derivativePolynom(list** head, list** tail) {
    list* current = (*head);
    while (current) {
        current->num *= current->step;
        current->step--;
        list* next = current->right;
        if (current->step < 0) {
            if (current->left)
                current->left->right = current->right;
            else
                *head = current->right; // Якщо видаляємо перший елемент, оновлюємо голову списку
            }
            if (current->right)
                current->right->left = current->left;
            else
                *tail = current->left; // Якщо видаляємо останній елемент, оновлюємо хвіст списку
            delete current;
        }
        current = next;
    }
}

//task2
void Sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//task3
struct TreeNode {
    int value;
    int index;
    TreeNode* left;
    TreeNode* right;
};

// Функція створення нового вузла
TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode;
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    newNode->index = 0;
    return newNode;
}

// Функція вставки значення у дерево
void insert(TreeNode** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        return;
    }

    if (value < (*root)->value) {
        if ((*root)->left == NULL)
            (*root)->left = createNode(value);
        else
            insert(&(*root)->left, value);
    } else if (value > (*root)->value) {
        if ((*root)->right == NULL)
            (*root)->right = createNode(value);
        else
            insert(&(*root)->right, value);
    } else {
        cout << "Node with given value already exists\n";
    }
}

// Функція симетричного обходу дерева з нумерацією вершин
void inorderTraversal(TreeNode* node, int& counter) {
    if (node == NULL)
        return;
    
    inorderTraversal(node->left, counter);
    node->index = counter++;
    cout << "Node #" << node->index << ": " << node->value << "\n";
    inorderTraversal(node->right, counter);
}

// Основна функція для виконання завдання
void task3(int arr[], int size) {
    TreeNode* root = NULL;
    // Побудова дерева
    for (int i = 0; i < size; i++) {
        insert(&root, arr[i]);
    }
    // Пронумерований вивід вершин у симетричному порядку
    int counter = 0;
    inorderTraversal(root, counter);
}
