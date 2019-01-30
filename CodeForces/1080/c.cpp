#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

void printPair(pair <ll, ll> p) {
	cout << "pair " << p.first << " " << p.second << endl;
}

void printPP(pair <pair <ll, ll>, pair <ll, ll>> pp) {
	cout << "double pair " << pp.first.first << " " << pp.first.second << " " << pp.second.first <<  " " << pp.second.second << endl;
}

pair <ll, ll> cc(ll x1, ll y1, ll x2, ll y2) {
	ll half = (x2 - x1 + 1) * (y2 - y1 + 1) / 2;
	if (~((x2 - x1 + 1) * (y2 - y1 + 1)) & 1) return make_pair(half, half);
	if ((x1 + y1) & 1) return make_pair(half, half + 1);
	else return make_pair(half + 1, half);
}

pair <pair <ll, ll>, pair <ll, ll>> inters(pair <pair <ll, ll>, pair <ll, ll>> r1, pair <pair <ll, ll>, pair <ll, ll>> r2) {
	//if (r1.second.first <= r2.first.first || r1.first.first >= r2.second.first || r1.second.second <= r2.first.second || r1.first.second >= r2.second.second)
	//	return make_pair(make_pair(-1, -1), make_pair(-1, -1));

	pair <pair <ll, ll>, pair <ll, ll>> ans = {{-1e18, -1e18}, {1e18, 1e18}};

	if (r1.first.first >= r2.first.first && r1.first.first <= r2.second.first) ans.first.first = max(ans.first.first, r1.first.first);
	if (r1.second.first >= r2.first.first && r1.second.first <= r2.second.first) ans.second.first = min(ans.second.first, r1.second.first);

	if (r2.first.first >= r1.first.first && r2.first.first <= r1.second.first) ans.first.first = max(ans.first.first, r2.first.first);
	if (r2.second.first >= r1.first.first && r2.second.first <= r1.second.first) ans.second.first = min(ans.second.first, r2.second.first);

	if (r1.first.second >= r2.first.second && r1.first.second <= r2.second.second) ans.first.second = max(ans.first.second, r1.first.second);
	if (r1.second.second >= r2.first.second && r1.second.second <= r2.second.second) ans.second.second = min(ans.second.second, r1.second.second);

	if (r2.first.second >= r1.first.second && r2.first.second <= r1.second.second) ans.first.second = max(ans.first.second, r2.first.second);
	if (r2.second.second >= r1.first.second && r2.second.second <= r1.second.second) ans.second.second = min(ans.second.second, r2.second.second);

	return ans;
}

bool isGood(pair <pair <ll, ll>, pair <ll, ll>> p) {
	return p.first.first != (ll)-1e18 && p.first.second != (ll)-1e18 && p.second.first != (ll)1e18 && p.second.first != (ll)1e18;
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		ll n, m, x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		pair <ll, ll> tc = cc(1, 1, m, n);

		pair <ll, ll> wc = cc(x1, y1, x2, y2);
		tc.first += wc.second;
		tc.second -= wc.second;

		pair <ll, ll> bc = cc(x3, y3, x4, y4);
		tc.first -= bc.first;
		tc.second += bc.first;

		pair <pair <ll, ll>, pair <ll, ll>> it = inters(make_pair(make_pair(x1, y1), make_pair(x2, y2)), make_pair(make_pair(x3, y3), make_pair(x4, y4)));

		if (isGood(it)) {
			pair <ll, ll> ic = cc(it.first.first, it.first.second, it.second.first, it.second.second);
			tc.first -= ic.second;
			tc.second += ic.second;
		}

		cout << tc.first << " " << tc.second << endl;
	}

	return 0;
}
