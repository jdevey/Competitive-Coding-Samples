#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

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

ll tri(ll n) {
	return n * (n + 1) / 2;
}

int main() {

	ll n;
	cin >> n;

	vector <ll> facs;
	factorLister(facs, n);

	vector <ll> lst;

	for (auto x : facs) {
		ll inv = n / x;
		lst.push_back(x * tri(inv - 1) + inv);
	}

	sort(lst.begin(), lst.end());

	for (auto x : lst) cout << x << " ";

    return 0;
}
