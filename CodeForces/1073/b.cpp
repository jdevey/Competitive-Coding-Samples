#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; ++i) {cin >> a[i]; --a[i];}
	for (int i = 0; i < n; ++i) {cin >> b[i]; --b[i];}

	int pos[n];
	for (int i = 0; i < n; ++i) pos[a[i]] = i;

	int pt = 0;
	for (int i = 0; i < n; ++i) {
		int p = pos[b[i]];
		cout << max(p - pt + 1, 0) << " ";
		pt = max(pt, p + 1);
	}

    return 0;
}
