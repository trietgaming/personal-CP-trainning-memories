#include <iostream>
using namespace std;

int stp(float n){
	int a=n;
	if (a!=n) return 1 ;else return 0;	
}

int main(){
	
	float n; cin>>n;
	float mau=0;
	do {
		mau++;		
	} while (stp(n*mau)!=0);
	int tu=n*mau;
cout<<tu<<"/"<<mau;
	return 0;
}
