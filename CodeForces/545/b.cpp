#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	string s, t;
	cin >> s >> t;

	int cnt = 0, sz = s.size();
	fl (i, 0, sz) if (s[i] != t[i]) ++cnt;

	if (cnt & 1) return puts("impossible");

	cnt >>= 1;
	int prog = 0;
	string ans;

	for (int i = 0; i < sz; ++i) {
		if (prog < cnt) {
			ans += s[i];
			if (s[i] != t[i]) ++prog;
		}
		else {
			ans += t[i];
		}
	}

	cout << ans << endl;

    return 0;
}
