#include <iostream>
using namespace std;

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
