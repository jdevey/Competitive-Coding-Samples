#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

vector <ll> factorLister(ll n) {
	vector <ll> ret;
	for (ll i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}

int main() {

	ll n;
	while (true) {
		cin >> n;
		if (!n) break;

		if (n == 3) {
			cout << 4 << endl;
			continue;
		}
		if (n < 7) {
			cout << "No such base\n";
			continue;
		}

		vector <ll> fl = factorLister(n - 3);
		for (auto x : fl) {
			if (x > 3) {
				cout << x << endl;
				break;
			}
		}
	}

	return 0;
}
