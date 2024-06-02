#include <iostream>
using namespace std;

//task1
/* Список F з цілих чисел, більшість елементів якого дорівнюють 0, представлений
   своїм зв'язним зберіганням. Написати функцію для представлення F 
   "стислим зв'язним зберіганням". */

//task2
/* Написати функцію для знаходження у невпорядкованому бінарному дереві,
   що зберігається у "стандартній формі", вершини зі значенням v 
   та рівня, де розташована ця вершина. */

//task3
/* Написати функцію, яка за матрицею суміжності графа будує його структуру суміжності */

struct node {
    int num; // index of matrix column
    node* next; // pointer to next element in the same row
};

struct grph {
    node* arr[8];
};

grph matrixToStruct(int mtr[8][8]){
    grph graph;
    for (int i=0; i<8; i++)
        graph.arr[i] = NULL;

    for (int i=0; i<8; i++){
        node* tempLast = NULL;
        for (int j=0; j<8; j++){
            if (mtr[i][j] != 0){
                node* tempNew = new node;
                tempNew->num = j;
                tempNew->next = NULL;

                if(!graph.arr[i])
                    graph.arr[i] = tempNew;
                else
                    tempLast->next = tempNew;
                tempLast = tempNew;
            }
        }
    }
    return graph;
}
