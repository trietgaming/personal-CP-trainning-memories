#include <bits/stdc++.h>

using namespace std;

int res = 1;

struct node {
    int data;
    node* left;
    node* right;
    int leftDepth;
};

void addNode(node *&t, int &data) {
    if (t == NULL) {
        node* temp = new node;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        temp->leftDepth = 0;
        t = temp;
        return;
    }
    if (t->data == data) return;
    if (data < t->data) return addNode(t->left, data);
    return addNode(t->right, data);
}

void calcLeftDepth(node* t, int &leftDepth) {
    if (t->left == NULL) {
        t->leftDepth = 0;
        return;
    }
    calcLeftDepth(t->left, leftDepth);
    t->leftDepth = ++leftDepth;
    
    if (t->right != NULL) {
    	int rLD = 0;
    	calcLeftDepth(t->right, rLD);
		}	
}

void printLeftDepth(node* t) {
	if (t == NULL) return;
	cout << t->data << " " << t->	leftDepth << endl;
	printLeftDepth(t->left);
	printLeftDepth(t->right);
}

void solve(node* t, int rightDepth = 1) {
	if (t == NULL) return;
	res = max(res, t->leftDepth + rightDepth);
	solve(t->right, rightDepth);
	solve(t->left, rightDepth + 1);
}

int lDS2(std::vector<int> arr)
{
    int n = arr.size();
    node* root = NULL;
    for (int i = 0; i < n; ++i) {
        addNode(root, arr[i]);
    }
    int leftDepth = 0;
  	calcLeftDepth(root, leftDepth);
  	solve(root);
    printLeftDepth(root);
    return res;
}

int main() {
	int a[] = {1, 1, 1, 1, 1};
	vector<int> arr(a, a + (sizeof(a) / sizeof(a[0])));
	cout << lDS2(arr);
	return 0;
}
