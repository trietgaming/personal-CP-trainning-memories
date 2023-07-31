#include <iostream>
using namespace std;

int main(){
	
	long long n;cin>>n;
	long long* f;
	f = new long long[n];
	if (n==1) cout<<n; else 
	if (n==2) cout<<"1 1"; else 
	{f[0]=1;f[1]=1;
	
	for (long long i=2;i<n;i++){
		f[i] = f[i-1]+f[i-2];
			
	}
	
	for (long long i=0;i<n;i++){
		cout<<f[i]<<" ";	
	}
	}
	delete[]f;
	return 0;
}
