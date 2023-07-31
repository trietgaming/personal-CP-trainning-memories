#include <iostream>
using namespace std;

int snt(long long n){
	int uoc=0;
	for (int i=1;i<=n;i++){
		if (n%i==0) uoc++;
	}
	if (uoc==2) return 1;else return 0;
}

int main(){
	long long n,k;
	do {
		cout<<"nhap n: ";
		cin>>n;
		if (n<1||n>10000000000000000) cout<<"vui long nhap n>=1 va n<=10^16!\n";
	} while (n<1||n>10000000000000000);
	cout<<"nhap k: ";
	cin>>k;
	int i=1,j=1,dieukien=0;
	while (n>0){
		
		if (snt(i)==1){
			if (snt(i+k)==1) {
			dieukien=1;
			cout<<"("<<i<<","<<i+k<<")";
		}
		}
		if (i+k>=n) break;
		i++;
		
	}
	if (dieukien==0)cout<<"Khong co cap so nguyen to sinh doi nao tu 1 den " <<n<<" thoa man q-p="<<k;
	return 0;
}
