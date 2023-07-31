#include <iostream>
using namespace std;

int gttd(long long n){
	if (n<0) return -n; else return n;
}

int main(){
	
	long int a,b,c,d;
	cout<<"nhap a/b: ";cin>>a>>b;
	cout<<"nhap c/d: ";cin>>c>>d;
	long long mau = b*d;
	long long tu =a*d-b*c;
	long int i=1;
	while (i>0){
		i++;
		if (tu % i ==0 && mau % i == 0) {
			tu=tu/i;
			mau=mau/i;
			i=1;
		}
		if (i>gttd(mau) || i>gttd(tu)) break;
	}
	cout<<"hieu cua "<<a<<"/"<<b<<" va "<<c<<"/"<<d<<" la : "<<tu<<"/"<<mau;
	return 0;
}
