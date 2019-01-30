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

	ll ans = 0;
	fl (i, 0, s.size()) ans |= (s[i] == 'B') * (1ll << i);

	cout << ans;

    return 0;
}
