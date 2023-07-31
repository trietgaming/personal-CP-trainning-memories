#include <iostream>


using namespace std;

int songuyento(int n){
	int snt=0;
	for (int i=1;i<=n;i++){
		if (n%i==0) snt++;
	}
	if (snt==2)return 1;else return 0;
}
int main (){
	int n,b=0;cin>>n;
	int a[n];
	for (int i=1;i<=n;i++){
		int j=i;
		while (j>=10 && songuyento(j)==1) j=j/10;
		if (songuyento(j)==1) {
		a[b]=i; b++;}
	}
	for (int i=0;i<b;i++) cout<<a[i]<<" ";
	return 0;
}
