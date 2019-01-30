#include <bits/stdc++.h>

#define MD 1000000007ULL
#define fl(i,a,b) for(int(i)=(a);(i)<(b);++(i))

using namespace std;

typedef unsigned long long ull;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ull n, m;
	scanf("%llu %llu", &n, &m);
	ull a[n], dp[n];
	fl (i, 0, n) scanf("%llu", &a[i]);
	dp[0] = 1ULL;
	printf("1\n");

	fl (i, 1, n) {
		ull sm = 1;
		fl (j, 1, i) if (a[i] % a[j] == 0) sm = (sm + dp[j]) % MD;
		dp[i] = sm % MD;
		printf("%llu\n", dp[i]);
	}

	return 0;
}
