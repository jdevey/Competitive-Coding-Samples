#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	set <pair <char, int>> st;

	for (int i = 0; i < s.size(); ++i) {
		st.insert({s[i], i});
	}

	int vc[n] = {};
	int ii = 0;
	for (auto it = st.begin(); it != st.end(); ++it, ++ii) {
		if (ii >= k) vc[it->second] = it->first;
	}

	fl (i, 0, n) if (vc[i]) cout << (char)vc[i];

    return 0;
}
