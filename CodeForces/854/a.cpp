#include <iostream>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;

	for (int i = n - 1; i > 0; --i) {
		if (gcd(i, n - i) == 1 && i < n - i) {
			cout << i << " " << n - i << endl;
			break;
		}
	}

    return 0;
}
