#include <iostream>
using namespace std;

//kiem tra mot so thuc do co phai la so thap phan hay khong
int stp(float n){
	int a=n;
	if (a!=n) return 1 ;else return 0;	
}

int main(){
	int a=1,b=6,c=5,d=12;
	float n=float(a)/float(b)-float(c)/float(d);
	cout<<"n= "<<n<<endl;
	
	//doi tu so thap phan sang phan so
	float mau=0;
	do {
		mau++;		
	} while (stp(n*mau)!=0);
	int tu=n*mau;
cout<<"phan so cua n la: "<<tu<<"/"<<mau;
	return 0;
}
