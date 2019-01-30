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
	string s[n];
	fl (i, 0, n) cin >> s[i];

	set <string> m;

	fl (i, 0, n) {
		int cs[26] = {};
		for (auto x : s[i]) {
			++cs[x - 'a'];
		}
		string ans;
		fl (j, 0, 26) {
			if (cs[j]) ans += j + 'a';
		}
		sort(ans.begin(), ans.end());
		if (m.find(ans) == m.end()) m.insert(ans);
	}

	cout << m.size();

    return 0;
}
