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

int main() {

	ll n, k, A, B;
	cin >> n >> k >> A >> B;

	if (k == 1) {
		cout << (n - 1) * A;
		return 0;
	}

	ll total = 0;

	while (n > 1) {
		//cout << n << " " << total << " ";
		if (n > k) {
			ll fst = n % k;
			n -= fst;
			total += fst * A;
		}
		if (n >= k ? A * (n - n / k) < B : true) {
			total += (n - 1) * A;
			break;
		}
		total += B;
		n /= k;
		//cout << total << endl;
	}

	cout << total;

	return 0;
}
