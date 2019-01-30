#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

ll euclidean(ll n, ll m) {
	return !m ? n : euclidean(m, n % m);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif
	ll n, a1, b1;
	cin >> n >> a1 >> b1;
	pair <ll, pair <ll, ll>> a[n];
	fl (i, 0, n) cin >> a[i].first >> a[i].second.first >> a[i].second.second;

	map <pair <ll, ll>, ll> m;
	map <ll, ll> special;
	fl (i, 0, n) {
		if (a[i].second.first == 0 || a[i].second.second == 0) {
			if (a[i].second.first == 0 && a[i].second.second == 0) continue;
			else if (a[i].second.first == 0) ++m[make_pair(1, 0)];
			else ++m[make_pair(0, 1)];
		}
		else if (a[i].second.second % a[i].second.first == 0 && a[i].second.second / a[i].second.first == a1) {
			++special[a[i].second.first];
		}
		else {
			pair <ll, ll> reduced;
			reduced.first = a[i].second.first / abs(euclidean(a[i].second.first, a[i].second.second));
			reduced.second = a[i].second.second / abs(euclidean(a[i].second.first, a[i].second.second));
			++m[reduced];
		}
	}

	ll ps[m.size() + special.size()];
	ps[0] = m.begin()->second;
	if (m.empty()) ps[0] = special.begin()->second;

	auto it = m.begin();
	if (m.size()) ++it;
	int ind = 0;

	for (int i = 1; it != m.end(); ++it, ++i) {
		ps[i] = ps[i - 1] + it->second;
		ind = i;
	}

	auto it2 = special.begin();
	for (int i = ind + 1; it2 != special.end(); ++it2, ++i) {
		ps[i] = ps[i - 1] + it2->second;
	}

	ll ans = 0;

	//cout << m.size() << " " << special.size() << endl;
	fl (i, 1, m.size() + special.size()) {
		//cout << ps[i] << endl;
		ans += (ps[i] - ps[i - 1]) * ps[i - 1];
	}

	cout << ans * 2;

    return 0;
}
