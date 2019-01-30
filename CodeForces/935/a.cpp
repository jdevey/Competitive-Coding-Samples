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

int numFac(int n) {
	int c = 0;
	fl (i, 2, n + 1) if (n % i == 0) {
		n /= i;
		++c;
	}
	return c;
}

vector <ll> factorLister(ll n) {

    vector <ll> completeList;

    double sq = sqrt(n);
        for (ll i = 1; i <= sq; ++i) {
            if (n % i == 0) {
                completeList.push_back(i);
                if (i * i != n) completeList.push_back(n / i);
            }
        }

    return completeList;
}

int main() {

	ll n;
	cin >> n;

	vector <ll> f = factorLister(n);
	cout << f.size() - 1;

    return 0;
}
