#include <iostream>
#include <iomanip>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {

	#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
	#endif

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		ld a[n], b[n], c[n];
		fl (i, 0, n) cin >> a[i] >> b[i] >> c[i];

		ld sum = 0.0;
		fl (i, 0, n) sum += a[i] * b[i] * (1 - (100 + c[i]) * (100 - c[i]) / 10000);

		cout << fixed << setprecision(12) << sum << endl;
	}

	return 0;
}


