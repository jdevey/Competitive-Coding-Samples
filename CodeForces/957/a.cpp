#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	string s;
	cin >> s;

	fl (i, 0, n - 1) if (s[i] != '?' && s[i] == s[i + 1]) {
		cout << "No" << endl;
		return 0;
	}

	bool good = false;
	if (s[0] == '?' || s[n - 1] == '?') good = true;

	fl (i, 1, n - 1) if (s[i] == '?' && (s[i - 1] == '?' || s[i + 1] == '?' || s[i - 1] == s[i + 1])) good = true;

	cout << (good ? "Yes" : "No") << endl;

    return 0;
}
