#include <iostream>
using namespace std;

//task1
/* Написати функцію, яка у списку, що зберігається у зв'язному представленні, з кожної групи 
сусідніх однакових елементів залишає лише один. */

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
