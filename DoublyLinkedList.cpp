#include <iostream>

using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

class DoublyLinkedList {
    private:
        node* createNode(int x, node* prev = NULL, node* next = NULL) {
            node* temp = new node;
            temp->prev = prev;
            temp->next = next;
            temp->data = x;
            ++size;
            return temp;
        }
        
    public:
        node* tail;
        node* head;
        int size;
        DoublyLinkedList() {
        		size = 0;
        		head = NULL;
        		tail = NULL;
        }
        node* pushBack(int x) { 
            node* temp = createNode(x, tail);
            if (tail) tail->next = temp;
            tail = temp;
            if (head == NULL) head = temp;
            return tail;
        }
};

int main() {
    DoublyLinkedList l;
    int n; cin>> n;
    for (int i = n; i >= 1; --i) {
        l.pushBack(i);
    }
	  node* p = l.head;
	  for (int i = 1; i < l.size; ++i) {
	      cout << p->data << " ";
	      p = p->next;
	  }
	  for (int i = l.size; i > 0; --i) {
	      cout << p->data << " ";
	      p = p->prev;
	  }
}

