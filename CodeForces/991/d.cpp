#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	string a, b;
	cin >> a >> b;

	int cnt = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (i > 0 && a[i] == '0' && b[i] == '0' && a[i - 1] == '0') {
			++cnt;
			a[i] = '.';
			a[i - 1] = '.';
			b[i] = '.';
		}
		else if (i > 0 && a[i] == '0' && b[i] == '0' && b[i - 1] == '0') {
			++cnt;
			a[i] = '.';
			b[i - 1] = '.';
			b[i] = '.';
		}
		else if (i < a.size() - 1 && a[i] == '0' && b[i] == '0' && a[i + 1] == '0') {
			++cnt;
			a[i] = '.';
			a[i + 1] = '.';
			b[i] = '.';
		}
		else if (i < a.size() - 1 && a[i] == '0' && b[i] == '0' && b[i + 1] == '0') {
			++cnt;
			a[i] = '.';
			b[i + 1] = '.';
			b[i] = '.';
		}
	}

	cout << cnt << endl;

	return 0;
}
