#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define MD 163577857LL
#define TWOINV 81788929LL
#define fl(i,m,n) for(long long (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

	#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
	#endif

	ll t, n, k;
	cin >> t;

	while (t--) {
		cin >> n >> k;

		if (k == 1) {
			cout << (n * (n + 1) % MD) * TWOINV % MD << endl;
			continue;
		}

		auto dp = new ll*[k], pref = new ll*[k];
		fl (i, 0, k) {dp[i] = new ll[n + 1]; pref[i] = new ll[n + 1];}
		fl (i, 1, n + 1) dp[1][i] = n - i + 1;
		fl (i, 0, k) {dp[i][1] = n; pref[i][0] = 0; pref[i][1] = n;}
		fl (i, 1, n + 1) pref[1][i] = (pref[1][i - 1] + dp[1][i]) % MD;
		fl (i, 2, k) fl (j, 2, n + 1) {dp[i][j] = (pref[i - 1][j - 1] * (n - j + 1) + dp[i - 1][j]) % MD; pref[i][j] = (pref[i][j - 1] + dp[i][j]) % MD;}

		ll s = 0;
		fl (i, 0, n) s = (s + dp[k - 1][i + 1] * (((n - i) * ((n - i - 1) * TWOINV % MD) + 1) % MD)) % MD;
		cout << s << endl;

		fl (i, 0, k) {delete dp[i]; delete pref[i];}
		delete dp; delete pref;
	}

	return 0;
}


