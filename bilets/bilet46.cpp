#include <iostream>
using namespace std;

//task 1
/* До лінійного списку F з m цілих чисел, більшість елементів якого дорівнюють 0,
   застосоване "стисле зв'язне зберігання". Написати функцію для визначення кількості
   елементів зі значенням 0, номери яких належать інтервалу [i,j]. */

//task2
/* Написати функцію для обчислення значення виразу з цілих чисел та операцій "+", "*",
записаного у формі ПОЛІЗ. Потрібний стек реалізуват власноруч */

//task3
/* Написати функцію, яка для орієнтованого графа будує орієнтований граф
   з протилежною орієнтацією дуг. Графи представлені "структурами суміжності" */

//task 1
struct listNode {
    int num;
    listNode* left;
    listNode* right;
};

struct CompactNode{
    int index;
    int num;
    CompactNode* left;
    CompactNode* right;
};

void cListAdd(int value, int index, CompactNode** head, CompactNode** tail) {
    CompactNode* temp = new CompactNode;
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

void cListNew(CompactNode** cHead, CompactNode** cTail, listNode* head) {
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
int findZerosFromTo(CompactNode* head, int i, int j){
    int nodesWithNonZeroValue = 0;
    CompactNode* current = head;

    while (current) {
        if(current->index >= i && current->index <= j)
            nodesWithNonZeroValue++;
        current = current->left;
    }
    return (j - i + 1) - nodesWithNonZeroValue;
}

//task2
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
struct node {
    int num; // index of matrix column
    node* next; // pointer to next element in the same row
};

struct grph {
    node* arr[8];
};

// MAIN FUNCTION
grph arcReverseOrientation(grph graph) {
    grph reverse;
    for (int i = 0; i < 8; i++)
        reverse.arr[i] = NULL;

    for (int i = 0; i < 8; i++) {
        node* temp = graph.arr[i];
        while (temp) {
            node* number = new node;
            number->num = i;
            number->next = NULL;

            node** added = &(reverse.arr[temp->num]);

            if (*added == NULL)
                *added = number;
            else {
                node* start = *added;
                while ((*added)->next)
                    *added = (*added)->next;
                (*added)->next = number;
                *added = start;
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

    CompactNode* cHead = NULL;
    CompactNode* cTail = NULL;
    cListNew(&cHead, &cTail, head);

    int i = 1;
    int j = 5;
    int numberOfZeros = findZerosFromTo(cHead, i, j);
	cout << "quantity of zeroes: " << numberOfZeros << '\n'; 

//task2
    	char in[100] = "20+35*2+30";
	char out[100] = "";
	cout << "input:  "<< in<<endl;
	makePOLIZ(in, out);
	cout << "output:  "<<out<<endl;
        cout << "count result: " << countPOLIZ(out);
	return 0;
	
	// task3
	int mtr[8][8] = {{0,1,0,1,0,0,1,0},
                      {0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0}, 
                      {0,0,0,0,0,0,0,0}};

    showMatrix(mtr);
    grph Graphik = matrixToStruct(mtr);
    showStruct(Graphik);
    
    grph reverse = arcReverseOrientation(Graphik);
    showStruct(reverse);
    
    return 0;
}
