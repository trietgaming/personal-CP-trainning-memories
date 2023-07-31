#include <iostream>
using namespace std;

int doday(long long n){
	int dd=0;
	while (n>0) {
		n=n/10;dd++;
	}
	return dd;
}

int docao(long long n){
	int dc=0;
	while (n>0) {
		dc+=n%10;n=n/10;
	}
	return dc;
}

int main(){
	long long n;
do	{
	cout<<"nhap vao mot so tu nhien N: ";
	cin>>n;
	if (n<1 || doday(n)>= 16) {
	cout<<"vui long nhap n>=1 va n<10^16\n";
	}
}while (n<1 || doday(n)>= 16);
	cout<<"do day cua "<<n<<" la: "<<doday(n);
	cout<<"\ndo cao cua "<<n<<" la: "<<docao(n);
	return 0;
}
