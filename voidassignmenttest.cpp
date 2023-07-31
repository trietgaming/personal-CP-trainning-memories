#include <iostream>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* insert(node* t, int data) {
    if (t == NULL) {
        node* temp = new node;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if (data <= t->data) t->left = insert(t->left, data);
    else t->right = insert(t->right, data);
}

void printTree(node *t){
	if (t != NULL){
		printTree(t->left);
		cout << t->data << " " ;
		printTree(t->right);
	}
}

void deallocate(node* t) {
    if (t != NULL) {
        deallocate(t->left);
        deallocate(t->right);
        delete t;
    }
}

int test(int x) {
}

int main() {

    node* root = NULL;
    root = insert(root, 4);
		int a = 5, b = 6;
		a = test(b);
		
		cout << a << " ";
		
    printTree(root);

    deallocate(root);

    return 0;
}
