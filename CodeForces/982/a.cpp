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

	if (n == 1) {cout << (s[0] == '0' ? "no" : "yes"); return 0;}

	bool good = true;

	fl (i, 1, n - 1) {
		if (i == 0 && s[i] == '0' && s[i + 1] == '0') good = false;
		else if (i == n - 1 && s[i] == '0' && s[i - 1] == '0') good = false;
		else if (s[i] == '0' && s[i - 1] == '0' && s[i + 1] == '0') good = false;
	}

	cout << (good ? "yes" : "no");

    return 0;
}
