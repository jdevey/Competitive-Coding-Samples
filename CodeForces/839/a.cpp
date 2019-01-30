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

	int n, k;
	cin >> n >> k;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	int stock = 0;
	int rev[n] = {};
	fl (i, 0, n) {
		rev[i] = min(8, a[i] + stock);
		stock = max(0, stock + a[i] - 8);
	}

	int sum = 0, ind = 1;
	while (sum < k && ind <= n) {
		sum += rev[ind - 1];
		++ind;
	}

	cout << (sum >= k ? ind - 1 : -1);

    return 0;
}
