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

	int cnt = 0, back = 0;
	fl (i, 0, n) {
		if (s[i] != 'x') back = i + 1;
		if (i - back >= 2) ++cnt;
	}

	cout << cnt;

    return 0;
}
