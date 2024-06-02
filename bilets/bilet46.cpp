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
	int counter = 1;
	int numberOfZeros = 0;

	while (head){
		if (head->right == NULL && ((head->index) - counter + 1) > i){
			numberOfZeros++;
			counter++;
		}
		if (head->right == NULL && ((head->index) - counter + 1) == i)
			counter = 1;
		if (head->index >= i && head->index <=j){
			if (head->right && ((head->index) - counter) != (head->right->index)){
				numberOfZeros++;
				counter++;
			}
			counter = 1;
		}
		head = head->left;
	}
	
	return numberOfZeros;
}
