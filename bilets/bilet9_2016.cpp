#include <iostream>
using namespace std;

//task1
/* Многочлен від однієї змінної з цілими коефіцієнтами можна подати зв'язним списком, 
впорядкованим за зростанням степені змінної, без зберігання одночленів з нульовими
коефіцієнтами. Написати функцію, яка реалізує обчислення похідної від многочлена */

//task 2
/* До лінійного списку F з m цілих чисел, більшість елементів якого дорівнюють 0,
застосоване зв'язне стисле зберігання. Написати функцію для визначення і-го 
за порядком елемента списку F */

//task 3
/* Написати функцію для визначення кількості вхдження елементів більших за а
до невпорядкованого бінарного дерева, що зберігається у стандартній формі */

//task 4
/* Написати функцію для визначення найбільшого значення у вузлах непорожнього
дерева бінарного пошуку, що менше за а */

//task 5
/* Написати функцію, яка перевіряє зв'язність неорієнтованого графа, поданого
матрицею суміжності*/


//task1
struct list {
    int num; // коефіцієнт
    int step; // степінь
    list* left; // попередній елемент
    list* right; // наступний елемент
};

void deleteNode(list** node, list** head, list** tail) {
    list* temp = *node;
    if (temp->left) {
        temp->left->right = temp->right;
    } else {
        *head = temp->right;
    }
    if (temp->right) {
        temp->right->left = temp->left;
    } else {
        *tail = temp->left;
    }
    *node = temp->right;
    delete temp;
}

void findDerivative(list** head, list** tail) {
    list* current = *head;
    while (current) {
        current->num *= current->step;
        current->step--;
        if (current->step < 0) {
            deleteNode(&current, head, tail);
        } else {
            current = current->right;
        }
    }
}

//task 2
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
}

//task 3
struct node {
    int num;
    node* left;
    node* right;
};

void countMoreThan(node* root, int number, int* count) {
    if (!root) {
        return;
    }
    if (root->num > number) {
        (*count)++;
    }
    countLessThan(root->left, number, count);
    countLessThan(root->right, number, count);
}

//task 4
int findMaxLessThanA(node* root, int a) {
    int maxVal = -1; // Початкове значення, яке вказує на відсутність результату
    while (root) {
        if (root->num < a) {
            maxVal = root->num;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return maxVal;
}

//task5
//замість N можна подати будь-яке число, бо Іванов не оч любить глобальні змінні
void DFS(int graph[N][N], int vertex, bool visited[N]) {
    visited[vertex] = true;
    for (int i = 0; i < N; ++i) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

bool isConnected(int graph[N][N]) {
    bool visited[N] = {false};
    // Починаємо DFS з першої вершини (0)
    DFS(graph, 0, visited);
    // Перевіряємо, чи всі вершини відвідані
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            return false; // Якщо знайдена не відвідана вершина, граф не зв'язний
        }
    }
    return true;
}
