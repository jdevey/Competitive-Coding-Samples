#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	map <string, string> m = {
		{"purple", "Power"},
		{"green", "Time"},
		{"blue", "Space"},
		{ "orange", "Soul"},
		{"red", "Reality"},
		{"yellow", "Mind"}
	};

	set <string> found;

	int n;
	cin >> n;
	fl (i, 0, n) {
		string temp;
		cin >> temp;
		found.insert(temp);
	}

	cout << 6 - found.size() << endl;

	for (auto x : m) {
		if (found.find(x.first) == found.end()) cout << x.second << endl;
	}

    return 0;
}
