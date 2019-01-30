#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef unsigned long long ull;

pair <int, int> pFac(ull n) {
	pair <int, int> ans;
	int three = 0, two = 0;
	while (n % 3 == 0) {
		++three;
		n /= 3;
	}
	while (n % 2 == 0) {
		++two;
		n >>= 1;
	}
	return {-three, two};
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	ull a[n];
	fl (i, 0, n) cin >> a[i];

	pair <pair <int, int>, int> srt[n];
	fl (i, 0, n) srt[i] = {pFac(a[i]), i};

	sort(srt, srt + n);

	fl (i, 0, n) cout << a[srt[i].second] << " ";

    return 0;
}
