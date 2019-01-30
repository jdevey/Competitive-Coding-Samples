#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

ll getMX(pair <ll, ll>* a, ll sz, ll pos) {
	if (pos == sz - 1) return a[sz - 2].first;
	else return a[sz - 1].first;
}

ll getSM(pair <ll, ll>* a, ll sz, ll sm, ll pos) {
	if (pos == sz - 1) return sm - a[sz - 1].first - a[sz - 2].first;
	else return sm - a[sz - 1].first - a[pos].first;
}

int main() {

	ll n;
	scanf("%lld", &n);
	pair <ll, ll> a[n];
	fl (i, 0, n) {scanf("%lld", &a[i].first); a[i].second = i;}

	sort(a, a + n);

	ll sm = 0;
	fl (i, 0, n) sm += a[i].first;

	vector <ll> ans;
	fl (i, 0, n) if (getSM(a, n, sm, i) == getMX(a, n, i)) ans.push_back(a[i].second + 1);

	printf("%lld\n", ans.size());
	for (auto x : ans) printf("%lld ", x);

    return 0;
}
