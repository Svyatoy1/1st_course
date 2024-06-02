#include <iostream>
using namespace std;

//task1 
/* До лінійного списку F з m цілих чисел, більшість елементів якого дорівнює 0,
   застосоване стисле зберігання. Написати функцію для визначення i-го елемента списку */

int getElementAtIndex(cListNode* cHead, int index) {
    cListNode* temp = cHead;
    while (temp) {
        if (temp->index == index) {
            return temp->num;
        }
        temp = temp->left;
    }
    return 0; // якщо елемент з таким індексом не знайдено, повертаємо 0
