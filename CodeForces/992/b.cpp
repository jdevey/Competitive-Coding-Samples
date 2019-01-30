#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

ll gcd(ll n, ll m) {
	return m ? gcd(m, n % m) : n;
}

void factorLister(vector <ll>& completeList, ll n) {
	long double sq = sqrt(n);
	for (ll i = 1; i <= sq; ++i) {
		if (n % i == 0) {
			completeList.push_back(i);
			if (i * i != n) completeList.push_back(n / i);
		}
	}
	sort(completeList.begin(), completeList.end());
}

void combine(vector <ll>& a, vector <ll>& b, set <ll>& c) {
	for (auto n1 : a) {
		for (auto n2 : b) {
			c.insert(n1 * n2);
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll l, r, x, y;
	cin >> l >> r >> x >> y;
	ll prod = x * y;

	set <ll> fList;
	vector <ll> aa, bb;
	factorLister(aa, x);
	factorLister(bb, y);
	combine(aa, bb, fList);
	int cnt = 0;

	for (auto num : fList) {
		if (gcd(num, prod / num) == x && prod / gcd(num, prod / num) == y && num >= l && num <= r && prod / num >= l && prod / num <= r) {
			++cnt;
		}
	}

	cout << cnt << endl;

    return 0;
}
