#include <iostream>
using namespace std;

//task1
/* В елементах циклічного списку розміщені цілі числа. Написали функцію, що перевпорядковує список, 
збираючи спочатку всі від'ємні числа, потім - 0, а потім додатні */

//task2
/* Лінійний список F цілих чисел зберігається як послідовно-зв'язний індексний список так, 
що числа, які мають дві однакові останні цифри, розміщуються в один підсписок. Написати 
функцію, яка вилучає з списку елемент зі значенням v, якщо він присутній */

void moveList(list** head, list** tail) {
    list* current = *head;
    list* lastNegative = NULL;

    while (current) {
        if (current->num < 0) {
            if (lastNegative == NULL) {
                lastNegative = current;
            } else {
                if (lastNegative->right != current) {
                    if (current->left) 
			current->left->right = current->right;
                    if (current->right) 
			current->right->left = current->left;
                  
                    current->left = lastNegative;
                    current->right = lastNegative->right;
                  
                    if (lastNegative->right) 
			lastNegative->right->left = current;
                  
                    lastNegative->right = current;
                  
                    if (lastNegative == *tail) 
			*tail = current;
                  
                    lastNegative = current;
                } else {
                    lastNegative = current;
                }
            }
        }
        current = current->right;
    }
}
