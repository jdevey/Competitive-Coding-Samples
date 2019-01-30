#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int getSum(multiset <int>& ms, int start) {
	int sm = 0;
	for (auto rit = ms.rbegin(); rit != ms.rend(); ++rit) {
		if (start == 0 || *rit < start) return sm;
		sm += start;
		if (start & 1) return sm;
		start >>= 1;
	}
	return sm;
}

int find(multiset <int>& ms) {
	int top = *ms.rbegin();
	int mx = 0;
	for (int i = 0; i <= top; ++i) {
		int res = getSum(ms, i);
		mx = max(mx, res);
	}
	return mx;
}

int main() {

	int n;
	scanf("%d", &n);
	int a[n];
	fl (i, 0, n) scanf("%d", &a[i]);

	map <int, int> m;
	fl (i, 0, n) ++m[a[i]];

	multiset <int> ms;
	for (auto x : m) ms.insert(x.second);

	cout << find(ms);

    return 0;
}
