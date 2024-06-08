#include <iostream>
using namespace std;

//task1
/* Написати функцію, яка переміщує найбільший елемент списку у кінець. 
Список заданий однозв'язним представленням */

//task2
/* Написати функцію для знаходження номера рядка матриці з максимальною кількістю 0 
елементів у розрідженої матриці В[20,50] при стислому зв'язному зберіганні */

//task3
/* Множина цілих чисел представлена деревом двійкового пошуку. Написати нерекурсивну функцію, 
що записує у масив цю множину чисел впорядковану за зростанням */

//task1
void moveMaxToEnd(ListNode*& head) {
    if (!head || !head->next) 
        return;
    
    stackNode* current = head;
    stackNode* maxNode = head;
    stackNode* prevMax = NULL;
    stackNode* prev = NULL;

    while (current) {
        if (current->value > maxNode->value) {
            maxNode = current;
            prevMax = prev;
        }
        prev = current;
        current = current->next;
    }

    if (maxNode->next == NULL)
        return;
    if (prevMax)
        prevMax->next = maxNode->next;
    else 
        head = head->next;

    current = head;
    while (current->next) 
        current = current->next;
  
    current->next = maxNode;
    maxNode->next = NULL;
}

//task2
int maxRowWithZeros(mat* headM) {
	int line = 1;
	int maxnum = 0;
	for (int i = 0; i < 5; i++)
	{
		int numberzero = 0;
		listI* temp = headM->list;
		while (temp)
		{
			numberzero++;
			temp = temp->left;
		}
		if (maxnum < 5 - numberzero)
		{
			maxnum = 5 - numberzero;
			line = i+1;
		}
		headM = headM->next;
	}
	return line;
}

int maxRowWithZeros(MatNode* head) {
    int maxZeros = -1;
    int maxRow = -1;
    int currentRow = 0;
    
    while (head) {
        int zeroCount = 50; // Початково вважати всі елементи нульовими
        ListNode* temp = head->row;
        while (temp) {
            zeroCount--;
            temp = temp->next;
        }
        if (zeroCount > maxZeros) {
            maxZeros = zeroCount;
            maxRow = currentRow;
        }
        head = head->next;
        currentRow++;
    }
    return maxRow;
}
