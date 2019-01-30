#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

bool igt(set <pair <ll, ll>>& m, ll n) {
	auto f = m.lower_bound({n, 0});
	if (f == m.end() || f->first != n) return false;
	++f;
	if (f == m.end() || f->first != n) return false;
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n;
	cin >> n;
	ll a[n];
	fl (i, 0, n) cin >> a[i];

	set <pair <ll, ll>> m;
	set <ll> compress;

	fl (i, 0, n) {m.insert({a[i], i}); compress.insert(a[i]);}

	set <ll>::iterator it = compress.begin();

	while (it != compress.end()) {
		if (igt(m, *it)) {
			ll tt = *it * 2, ni;

			auto res = m.lower_bound({*it, 0});
			res = m.erase(res);
			ni = res->second;
			m.erase(res);
			m.insert({tt, ni});

			compress.insert(tt);
			auto newIT = compress.find(tt / 2);
			it = newIT;
		}
		else ++it;
	}

	vector <pair <ll, ll>> vp;
	for (auto x : m) vp.push_back({x.second, x.first});

	sort(vp.begin(), vp.end());

	cout << vp.size() << endl;
	fl (i, 0, vp.size()) cout << vp[i].second << " ";

    return 0;
}
