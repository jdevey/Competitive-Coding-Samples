#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

string ic(int n) {
	string ans;
	ans += to_string(n / 60);
	n %= 60;
	ans += ' ';
	ans += to_string(n);
	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, s;
	cin >> n >> s;
	pair <int, int> a[n];
	fl (i, 0, n) cin >> a[i].first >> a[i].second;
	int conv[n];
	fl (i, 0, n) conv[i] = a[i].first * 60 + a[i].second;

	if (conv[0] >= s + 1) {
		cout << "0 0" << endl;
		return 0;
	}

	fl (i, 1, n) {
		if (conv[i] - conv[i - 1] >= 2 * s + 2) {
			//cout << i << " " << conv[i] << endl;
			//cout << conv[i] - conv[i - 1] << endl;
			//cout << conv[i - 1] + s << endl;
			cout << ic(conv[i - 1] + s + 1) << endl;
			return 0;
		}
	}

	cout << ic(conv[n - 1] + s + 1) << endl;

    return 0;
}
