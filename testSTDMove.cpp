#include <iostream>

using namespace std;

template <typename T>
void _swap(T *&a, T *&b) {
	T *temp = a;
	a = b;
	b = temp;
}

template <typename T>
void print(T *a, T *b) {
	cout << "a: " << *a << " - b: " << *b << endl;
}

int main() {
	
	int *a = new int(10);
	int *b = new int(20);
	
	print(a, b);
	_swap(a, b);
	print(a, b);
	
	delete a;
	delete b;
	
	return 0;
}
