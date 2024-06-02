struct node {
    int num;
    node* left;
    node* right;
};

node* createNode(int num) {
    node* newNode = new node();
    newNode->num = num;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(node*& root, int num) {
    if (root == NULL) {
        root = createNode(num);
        return;
    }
    if (num < root->num) {
        insertNode(root->left, num);
    } else {
        insertNode(root->right, num);
    }
}

void deleteTree(node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
