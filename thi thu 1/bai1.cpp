#include <iostream>
using namespace std;

int gttd(int n){
	if (n<0)return -n;
	if (n>=0) return n;
	
}

int main(){
	
	int a,b,c;
	do{
		cin>>a;
		if (gttd(a)>1000)cout<<"vui long nhap so hop le!\n";
	} while (gttd(a)>1000);
	do{
		cin>>b;
		if (gttd(b)>1000)cout<<"vui long nhap so hop le!\n";
	} while (gttd(b)>1000);
	do{
		cin>>c;
		if (gttd(c>1000))cout<<"vui long nhap so hop le!\n";
	} while (gttd(c)>1000);
	
	if (a*b >a*c && a*b >c*b) cout<<a*b;
	if (a*c >a*b && a*c >c*b) cout<<a*c;
	if (c*b >a*c && c*b >a*b) cout<<c*b;
	
	return 0;
}
