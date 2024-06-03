#include <iostream>
using namespace std;

//task1
/* Написати функцію для впорядкування елементів однозв'язного списку за зростанням */

nodeStack* insertionSort(nodeStack* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    nodeStack* sorted = NULL;
    nodeStack* current = head;

    while (current) {
        nodeStack* next = current->next;

        if (sorted == NULL || current->num < sorted->num) {
            current->next = sorted;
            sorted = current;
        } else {
            nodeStack* temp = sorted;
            while (temp->next != NULL && temp->next->num < current->num) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

//task2 
/* Використовуючи відповідний механізм черг або стеків, написати функцію, яка виводить 
відмітки вузлів бінарного дерева, поданого у "стандартній формі", 
по рівнях (починаючи з кореня дерева, далі з синів кореня й далі) */

struct node {
    int num;
    node* left;
    node* right;
};

struct stackTreeElement {
    stackTreeElement* next;
    node* treeNode;
};

void stackTreeAdd(stackTreeElement** tail, node* treeNode) {
    stackTreeElement* temp = new stackTreeElement;
    temp->next = NULL;
    temp->treeNode = treeNode;

    if (*tail) {
        (*tail)->next = temp;
    }
    *tail = temp;
}

void stackTreeDelete(stackTreeElement** head, stackTreeElement** tail) {
    stackTreeElement* temp = *head;
    if (*head == *tail) {
        *tail = NULL;
    }
    *head = (*head)->next;
    delete temp;
}

void stackTreeShow(node* root) {
    if (!root) return;

    stackTreeElement* head = new stackTreeElement;
    head->next = NULL;
    head->treeNode = root;
    stackTreeElement* tail = head;

    bool firstElement = true; // To handle comma placement

    while (head) {
        node* currentNode = head->treeNode;
        if (!firstElement) {
            cout << ", ";
        }
        cout << currentNode->num;
        firstElement = false;

        if (currentNode->left)
            stackTreeAdd(&tail, currentNode->left);
        if (currentNode->right)
            stackTreeAdd(&tail, currentNode->right);

        stackTreeDelete(&head, &tail);
    }
    cout << endl;
}

//task3 
/* Написати функцію для знаходження середнього арифметичного елементів
розрідженої матриці В[20,50] при послідовно-зв'язному індексному зберіганні */

double findMiddleElement (matrix* headM) {
    double number = 0;
    int count;
	while (headM) {
		listI* temp = headM->list;
		while (temp) {
			number += temp->num;
            count++;
			temp = temp->left;
		}
		headM = headM->next;
	}
    if (number != 0)
    	return (number / count);
    return 0;
}

//task4 
/* Написати функцію для побудови кістякового дерева графа пошуком в глибину.
Граф представлений структурою суміжності */

void addEdge(grph &mst, int u, int v) {
    node* newNode = new node;
    newNode->num = v;
    newNode->next = mst.arr[u - 1];
    mst.arr[u - 1] = newNode;
}

void DFSForSpanningTree(grph &graph, int active, bool check[8], grph &mst) {
    check[active - 1] = true;

    node* temp = graph.arr[active - 1];
    while (temp) {
        if (!check[temp->num - 1]) {
            addEdge(mst, active, temp->num);
            addEdge(mst, temp->num, active);
            DFSForSpanningTree(graph, temp->num, check, mst);
        }
        temp = temp->next;
    }
}

grph findSpanningTree(grph &graph) {
    grph mst;
    for (int i = 0; i < 8; i++) {
        mst.arr[i] = NULL;
    }
    bool check[8] = {false};
    DFSForSpanningTree(graph, 1, check, mst); // Починаємо з вузла 1 (можна вибрати будь-який стартовий вузол)
    return mst;
}

//task5
/* Написати функцію для об'єднання двох дерев двійкового пошуку зі значеннями
у деревах відповідно <K та >=K */
