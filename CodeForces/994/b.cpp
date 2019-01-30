#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n, k;
	cin >> n >> k;
	pair <ll, pair <ll, ll>> a[n];
	fl (i, 0, n) a[i].second.second = i;
	fl (i, 0, n) cin >> a[i].first;
	fl (i, 0, n) cin >> a[i].second.first;

	sort(a, a + n);

	multiset <ll> s;
	ll ps = 0;

	vector <pair <ll, ll>> ans;

	fl (i, 0, n) {
		ans.push_back({a[i].second.second, (ll)a[i].second.first + ps});
		//cout << a[i].second.first + ps << " ";
		s.insert(a[i].second.first);
		ps += a[i].second.first;
		if (s.size() > k) {
			ps -= *s.begin();
			s.erase(s.begin());
		}
	}

	sort(ans.begin(), ans.end());

	for (auto x : ans) cout << x.second << " ";

    return 0;
}
