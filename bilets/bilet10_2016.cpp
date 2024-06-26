#include <iostream>
using namespace std;

//task1
/* В елементах циклічного списку розміщені цілі числа. Написати функцію копіювання списку, 
помінявши порядок елементів на оберенений*/

//task 2
/* До лінійного списку F з m цілих чисел, більшість елементів якого дорівнюють 0,
   застосоване "стисле зв'язне зберігання". Написати функцію для визначення кількості
   елементів зі значенням 0, номери яких належать інтервалу [i,j]. */

//task 3
/* Написати функцію для перевірки входження значення а до елементів невпорядкованого
бінарного дерева, що зберігається у стандартній формі */

//task 4
/* Написати функцію для визначення найменшого значення у вузлах непорожнього
дерева, бінарного пошуку, що більше за а*/

//task 5
/* Написати функцію, яка перевіряє ациклічність орієнтованого графа, 
поданого матрицею суміжності */

//task 1
void AddElementInList(list** head, list** tail, int number) {
	list* temp = new list;
	temp->num = number;
	if (*head) {
		(*head)->right = temp;
		(*tail)->left = temp;
		temp->left = (*head);
		temp->right = (*tail);
		(*tail) = temp;
	} else {
		(*tail) = temp;
		(*head) = (*tail);
		(*head)->left = (*tail);
		(*head)->right = (*tail);
		(*tail)->left = (*head);
		(*tail)->right = (*head);
	}
}

void CopyList(list* head, list* tail, list** headc, list** tailc) {
	do {
		AddElementInList(headc, tailc, tail->num);
		tail = tail->right;
	} while 
      (tail != head->right);
}

//task 2
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

//task3
bool findNodeOfBinaryTree(node* root, int num) {
    if (!root) return false;

    if (root->num == num) {
        cout << "Number: " << root->num << ", level: " << *height << endl;
        return true;
    }

    bool foundInLeft = findNodeOfBinaryTree(root->left, num);
    if (foundInLeft) return true;

    bool foundInRight = findNodeOfBinaryTree(root->right, num);
    if (foundInRight) return true;
	
    return false;
}

//task4
int findMinMoreThanA(node* root, int a) {
    int minVal = -1; // Початкове значення, яке вказує на відсутність результату
    while (root) {
        if (root->num > a) {
            minVal = root->num;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return minVal;
}

//task5
void DFS(int graph[N][N], int vertex, bool visited[N], int parent, bool& cyclic) {
    visited[vertex] = true;
    for (int i = 0; i < N; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited, vertex, cyclic);
        } else if (graph[vertex][i] == 1 && i != parent) {
            cyclic = true; // Знайдено цикл
        }
    }
}

bool isCyclic(int graph[N][N]) {
    bool visited[N] = {false};
    bool cyclic = false;

    // Починаємо DFS з кожної вершини графа
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            DFS(graph, i, visited, -1, cyclic);
            if (cyclic) {
                return true;
            }
        }
    }
    return false;
}
