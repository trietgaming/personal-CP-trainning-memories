#include <iostream>
using namespace std;

int main(){
	
	int n;
	do{
		cin>>n;
		if (n>=100)cout<<"vui long nhap n<100\n";
		
	}while (n>=100);
	
	long long a[100],b[100];
	for (int i=0;i<n;i++){
		cout<<"nhap so thu "<<i+1<<": ";
		cin>>a[i];
		b[i]=0;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (a[i]%a[j]==0)b[i]++;
		}
	}	
	int max=b[0],stt;
	for (int i=0;i<n;i++){
		if (b[i]>max){
			max=b[i];
			stt=i;
		}
	}
	cout<<"so co nhieu uoc nhat : "<<a[stt];
	return 0;
}
