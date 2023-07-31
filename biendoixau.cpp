#include <iostream>
using namespace std;

int main(){
	
	string s; cout<<"nhap xau s: "; getline(cin,s);
	int k; cout<<"nhap k: ";cin>>k;
	int p[k],q[k];
	
	for (int i=0;i<k;i++){
		
		do
		{
			
		cout<<"nhap p"<<i+1<<": ";cin>>p[i];
		
		} while (p[i]>s.size()&&p[i]>0);
		
		do
		{
			
		cout<<"nhap q"<<i+1<<": ";cin>>q[i];cout<<endl;
		
		} while (q[i]>s.size()&&q[i]>0);
	
	char tam=s[p[i]-1];	
	s[p[i]-1]=s[q[i]-1];
	s[q[i]-1]=tam;
	
	}
	cout<<s;
	
	
	return 0;
}
