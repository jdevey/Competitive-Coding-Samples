#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
#define cin fin
std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

void factorLister(vector <ll>& completeList, ll n) {
	double sq = sqrt(n);
	for (ll i = 1; i <= sq; ++i) {
		if (n % i == 0) {
			completeList.push_back(i);
			if (i * i != n) completeList.push_back(n / i);
		}
	}
	sort(completeList.begin(), completeList.end());
}

int main() {

	ll p, y;
	cin >> p >> y;

	for (int i = y; i > p; --i) {
		vector <ll> fac;
		factorLister(fac, i);
		if (fac.size() == 2 && i > p) {
			cout << i << endl;
			return 0;
		}
		fl (j, 1, fac.size() - 1) {
			if (fac[j] <= p) break;
			if (j == fac.size() - 2) {
				cout << i << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;

	return 0;
}
