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
typedef long double ld;

int main() {

	ll k, d;
	ld t;
	cin >> k >> d >> t;

	ld total, cookAmt, period;
	if (k > d) {
		cookAmt = k % d ? k * 1.0L + (k / d * d + d - k) / 2.0L : k;
		period = k % d ? k / d * d + d : k;
	}
	else {
		cookAmt = k * 1.0L + (d - k) / 2.0L;
		period = d;
	}

	total = (ld)floor(t / cookAmt) * period;
	t -= (ld)floor(t / cookAmt) * cookAmt;

	total += t > k ? k : t;
	t -= t > k ? k : t;

	total += t * 2;

	cout << total;

	return 0;
}

