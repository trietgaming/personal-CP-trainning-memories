#include <iostream>
using namespace std;

void sapxeptd(int* p,int n){
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if (p[i]>p[j]){
				int tam =p[i];
				p[i]=p[j];
				p[j] = tam;
			}
		}
	}
}

void xuatchuoi(int* p,int n){
	for (int i=0;i<n;i++){
		cout<<p[i]<<" ";
	}
}

int main(){
	
	int n;cin>>n;
	int a[1000],chan[1000],le[1000];
	for (int i=0;i<n;i++){
		cout<<"nhap so thu "<<i+1<<": ";
		cin>>a[i];
	}
	cout<<"day vua nhap la: ";xuatchuoi(a,n);
	sapxeptd(a,n);
	int l=0,c=0;
	for (int i=0;i<n;i++){
		if (a[i]%2==0) {
			chan[c]=a[i];
			c++;
		} else {
			le[l]=a[i];
			l++;
		}
	}
	cout<<"\nday cac so le la: ";xuatchuoi(le,l);
	cout<<"\nday cac so chan la: ";xuatchuoi(chan,c);
	
	return 0;
}
