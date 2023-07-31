#include <iostream>
using namespace std;
int giaithua(int n){
	int gt=1;
	for (int i=1;i<=n;i++)gt=gt*i;
	return gt;	
}
int main(){
	int n;cin>>n;
	int s;
	for (int i=1;i<=n;i++)s=s+giaithua(i);
	cout<<s;
}
