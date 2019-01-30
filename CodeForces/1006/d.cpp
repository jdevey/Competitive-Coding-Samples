#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	int total = 0;

	for (int i = 0; i < n / 2; ++i) {
		if (b[i] == b[n - i - 1]) {
			total += a[i] != a[n - i - 1];
		}
		else {
			int cs[26] = {};
			++cs[a[i] - 'a'];
			++cs[a[n - i - 1] - 'a'];
			total += cs[b[i] - 'a'] < 1;
			total += cs[b[n - i - 1] - 'a'] < 1;
		}
	}

	total += n & 1 && a[n / 2] != b[n / 2];
	
	cout << total << endl;

    return 0;
}
