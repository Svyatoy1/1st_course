#include <iostream>
using namespace std;

//task 1
/* До лінійного списку F з m цілих чисел, більшість елементів якого дорівнюють 0,
   застосоване "стисле зв'язне зберігання". Написати функцію для визначення кількості
   елементів зі значенням 0, номери яких належать інтервалу [i,j]. */

struct listNode {
    int num;
    listNode* left;
    listNode* right;
};

struct cListNode{
	int index;
	int num;
	cListNode *left;
	cListNode *right;
};

void cListAdd(int value, int index, cListNode** head, cListNode** tail) {
    cListNode* temp = new cListNode;
    temp->num = value;
    temp->index = index;

    if (!(*head)) {
        *head = temp;
        *tail = temp;
        temp->left = NULL;
        temp->right = NULL;
    } else {
        temp->right = *tail;
        temp->left = NULL;
        (*tail)->left = temp;
        *tail = temp;
    }
}

void cListNew(cListNode** cHead, cListNode** cTail, listNode* head) {
    listNode* temp = head;
    int index = 1;

    while (temp) {
        if (temp->num != 0) {
            cListAdd(temp->num, index, cHead, cTail);
        }
        index++;
        temp = temp->left;
    }
}

//MAIN FUNCTION
int findZerosFromTo(int i, int j, cListNode* head) {
    int counter = i;
    int numberOfZeros = 0;
    while (head && head->index <= j) {
        if (head->index >= i) {
            while (counter < head->index) {
                numberOfZeros++;
                counter++;
            }
            counter++; // move to the next expected index
        }
        head = head->left;
    }
    // Account for any remaining zeros in the range
    while (counter <= j) {
        numberOfZeros++;
        counter++;
    }
    return numberOfZeros;
}

//task2
/* Написати функцію для обчислення значення виразу з цілих чисел та операцій "+", "*",
записаного у формі ПОЛІЗ. Потрібний стек реалізуват власноруч */

struct number{
	int num;
	number* next;
};

void numberAdd(number** head, int num){
	number *temp = new number;
	temp->num = num;
	temp->next = *head;
	*head = temp;
}

int numberGet(number** head){
	int num;
	num = (*head)->num;
	number *temp = *head; 
	*head = (*head)->next;
	delete temp;
	return num;
}

int countPOLIZ(char in[100]){
	number* head = NULL;
	for (int i = 0; in[i]; i++) {
		if (in[i] != ' ') {
			if (in[i]>47 and in[i]<58) {
				int num = 0;
				while (in[i]>47 and in[i]<58) {
					num = num*10+in[i] - 48; 
					i++;
				}
				numberAdd(&head, num);
			}			
			else {
				int result;
				if (in[i] == '+')
				    result = numberGet(&head) + numberGet(&head);
				else if (in[i] == '*')
				    result = numberGet(&head) * numberGet(&head);  
				numberAdd(&head, result);	  
			}  
		}
	}
	return head->num;
}

//task3
/* Написати функцію, яка для орієнтованого графа будує орієнтований граф
   з протилежною орієнтацією дуг. Графи представлені "структурами суміжності" */

struct node {
    int num; // index of matrix column
    node* next; // pointer to next element in the same row
};

struct grph {
    node* arr[8];
};

grph arcReverseOrientation (grph graph){
	grph* reverse = new grph;
	for (int i=0; i<10; i++)
		reverse->arr[i] = NULL;

	for (int i=0; i<10; i++) {
		node* temp = graph.arr[i];
		while (temp){
			node* number = new node;
			number->num = i+1;
			number->next = NULL;

			node** added = &(reverse->arr[temp->num - 1];

			if (*added == NULL)
				*added = number;
			else {
				node* start = (*added);
            			while ((*added)->next)
                    			(*added) = (*added)->next;
               			(*added)->next = number;
               			(*added) = start;
			}
			temp = temp->next;
		}
	}
	return reverse;
}

int main () {
//task1
    listNode* head = NULL;
    listNode* tail = NULL;

    head = new listNode{1, NULL, NULL};
    tail = head;
    tail->left = new listNode{0, NULL, tail};
    tail = tail->left;
    tail->left = new listNode{2, NULL, tail};
    tail = tail->left;
    tail->left = new listNode{0, NULL, tail};
    tail = tail->left;
    tail->left = new listNode{0, NULL, tail};
    tail = tail->left;
    tail->left = new listNode{3, NULL, tail};
    tail = tail->left;

    cListNode* cHead = NULL;
    cListNode* cTail = NULL;
    cListNew(&cHead, &cTail, head);
    showCList(cHead);

    int i = 1;
    int j = 5;
    int numberOfZeros = findZerosFromTo(i, j, cHead);
	cout << "Number of zeros from index " << i << " to " << j << ": " << numberOfZeros << endl;

//task2
    	char in[100] = "20+35*2+30";
	char out[100] = "";
	cout << "input:  "<< in<<endl;
	makePOLIZ(in, out);
	cout << "output:  "<<out<<endl;
        cout << "count result: " << countPOLIZ(out);
	return 0;
}
