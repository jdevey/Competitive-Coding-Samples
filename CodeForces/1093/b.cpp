#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

bool isUni(string s) {
	for (auto c : s) if (c != s[0]) return false;
	return true;
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (isUni(s)) cout << -1 << endl;
		else {
			sort(s.begin(), s.end());
			cout << s << endl;
		}
	}

    return 0;
}
