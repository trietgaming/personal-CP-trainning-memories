#include <iostream>
using namespace std;

void add_zero(string& s, int max){
	while (s.length()<max) s.insert(0,1,'0');
}

short ctoi(char c) {
	return c-'0';
}

char stoc(short s) {
	switch (s){
		case 1:
			return '1';
			break;
		case 2:
			return '2';
			break;
		case 3:
			return '3';
			break;
		case 4:
			return '4';
			break;
		case 5:
			return '5';
			break;
		case 6:
			return '6';
			break;
		case 7:
			return '7';
			break;
		case 8:
			return '8';
			break;
		case 9:
			return '9';
			break;
		case 0:
			return '0';
			break;
	}
}

string s_plus(string s1, string s2){	
	if (s1.length()>s2.length()) add_zero(s2, s1.length());
	else if (s2.length()>s1.length()) add_zero(s1, s2.length());
	string result = "";
	bool keep=false;
	for (int i = s1.length()-1; i>=0; i--){
		short temp = ctoi(s1[i]) + ctoi(s2[i]);
		if (keep) temp+=1;
		result.insert(0,1,stoc(temp%10));
		if (temp/10!=0) keep = true; else keep=false;
	}
	return result;
}

string s_multiply(string s1, int n){
	for (int i = 1; i<=n; i++){
	
		cout<<s_plus(s1,s1);
	}
	return s1;
}

string to_string(long long n, string result){
	if (n<=0){
		return result;
	} ;
	
	switch (n%10){
		case 1: 
			result.insert(0,1,'1');
			break;
		case 2: 
			result.insert(0,1,'2');
			break;
		case 3: 
			result.insert(0,1,'3');
			break;
		case 4: 
			result.insert(0,1,'4');
			break;
		case 5: 
			result.insert(0,1,'5');
			break;
		case 6: 
			result.insert(0,1,'6');
			break;
		case 7: 
			result.insert(0,1,'7');
			break;
		case 8: 
			result.insert(0,1,'8');
			break;
		case 9: 
			result.insert(0,1,'9');
			break;
		case 0: 
			result.insert(0,1,'0');
			break;				
	}
	n/=10;
	return to_string(n, result);
}

int main(){
	
	long long n;
	cout<<s_plus("153","153")<<endl;
	cout<<s_multiply("5",5);
	return 0;
}
