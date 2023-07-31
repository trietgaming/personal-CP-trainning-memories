#include <bits/stdc++.h>

using namespace std;

bool isValidChar(char c) {
    return     (c >= 'A' && c <= 'Z')
            || (c >= 'a' && c <= 'z')
            || (c >= '0' && c <= '9');
}

char toUpperCase(const char &c) {
    if (c >= 'a' && c <= 'z') return c - 32;
    return c;
}
char toLowerCase(const char &c) {
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}

string questionCorrection(string s)
{
    string res = "";
    int start = 0, end = s.length() - 1;
    for (int i = 0; i <= end; ++i) {
        if (isValidChar(s[i])) break;
        ++start;
    }
    for (int i = end; i > start; --i) {
        if (isValidChar(s[i])) break;
        --end;
    }
    char temp = toUpperCase(s[start]);
    if (isValidChar(temp)) res += temp;
    ++start;
    for (int i = start; i < end; ++i) {
        char c = s[i];
        if (isValidChar(c)) {
            res += toLowerCase(c);
            continue;
        }
        if (c == ',') {
            res += c;
            res += ' ';
            while (!isValidChar(s[i])) {
							++i;
						};
						--i;
            continue;
        }
        if (!isValidChar(s[i + 1])) {
            continue;
        }
        if (s[i + 1] != ' ' || s[i + 1] != ',')
        	res += ' ';
    }
    if (isValidChar(s[end]) && start < end) res += toLowerCase(s[end]);
    return res + '?';
}

int main() {
	
	string s;
	getline(cin, s);
	cout << questionCorrection(s);
	
	return 0;
}
