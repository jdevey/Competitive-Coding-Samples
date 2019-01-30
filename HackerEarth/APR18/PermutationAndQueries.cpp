#include <bits/stdc++.h>

#define MD 1000000007ll
#define fl(i,a,b) for(int(i)=(a);(i)<(b);++i)

using namespace std;

typedef long long ll;

void ext(ll a, ll b, ll& x, ll& y) {
    if (!b) {
        x = 1;
        y = 0;
        return;
    }
    ext(b, a % b, x, y);
    ll temp = x - a / b * y;
    x = y;
    y = temp;
}

ll modInv(ll a) {
    ll x, y;
    ext(a, MD, x, y);
    return x < 0 ? x + MD : x;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll** dp = new ll*[501], maxx[501], finVal[501], fac[501], facInv[501];
	fac[0] = 1;
	fl (i, 1, 501) fac[i] = fac[i - 1] * i % MD;
	facInv[0] = 1;
	fl (i, 1, 501) facInv[i] = modInv(i) * facInv[i - 1] % MD;
	fl (i, 0, 501) dp[i] = new ll[i * (i + 1) / 2 + 1];
	memset(dp, 0, sizeof(dp));
	dp[1][0] = 1;
	maxx[1] = 1;
	finVal[1] = 1;
	fl (i, 2, 501) {
		dp[i][0] = 1;
		fl (j, 1, i * (i - 1) / 2 + 1) dp[i][j] = (dp[i][j - 1] + (dp[i][j - 1] - (j == 1 ? 0 : dp[i][j - 2])) + (j > (i - 2) * (i - 1) / 2 ? 0 : dp[i - 1][j] - dp[i - 1][j - 1]) - (j >= i ? j == i ? 1 : dp[i - 1][j - i] - dp[i - 1][j - i - 1] : 0) + 10 * MD) % MD;
		maxx[i] = dp[i][i * (i - 1) / 2];
		finVal[i] = (maxx[i] - dp[i][i * (i - 1) / 2 - 1] + MD) % MD;
	}

	ll q, n, k;
	cin >> q;
	while (q--) {
		cin >> n >> k;
		ll sm = 0;
		fl (i, 1, n + 1) sm = (sm + fac[n] * facInv[i] % MD * (n - i + 1) % MD * (k > i * (i - 1) / 2 ? maxx[i] : dp[i][k])) % MD;
		cout << sm << endl;
	}

	return 0;
}

