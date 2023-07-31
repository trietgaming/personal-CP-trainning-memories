#include <iostream>
using namespace std;

int main(){
	cout<<"Nhap vao xau S: ";
	string s;getline(cin,s);
	int tongxh=0;
	for (int i=0;i<s.size();i++){
		
		int xh=0;
		for (int j=i;j<s.size();j++){
			if (s[i]==s[j]) xh++;
		}
		if (xh==1) tongxh++;
	}
	//tim so ki tu khac nhau, test = AbcabA12321ABCcba
	cout<<"So ki tu khac nhau: "<<tongxh;
	int doixung=0;
	int dau,duoi=0;
	for (int i=0;i<s.size();i++){
		for (int j=i+1;j<s.size();j++){
			if (s[i]==s[j]) {
				
				int y=j-1;
				for (int x=i+1;x<=i+((j-i)/2);x++){
					
					if (s[x]!=s[y]) break;
				
						if (x==y || (x+1==y && s[x]==s[y]) ) {
							if (duoi-dau<j-i) {
								dau=i;
								duoi=j;
							}	
						break;}
		
							
					y--;}
				
			}
		}
	}
	//xau x la xau doi xung trong xau s
	
	cout<<"\nDo dai xau X: ";
	cout<<(duoi-dau)+1;
	cout<<"\nXau X la: ";
	for (int i=dau;i<=duoi;i++) cout<<s[i];
	return 0;
}
