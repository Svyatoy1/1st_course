#include <iostream>
using namespace std;

//task1
/* В елементах зв'язного списку розміщені цілі числа. Написати функцію, що перевпорядковує список, 
збираючи спочатку всі додатні числа, а потім - інші */

//task2
/* Лінійний список F цілих чисел зберігається як послідовно-зв'язний індексний список так, 
що числа, які мають однакову останню цифру, розміщуються в один підсписок. Написати 
функцію, яка додає до списку елемент зі значенням v, якщо такий елемент у списку відсутній */

//task1
void moveNonPositiveToEnd(list** head, list** tail) {
    list* current = *head;
    list* lastPositive = NULL;

    while (current) {
        if (current->num > 0) {
            if (lastPositive == NULL) {
                lastPositive = current;
            } else {
                if (lastPositive->right != current) {
                    if (current->left) 
			current->left->right = current->right;
                    if (current->right) 
			current->right->left = current->left;
                  
                    current->left = lastPositive;
                    current->right = lastPositive->right;
                  
                    if (lastPositive->right) 
			lastPositive->right->left = current;
                  
                    lastPositive->right = current;
                  
                    if (lastPositive == *tail) 
			*tail = current;
                  
                    lastPositive = current;
                } else {
                    lastPositive = current;
                }
            }
        }
        current = current->right;
    }
}

