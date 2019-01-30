#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];

	sort(a, a + n);
	sort(b, b + m);

	int cnt = 0;
	int pt = 0;

	for (int i = 0; i < m; ++i) {
		if (a[pt] <= b[i]) {++cnt; ++pt;}
	}

	cout << cnt << endl;

	return 0;
}
