#include <iostream>
using namespace std;

int main(){
	
	int a,b,v;cin>>a>>b>>v;
	int qd=0,ngay=0,sum=0;
	while (qd<v){
		
		qd+=a-b;
		if (qd==v);else
		ngay++;
		
	}
	
	 int tt,tl;
	 while (tt<v){

		tt+=a-b;
	 	if (tt>=v) break;
	 	if (tt<v) sum+=a-(v-qd);
}
sum+=b*(ngay-1);
	cout<<ngay<<" "<<sum;
	return 0;
}
