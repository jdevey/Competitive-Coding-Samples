#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int n;
	string s, ans;
	cin >> n >> s;

	for (int i = 1, j = 0; i <= n; ++i) {
		ans += s[j];
		for (int k = 0; k < i; ++k) ++j;
	}

	cout << ans << endl;

    return 0;
}
