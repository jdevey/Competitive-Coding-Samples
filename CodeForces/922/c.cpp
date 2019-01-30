#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int main() {

	ll n, k;
	cin >> n >> k;

	set <int> ff;
	bool good = true;
	for (int i = 1; i <= k; ++i) {
		if (ff.find(n % i) != ff.end()) {
			cout << "No";
			return 0;
		}
		else ff.insert(n % i);
	}

	cout << "Yes";

    return 0;
}
