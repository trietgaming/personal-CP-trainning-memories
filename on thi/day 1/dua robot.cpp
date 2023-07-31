#include <iostream>
using namespace std;

int main(){
	
	int a[1000];
	int vuot=0;
	float t[1000];
	int n; cout<<"nhap so robot tham gia cuoc dua : ";cin>>n;
	int d; cout<<"nhap do dai duong dua (met) : ";cin>>d;
	for (int i=0;i<n;i++){
		cout<<"nhap van toc cua robot thu "<<i+1<<" : ";
		cin>>a[i];
		t[i]=float(d)/float(a[i]);
		for (int j=0;j<i;j++) t[i]=t[i]+1;
	}
	
	for (int i=1;i<n;i++){
		for (int j=i-1;j>=0;j--){
			if (t[i]<t[j]) vuot++;
		}

	}
	cout<<"so lan vuot nhau cua cac robot la: "<<vuot;
	return 0;
}
