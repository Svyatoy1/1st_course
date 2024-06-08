#include <iostream>
using namespace std;

//task1
/* Написати функцію, яка у списку, що зберігається у зв'язному представленні, з кожної групи 
сусідніх однакових елементів залишає лише один. */

//task2
/* Написати функцію, для обчислення матриці В=А2, де для матриці А використано "прямокутне-зв'язне стисле зберігання", 
а матриця В зберігається традиційним чином у вигляді двовимірного масиву */

//task3
/* Написати функцію, яка обчислює кількість елементів більших за v у множині, 
що представлена невпорядкованим бінарним деревом у "стандартній формі" */

//task1
void leaveOne(list** head, list** tail) {
    list* current = *head;
    while (current) {
        list* nextNode = current->right;
        while (nextNode && current->num == nextNode->num) {
            list* temp = nextNode;
            nextNode = nextNode->right;
            if (temp->right) {
                temp->right->left = temp->left;
            } else {
                *tail = temp->left; // Update the tail if we are removing the last element
            }
            temp->left->right = temp->right;
            delete temp;
        }
        current = nextNode;
    }
}

//task2
void MatrixQuadro(node* arrR[], node* arrST[], int matrix[10][10]) {
    // Ініціалізація матриці результатів
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = 0;
        }
    }

    // Обчислення матриці B = A^2
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            node* tempR = arrR[i];
            node* tempST = arrST[j];
            while (tempR && tempST) {
                if (tempR->j == tempST->i) {
                    matrix[i][j] += tempR->data * tempST->data; // Накопичення суми добутків
                    tempR = tempR->nextR;
                    tempST = tempST->nextST;
                } else if (tempR->j < tempST->i) {
                    tempR = tempR->nextR;
                } else {
                    tempST = tempST->nextST;
                }
            }
        }
    }
}
