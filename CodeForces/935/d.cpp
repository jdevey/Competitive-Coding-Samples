#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define BIG 1000000007
#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

void EE(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    EE(b, a % b, x, y);
    ll temp = x - a / b * y;
    x = y;
    y = temp;
}

ll modInv(ll a) {
    ll x, y;
    EE(a, BIG, x, y);
    return x < 0 ? x + BIG : x;
}

int main() {

	int n, m;
	cin >> n >> m;
	int a[n], b[n];
	fl (i, 0, n) cin >> a[i];
	fl (i, 0, n) cin >> b[i];

	ll top, bottom;
	fl (i, 0, n) {
		if (a[i] == 0 && b[i] == 0) bottom *= modInv(2);
		else if (a[i] == 0) {

		}
	}

    return 0;
}
