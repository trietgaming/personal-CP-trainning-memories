#include <bits/stdc++.h>

using  namespace std;

using ll = long long;
const string FNAME = "COMSTR";
const int MAXM = 100000;

struct InitChar {
  char c;
  int ind;
  InitChar(char ch = 'A', int i = 0): c(ch), ind(i) {};
};

int diff_at[MAXM][26];
int total_diff[MAXM];
int appear[MAXM];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

 	freopen((FNAME + ".inp").c_str(), "r", stdin);
 	freopen((FNAME + ".ans").c_str(), "w", stdout);

	ll m, m1, m2, r;
	cin >> m >> m1 >> m2 >> r;

	string s;
	cin >> s;

	/// Subtask 1
	if (r == 0) {
		string s1 = s.substr(m2, m1), s2 = s.substr(0, m2);
		string fibo = s2 + s1;
		while (fibo.length() < m) {
			string temp = s2;
			s2 = fibo;
			fibo += temp;
		}
		ll diff = 0;
		for (int i = 0, e = min(fibo.length(), s.length()); i < e; ++i) {
			diff += fibo[i] != s[i];
		}
//		diff += abs(static_cast<int>(fibo.length()) - static_cast<int>(s.length()));
//		cerr << diff;
//		cerr << endl << s << "\n" << fibo;
		cout << diff;
		return 0;
	}
	/// Subtask 2
	/// 0 - A, 1 - B
	if (r == m1 + m2 && r <= 10 && m <= 1001) {
		unsigned long long maskEnd = (1 << r) - 1;
		ll res = 1000000000000;
		for (unsigned long long i = 0; i <= maskEnd; ++i) {
			string s1 = "", s2 = "";
			for (int j = m2; j < m2 + m1; ++j) {
				if (i & (1 << j)) {
					s1 += 'B';
				} else {
					s1 += 'A';
				}
			}
			for (int j = 0; j < m2; ++j) {
				if (i & (1 << j)) {
					s2 += 'B';
				} else {
					s2 += 'A';
				}
			}
			string fibo = s2 + s1;
			while (fibo.length() < m) {
				string temp = s2;
				s2 = fibo;
				fibo += temp;
			}
			ll diff = 0;
			for (int l = r, e = min(fibo.length(), s.length()); l < e; ++l) {
				diff += fibo[l] != s[l];
			}
//			if (diff < res) {
//				cerr << fibo << ": " << diff << "\n";
//			}
			res = min(res, diff);
		}
		cout << res;
		cerr << res;
		return 0;
	}

	return 0;
}
