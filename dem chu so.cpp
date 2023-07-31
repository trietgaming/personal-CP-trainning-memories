#include <iostream>
using namespace std;

int main(){
	
	int n,c;cin>>n;
	int n1=n;
	
	while (n>=10){
		n=n/10;
		c++;
	}
	if (n<10)c++;
	printf("so %d co %d chu so",n1,c);
	
	return 0;
}
