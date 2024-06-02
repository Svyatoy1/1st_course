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
