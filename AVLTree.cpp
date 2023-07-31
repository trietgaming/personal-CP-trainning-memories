#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

void insert(node *&t, const int &data) {
    if (t == NULL) {
        node* temp = new node;
        temp->left = NULL;
        temp->right = NULL;
        temp->data = data;
        t = temp;
        return;
    }
    if (data < t->data) return insert(t->left, data);
    insert(t->right, data);
}

void turnLeft(node *&t) {
    node *r = t->right;
    node *l = r->left;
    r->left = t;
    t->right = l;
    t = r;
}

void turnRight(node *&t) {
    node *l = t->left;
    node *r = l->right;
    l->right = t;
    t->left = r;
    t = l;
}

int nodeLevel(node *t) {
    if (t == NULL) return -1;
    return 1 + max(nodeLevel(t->left), nodeLevel(t->right));
}

bool isAVL(node *t) {
    if (t == NULL) return true;
    if (abs(nodeLevel(t->left) - nodeLevel(t->right)) > 1) return false;
    return isAVL(t->left) && isAVL(t->right);
}

void turnAVL(node *&t) {
    if (t == NULL) return;
    int leftLevel = nodeLevel(t->left);
    int rightLevel = nodeLevel(t->right);
    if (abs(leftLevel - rightLevel) <= 1) return;
    if (leftLevel > rightLevel) {
        if (nodeLevel(t->left->right) > nodeLevel(t->left->left)) {
            turnLeft(t->left);
        }
        turnRight(t);
    }
    else {
        if (nodeLevel(t->right->left) >  nodeLevel(t->right->right)) {
            turnRight(t->right);
        }
        turnLeft(t);
    }
    turnAVL(t->left);
    turnAVL(t->right);
    if (!isAVL(t)) turnAVL(t);
}

int count(node *t, int x) {
    if (t == NULL) return 0;
    return (t->data == x) + count(t->left, x) + count(t->right, x);
}

void printBT(const std::string& prefix, const node* t, bool isLeft)
{
    if (t == NULL) return;
    
    std::cout << prefix;
    std::cout << (isLeft ? "|--" : "L--");
    // print the value of the node
    std::cout << t->data << std::endl;
    // enter the next tree level - left and right branch
    printBT(prefix + (isLeft ? "|   " : "    "), t->right, true);
    printBT(prefix + (isLeft ? "|   " : "    "), t->left, false);
}

void printTree(const node* t)
{
    printBT("", t, false);
}

void deallocate(node *& t) {
	if (t == NULL) return;
	deallocate(t->left);
	deallocate(t->right);
	delete t;
	t = NULL;
}

int main() {

    node* root = NULL;

		int arr[] = {1,2,3,1,2,2,2};
		int x = 2;
		
		vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    for (int i = 0, n = v.size(); i < n; ++i) {
        insert(root, v[i]);
    }


    turnAVL(root);

    printTree(root);

    cout << count(root, x);

		deallocate(root);

    return 0;
}
