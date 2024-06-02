#include <iostream>
using namespace std;

/* До лінійного списку F з m цілих чисел, більшість елементів якого дорівнюють 0,
   застосоване "стисле зв'язне зберігання". Написати функцію для визначення кількості
   елементів зі значенням 0, номери яких належать інтервалу [i,j]. */

struct cListNode{
	int index;
	int num;
	cListNode *left;
	cListNode *right;
};

int findZerosFromTo(int i, int j, cListNode* head){
	int index = 1;
	int counter = 0;
	
	while (head and head->index <= j)
	{
		if (head->index >= i)
			counter++;
		head = head->left;
	}
	
	return j-i-counter+1 ;
}
