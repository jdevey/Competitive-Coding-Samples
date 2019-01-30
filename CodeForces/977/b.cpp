#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	string s;
	cin >> s;

	map <string, int> m;
	for (int i = 1; i < s.size(); ++i) {
		string ins;
		ins += s[i - 1];
		ins += s[i];
		++m[ins];
	}

	int mx = 0;
	string ms;
	for (auto x : m) {
		if (x.second > mx) {
			mx = x.second;
			ms = x.first;
		}
	}

	cout << ms;

    return 0;
}
