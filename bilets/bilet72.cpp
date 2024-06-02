#include <iostream>
using namespace std;

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
