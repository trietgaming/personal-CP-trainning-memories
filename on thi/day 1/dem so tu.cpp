#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main(){
	
	char s[1000];
	gets(s);
	int i=0,tu=0;
	if (s[0]!=' ') tu++; 
	for (int i=1;i<=strlen(s);i++) if (s[i-1]==' ' && s[i]!=' ') tu++;
	cout<<"so tu la: "<<tu; 
	
	return 0;
}
