#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void xoakitu(char* s,int vitri){
	for (int i=vitri;i<strlen(s);i++) s[i]=s[i+1];
}

void themkitu(char* s,int vitri,char kitu){
	s[strlen(s)+1]='\0';
	for (int i=strlen(s);i>vitri;i--) s[i]=s[i-1];
	s[vitri]=kitu;
}

void xoakhoangtrangthua(char* s){
	for (int i=0;i<strlen(s);i++){
		if (s[i]==' ') while (s[i+1]==' ') xoakitu(s,i);
	}
}

void ngatcau1(char* s){
	for (int i=0;i<strlen(s);i++){
		if (s[i]=='.' || s[i]==',' || s[i]=='?' || s[i]=='!' || s[i]==':' || s[i]==';'){
			
			if (s[i-1]==' ') xoakitu(s,i-1);
			
		}
	}
}

void ngatcau2(char* s){
	for (int i=0;i<strlen(s);i++){
		if (s[i]=='.' || s[i]==',' || s[i]=='?' || s[i]=='!' || s[i]==':' || s[i]==';'){
			
			
			if (s[i+1]!=' ') themkitu(s,i+1,' ');
		}
	}
}

void viethoa(char*s){
	for (int i=0;i<strlen(s);i++){
		
		if (s[i]=='.' || s[i]=='!' || s[i]=='!' || s[i]==':')
		if (s[i+2]>='a' && s[i+2]<='z') s[i+2]-=32;
	}
}

void ngoacdon(char*s){
	for (int i=0;i<strlen(s);i++){
		if (s[i]=='('){
			
			if (s[i-1]!=' ') themkitu(s,i-1,' ');
			
		}
	}
	for (int i=0;i<strlen(s);i++){
		if (s[i]=='('){
			
			if (s[i+1]==' ') xoakitu(s,i+1);
			
		}
	}
	for (int i=0;i<strlen(s);i++){
		if (s[i]==')'){
			
			if (s[i-1]==' ') xoakitu(s,i-1);
			
		}
	}
	for (int i=0;i<strlen(s);i++){
		if (s[i]==')'){
			if (s[i+1]=='.' || s[i+1]==',' || s[i+1]=='?' || s[i+1]=='!' || s[i+1]==':' || s[i+1]==';') ;else
			if (s[i+1]!=' ') themkitu(s,i+1,' ');
			
		}
	}
}

int main(){
	char s[1000];
	do{
	cout<<"nhap vao van ban: ";
	gets(s);
	if (strlen(s)>255) cout<<"vui long nhap van ban khong qua 255 ki tu\n";
}
	while (strlen(s)>255);
	xoakhoangtrangthua(s);
	ngatcau1(s);
	ngatcau2(s);
	ngoacdon(s);
	viethoa(s);
	if (s[0]>='a' && s[0]<='z') s[0]-=32;
	/*Khoang trang Dau cham . Dau phay , Dau cham phay ; Dau cham than ! Dau hoi ( ngoac don )*/
	cout<<"Van ban chuan la:\n";
	for (int i=0;i<strlen(s);i++) cout<<s[i];
	
	return 0;
}
