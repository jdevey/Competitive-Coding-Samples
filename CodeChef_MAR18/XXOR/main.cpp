#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

	int n, q, l, r;
	scanf("%d %d", &n, &q);
	int a[n];
	fl (i, 0, n) scanf("%d", &a[i]);

	int pref[n + 1][32];
	memset(pref[0], 0, sizeof(pref[0]));
	fl (i, 1, n + 1) {
		int x = a[i - 1];
		fl (j, 0, 32) {
			pref[i][j] = pref[i - 1][j] + (x & 1);
			x >>= 1;
		}
	}

	while (q--) {
		scanf("%d %d", &l, &r);
		int x = 0;
		fl (i, 0, 31) x += pref[r][i] - pref[l - 1][i] < (r - l) / 2 + 1 ? 1 << i : 0;
		printf("%d\n", x);
	}

    return 0;
}
