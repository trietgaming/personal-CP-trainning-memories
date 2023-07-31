#include <iostream>
using namespace std;

int tongsole(int a,int b){
	int tong=0;
	for (int i=a;i<=b;i++){
		if (i%2!=0) tong+=i;
	}
	return tong;
}

int stp(float n){
	int a=n;
	if (a!=n) return 1 ;else return 0;	
} 

int main(){
	
	int a,b;
	cout<<"nhap so a: ";cin>>a;
	cout<<"nhap so b: ";cin>>b;
	cout<<"tong cac so le tu "<<a<<" den "<<b<<" la: "<<tongsole(a,b)<<endl;
	float a1=float(a),b1=float(b);
	float n=a1/b1;
	float mau=0;
	do {
		mau++;		
	} while (stp(n*mau)!=0);
	int tu=n*mau;
	cout<<"phan so toi gian cua "<<a<<"/"<<b<<" la: "<<tu<<"/"<<mau<<endl;
	int dieukien=0;
	for (int i=1;i<=a;i++){
		for (int j=1;j<=a-i;j++){
			if (i+j==a && i*j==b){
			
			cout<<"hai so p va q la: "<<i<<" "<<j;
			dieukien=1;
			break;
		}
		if (dieukien==1) break;
		}
	}
	if (dieukien==0) cout<<"khong co so p va q nao thoa man p + q = a va p * q = b";
	return 0;
}
