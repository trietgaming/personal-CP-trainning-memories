#include <iostream>
using namespace std;

int dodai(long long n){
	int dd=0;
	while (n>0){
		n=n/10;
		dd++;
	}
	return dd;
}

void xoa(long long*a,int dd,int vitrikitu){
	for (int i=vitrikitu;i<dd;i++){
		a[i]=a[i+1];
	}
}

int main(){
	
	long long n;
	cout<<"nhap n: ";cin>>n;
	long long k;
	cout<<"nhap k: ";cin>>k;
	long long* a;
	long long dd=dodai(n);
	a = new long long[dd];
	int m=1,dieukien=0,dieukien2=0;
	for (int i=dd-1;i>=0;i--){
		a[i]=n%10;
		n=n/10;	
	}
	
	cout<<"so lon nhat khi xoa "<<k<<" chu so la: ";
	for (int i=0;i<dd;i++)cout<<a[i];
	
	delete[] a;
	return 0;
}
