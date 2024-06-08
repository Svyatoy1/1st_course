#include <iostream>
using namespace std;
//task 1
/* Написати функцію для копіювання списку у «однозвʼязному представленні», зберігаючи 
взаємний порядок елементів, але зробивши у копії «двозвʼязне циклічне представлення» */

//task 2
/* Написати функцію для визначення висоти «дерева степені 3», що зберігається у 
«розширеній стандартній формі». */

//task3
/* Знайти всі вершини графа, що поданий «структурую суміжності», до яких існує шлях 
заданої довжини d від заданої вершини */

//task1
struct stack {
    int num;
    stack* next; 
};

struct list {
    int num;
    list* left; 
    list* right; 
};

void copyToDoubleCircular(stack* stackHead, list** head, list** tail) {
    if (!stackHead) {
        *head = NULL;
        *tail = NULL;
        return;
    }
    list* temp = new list;
    temp->num = stackHead->num;
    temp->left = temp;
    temp->right = temp;
    *head = temp;
    *tail = temp;
    stackHead = stackHead->next;
    while (stackHead) {
        list* newNode = new list;
        newNode->num = stackHead->num;
        newNode->left = *tail; 
        newNode->right = *head; 
        (*tail)->right = newNode;
        (*head)->left = newNode; 
        *tail = newNode;
        stackHead = stackHead->next;
    }
}

//task2
struct TreeNode {
    int value;
    TreeNode* parent;
    TreeNode* child1;
    TreeNode* child2;
    TreeNode* child3;
};

int heightOfTree(TreeNode* node) {
    if (node == NULL)
        return 0;

    int height1 = heightOfTree(node->child1);
    int height2 = heightOfTree(node->child2);
    int height3 = heightOfTree(node->child3);

    return 1 + max({height1, height2, height3});
}

//task3
struct GraphNode {
    int index;
    GraphNode* next;
};

void findVertices(int current, int currentDistance, int distance, bool* result, bool* visited, GraphNode* GraphArr[], int rows) {
    if (currentDistance == distance) {
        result[current] = true;
        return;
    }
    visited[current] = true;
    GraphNode* neighbor = GraphArr[current];
    while (neighbor) {
        if (!visited[neighbor->index]) {
            findVertices(neighbor->index, currentDistance + 1, distance, result, visited, GraphArr, rows);
        }
        neighbor = neighbor->next;
    }
    visited[current] = false;
}

void task3(int startVertex, int distance, bool* result, GraphNode* GraphArr[], int rows) {
    if (distance < 0 || startVertex < 0 || startVertex >= rows)
        return;

    bool visited[rows] = {false};
    for (int i = 0; i < rows; ++i) {
        result[i] = false;
    }

    findVertices(startVertex, 0, distance, result, visited, GraphArr, rows);

    cout << "Vertices at distance " << distance << " from vertex " << startVertex + 1 << " are: ";
    for (int i = 0; i < rows; i++) {
        if (result[i]) 
            cout << i + 1 << " ";
    }
    cout << '\n';
}
