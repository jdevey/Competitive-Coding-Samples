#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

vector <ll> fLister(ll n) {
	vector <ll> ret;
	for (ll i = 1; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}

bool good(vector <ll>& small, ll n, ll m, ll blue) {
	auto it = upper_bound(small.begin(), small.end(), n);
	if (it != small.begin()) --it;
	return blue / *it <= m;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll a, b;
	cin >> a >> b;
	ll nm = a + b;

	vector <ll> nmFacList = fLister(a + b);
	auto aFacList = fLister(a);
	auto bFacList = fLister(b);

	for (int i = nmFacList.size() / 2; i > -1; --i) {
		if (good(aFacList, nmFacList[i], nm / nmFacList[i], a) || good(bFacList, nmFacList[i], nm / nmFacList[i], b)) {
			cout << 2 * nmFacList[i] + 2 * nm / nmFacList[i] << endl;
			break;
		}
	}

    return 0;
}
