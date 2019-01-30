#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

bool isPal(string s) {
	for (int i = 0; i < s.size(); ++i) if (s[i] != s[s.size() - i - 1]) return false;
	return true;
}

bool isHomo(string s) {
	for (int i = 0; i < s.size(); ++i) if (s[i] != s[0]) return false;
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	string s;
	cin >> s;

	if (isHomo(s)) return puts("0");
	if (isPal(s)) {
		cout << s.size() - 1 << endl;
		return 0;
	}
	cout << s.size() << endl;

    return 0;
}
