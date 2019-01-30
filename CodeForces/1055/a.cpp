#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int s, n;
	cin >> n >> s;
	int a[n], b[n];
	fl (i, 0, n) cin >> a[i];
	fl (i, 0, n) cin >> b[i];

	int pos = 0;

	if (a[0] == 0) return puts("NO");

	for (int i = 1; i < n; ++i) {
		if (i == s - 1 & a[i]) return puts("YES");
		if (a[i] & b[i]) {
			for (int j = i; j > -1; --j) {
				if (j == s - 1 & b[j]) return puts("YES");
			}
		}
	}

	cout << "NO" << endl;

    return 0;
}

