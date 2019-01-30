#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool isGood(int* a, int n, int per) {
	for (int i = 0; i < n; ++i) if (a[i] != a[i % per]) return false;
	return true;
}

int main() {

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	int decomp[n];
	decomp[0] = a[0];
	for (int i = 1; i < n; ++i) decomp[i] = a[i] - a[i - 1];

	vector <int> ans;
	for (int i = 1; i <= n; ++i) if (isGood(decomp, n, i)) ans.push_back(i);

	cout << ans.size() << endl;
	for (auto x : ans) cout << x << " ";

	return 0;
}
