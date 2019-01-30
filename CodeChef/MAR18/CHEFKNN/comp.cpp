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
 
ll compFIJ(ll* fArr, ll n, ll j) {
	ll s = fArr[j];
	fl (h, 1, j)
		s = (s + fArr[h] * (n - j + 1)) % MD;
	return s;
}
 
ll compAns(ll* fArr, ll n) {
	ll s = 0;
	fl (i, 0, n)
		s = (s + fArr[i + 1] * (((n - i) * ((n - i - 1) * TWOINV % MD) + 1) % MD)) % MD;
	return s;
}
 
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
 
		//auto dp = new ll*[k];
		//fl (i, 0, k + 1) dp[i] = new ll[n + 1];
		ll dp[k][n + 1];
 
		fl (i, 1, n + 1) dp[1][i] = n - i + 1;
		fl (i, 2, k) {
			fl (j, 1, n + 1) {
				dp[i][j] = compFIJ(dp[i - 1], n, j);
			}
		}
		cout << compAns(dp[k - 1], n) << endl;
		//fl (i, 0, k) delete dp[i];
		//delete dp;
	}
 
	return 0;
}
