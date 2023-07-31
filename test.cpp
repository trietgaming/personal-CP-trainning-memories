#include <iostream>
using namespace std;

int main(){
	
	int a[1000];
	int n;cout<<"nhap so phan tu cua mang: ";cin>>n;
	for (int i=0;i<n;i++){
		cout<<"nhap phan tu thu "<<i+1<<": ";
		cin>>a[i];
	}
	
	return 0;
}
