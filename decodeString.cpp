#include <iostream>
#include <stack>

using namespace std;

bool isInt(char c) {
    int res = c - 48;
    return res >=0 && res <=9? true: false;
}

int charToInt(char c) {
	return c - '0';
}

int strToInt(string s) {
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		res += charToInt(s[i]);
		if (i + 1 != s.size()){
			res *= 10;
		}
	}
	return res;
}

string decodeString(string s)
{
    stack<int> brackets;
    string res;
    int size = 0;
    for (int i = 0, l = s.size(); i < l; ++i) {
        if (s[i] == '[') {
            brackets.push(i);
        }
        else if (s[i] == ']') {
        		int top = brackets.top();
        		brackets.pop();
        		string base = s.substr(top + 1, i - top - 1);
        		string temp = "";
        		int length = 0;
        		string tempL = "";
        		while (true) {
        			length++;
        			if (!isInt(s[top - length])) {
        				--length;
        				break;
							}
							tempL += s[top - length];	
						}
						int size = strToInt(tempL);
        		for (int j = 1; j <= size; j++) temp+= base;
            s= s.substr(0, top - length) + temp + s.substr(i + 1, s.size() - i - 1);
            l = s.size();
            i-= 3;
        }   
    }
    return s;
}

int main() {
	cout << decodeString("13[ab]");
	return 0;
}
