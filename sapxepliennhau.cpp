#include <iostream>
using namespace std;

int sodau(int n){
	while (n>=10){
		n=n/10;
	}
	return n;
}

int main(){
	int n;cin>>n;
	int a[n];
	for (int i=0;i<n;i++){
		cout<<"nhap so thu "<<i+1<<": ";
		cin>>a[i];
	}
	
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if ( a[i] < a[j] ){
				int tam=a[j];
				a[j]=a[i];
				a[i]=tam;
			}
		}		
	}
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if ( sodau(a[i] ) < sodau(a[j] )){
				int tam=a[j];
				a[j]=a[i];
				a[i]=tam;
			}
			if ( sodau(a[i] ) == sodau(a[j] )&& a[i]<a[j] ){
				int tam=a[j];
				a[j]=a[i];
				a[i]=tam;
		}	
	}
}
	for (int i=0;i<n;i++){
		cout<<a[i];
	}					
	return 0;
}
