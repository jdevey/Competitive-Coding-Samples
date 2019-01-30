#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int n, m;
	scanf("%d", &n);
	int a[n];
	fl (i, 0, n) scanf("%d", &a[i]);
	scanf("%d", &m);
	int b[m];
	fl (i, 0, m) scanf("%d", &b[i]);
	
	ll sma = 0, smb = 0;
	fl (i, 0, n) sma += a[i];
	fl (i, 0, m) smb += b[i];
	if (sma != smb) return puts("-1");

	int cnt = 0;
	ll ac = a[0], bc = b[0];
	int ap = 0, bp = 0;

	while (ap < n && bp < m) {
		if (ac == bc) {
			++cnt;
			ac = 0;
			bc = 0;
		}
		if (bc > ac) {
			++ap;
			ac += a[ap];
		}
		else {
			++bp;
			bc += b[bp];
		}
	}

	cout << cnt << endl;

    return 0;
}
