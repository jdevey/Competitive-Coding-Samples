#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

bool cmp(const string& a, const string& b) {
	return a.size() < b.size();
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	string a[n];
	fl (i, 0, n) cin >> a[i];

	sort(a, a + n, cmp);

	fl (i, 1, n) {
		if (a[i].find(a[i - 1]) == string::npos) {/*cout << a[i] << " " << a[i - 1] << endl;*/ return puts("NO");}
	}

	cout << "YES" << endl;
	for (auto x : a) cout << x << endl;

    return 0;
}
