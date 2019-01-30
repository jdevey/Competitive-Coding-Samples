#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int bc = 0, ec = 0, ind = 0;
	while (s[ind] == s.front()) ++bc, ++ind;
	ind = s.size() - 1;
	while (s[ind] == s.back()) ++ec, --ind;
	if (s.front() == s.back()) cout << (ll)(bc + 1) * (ec + 1) % 998244353 << endl;
	else cout << bc + ec + 1 << endl;
    return 0;
}
