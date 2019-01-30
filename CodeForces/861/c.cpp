#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	string s;
	cin >> s;

	int run = 0;
	string build;

	fl (i, 0, s.size()) {
		if (!isVowel(s[i])) ++run;
		else run = 0;
		if (i > 1 && !isVowel(s[i]) && run > 2 && s[i] == s[i - 1] && s[i - 1] == s[i - 2]) --run;
		if (run > 2) {
			run = 1;
			build += " ";
			build += s[i];
		}
		else build += s[i];
	}

	cout << build;

    return 0;
}
