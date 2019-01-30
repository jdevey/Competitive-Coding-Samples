#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

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

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	string s;
	cin >> s;

	vector <ll> fac;
	factorLister(fac, n);

	for (auto x : fac) {
		reverse(s.begin(), s.begin() + x);
	}

	cout << s << endl;

    return 0;
}
