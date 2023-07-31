#include <iostream>
using namespace std;

bool isPrime(int n){
	int temp =0 ;
	for (int i=1;i<=n;i++){
		
		if (n%i==0){
			temp++;
		}
					
	}
	if (temp==2) {
	return true;
	}
	else return false; 
}

int main(){
	
	int n;cin>>n;
	int* a;
	a = new int[n];
	
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for (int i=0;i<n;i++){

		if (isPrime(a[i])){
			cout<<a[i]<<" vitri: "<<i+1<<endl;}

	}
	delete[] a;
	return 0;
}
