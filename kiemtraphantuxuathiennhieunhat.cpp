#include <iostream>
using namespace std;

int main(){
	cout<<"nhap do dai cua mang: ";
	int n; cin>>n;
	int a[1000],b[1000];
	for (int i=0;i<n;i++){
		cout<<"nhap so thu "<<i+1<<": ";
		cin>>a[i];
	}
	int xh=0,bn=1;
	for (int i=0;i<n;i++){
		
		for (int j=0;j<n;j++){
			
			if (a[i]==a[j]) xh++ ;
		}
		b[i]=xh;
		xh=0;
	}
	
	for (int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if (b[i]<b[j]){
				int tam1 =a[i];
				a[i]=a[j];
				a[j]=tam1;
				int tam2 =b[i];
				b[i]=b[j];
				b[j]=tam2;
			}
		}
	}
	
	cout<<"phan tu xuat hien nhieu nhat la: ";
		for (int i=0;i<n;i++){
		if (a[i]!=a[i-1]&&b[i]==b[0]) cout<<a[i]<<" ";
	}
	cout<<endl<<"xuat hien "<<b[0]<<" lan";
	return 0;
}
