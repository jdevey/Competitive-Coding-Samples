#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define MD 1000000007

using namespace std;

typedef long long ll;
typedef long double ld;

void factorLister(vector <ll>& completeList, ll n) {
	for (ll i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			completeList.push_back(i);
			if (i * i != n) completeList.push_back(n / i);
		}
	}
	sort(completeList.begin(), completeList.end());
}

int main() {

	ll n;
	cin >> n;
	ll a[n];
	fl (i, 0, n) cin >> a[i];

	vector <ll> fList[n];
	fl (i, 0, n) factorLister(fList[i], a[i]);

	ll* m = new ll[1000001];
	memset(m, 0, sizeof(m));

	ll sm = 0;
	fl (i, 0, n) {
		for (auto x : fList[i]) {
			if (x > i + 1) break;
			ll res = x == 1 ? 1 : m[x - 1];
			sm = (sm + res) % MD;
		}
		for (auto x = fList[i].rbegin(); x != fList[i].rend(); ++x) {
			if (*x > i + 1) continue;
			ll res = *x == 1 ? 1 : m[*x - 1];
			m[*x] = (m[*x] + res) % MD;
		}
	}

	cout << sm << endl;

    return 0;
}
