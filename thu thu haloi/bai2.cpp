#include <iostream>
using namespace std;


int main(){
	
	int n;
	cout<<"nhap n: ";cin>>n;
	int* a;
	a = new int[n];	
	int* b;
	b = new int[n];
	for (int i=0;i<n;i++){
		if (i<2) a[i]=1;else
		a[i]=a[i-2]+a[i-1];
		a[i]=a[i]%100;
	}
	cout<<"so hang thu "<<n<<" trong day moi la: "<<a[n-1];
	int dif=0;
	for (int i=0;i<n;i++){
		b[i]=1;
		for (int j=i+1;j<n;j++){
			if (a[i]==a[j]) b[i]++;
		}
		if (b[i]==1) dif++;
	}

	cout<<endl<<dif;
	delete[] a; delete[] b;
	return 0;
}
