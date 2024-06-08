#include <iostream>
using namespace std;

//task1 
/* В елементах зв'язного списку розміщені різні цілі числа. Написати функцію, що роздруковує
   значення елементів, розміщених між найменшим та найбільшим елементами списку */

//task2 
/* Використовуючи відповідний механізм черг або стеків, написати функцію, яка виводить 
відмітки вузлів бінарного дерева, поданого у "стандартній формі", 
по рівнях (починаючи з кореня дерева, далі з синів кореня й далі) */

//task 3
/* Написати функцію, що перевіряє зв'язний граф, поданий "стурктурою суміжності", на ейлеровість */

//task1
void printElementsBetweenMinAndMax(Node* head){
    Node* current = head;
    int minIndex = 0;
    int maxIndex = 0;
    int currentIndex = 0;
    Node *minNode = head;
    Node *maxNode = head;

    while (current) {
        if (current->data < minNode->data) {
            minNode = current;
            minIndex = currentIndex;
        } else if (current->data > maxNode->data) {
            maxNode = current;
            maxIndex = currentIndex;
        }
        currentIndex++;
        current = current->next;
    }

    Node* startFrom;
    Node* endBy;
    if (maxIndex > minIndex) {
        startFrom = minNode;
        endBy = maxNode;
    } else {
        startFrom = maxNode;
        endBy = minNode;
    }
    Node* currentToPrint = startFrom;

    while (currentToPrint != endBy->next){
        cout << currentToPrint->data << "->";
        currentToPrint = currentToPrint->next;
    }
}

//task2 
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

//task 3
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

int main() {
    node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    stackTreeShow(root);

    return 0;
}
