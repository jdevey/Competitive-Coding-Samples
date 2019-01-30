#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

ll compScore(int* a, int ind) {
	int cnt = a[ind];
	a[ind] = 0;
	fl (i, 0, 14) {
		a[i] += cnt / 14;
	}
	cnt %= 14;
	for (int i = (ind + 1) % 14; cnt; --cnt, i = (i + 1) % 14) {
		++a[i];
	}
	ll sm = 0;
	fl (i, 0, 14) if (~a[i] & 1) sm += a[i];
	return sm;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int a[14];
	fl (i, 0, 14) cin >> a[i];

	int aCopy[14];
	fl (i, 0, 14) aCopy[i] = a[i];

	ll mxScore = 0;
	fl (i, 0, 14) {
		mxScore = max(mxScore, compScore(a, i));
		fl (j, 0, 14) a[j] = aCopy[j];
	}

	cout << mxScore;

    return 0;
}
