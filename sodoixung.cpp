#include <iostream>
using namespace std;

int dodai(long long n){
	long long dd=0;
	while (n>0){
		dd++;
		n=n/10;
	}
	return dd;
}

int sodoixung(long long n){
	int soam=0;
	if (n<0) 
	{
	soam=1;
	n=-n;
	}
	long long n1=0,m=1,dd=dodai(n);	
	for (long long i=1;i<dd;i++)
	m=m*10;
	while (n>0){
		n1=n1+(n%10)*m;
		m=m/10;
		n=n/10;
		
	
	
}
	if (soam==1)
	return -n1;else return n1;
}

int main(){
	
	long long a,b;
	cout<<"nhap so a: ";cin>>a;
	cout<<"nhap so b: ";cin>>b;
	long long a1=sodoixung(a),b1=sodoixung(b);
	cout<<"so doi xung cua "<<a<<" la: "<<a1<<endl;
	cout<<"so doi xung cua "<<b<<" la: "<<b1<<endl;
	cout<<"tong cua "<<a1<<" va "<<b1<<" la: "<<a1+b1;
	return 0;
}
