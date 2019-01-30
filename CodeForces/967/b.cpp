#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

bool isGood(int sm, int a, int b, int a0) {
	return a0 * a / sm >= b;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, a, b;
	cin >> n >> a >> b;
	int arr[n];
	fl (i, 0, n) cin >> arr[i];

	int sm = 0;
	fl (i, 0, n) sm += arr[i];

	int cpy[n];
	fl (i, 0, n) cpy[i] = arr[i];
	sort(cpy, cpy + n);

	int matchCount = 0, remCount = 0;
	fl (i, 0, n) if (arr[i] == arr[0]) ++matchCount;

	for (int i = n - 1; i > -1; --i) {
		if (isGood(sm, a, b, arr[0])) {cout << remCount << endl; return 0;}
		if (cpy[i] != arr[0] || (cpy[i] == arr[0] && matchCount > 1)) {
			if (cpy[i] == arr[0]) --matchCount;
			sm -= cpy[i];
			++remCount;
		}
	}
	cout << n - 1 << endl;

    return 0;
}
