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

	int zerCount = 0;
	for (auto x : s) if (x == '0') ++zerCount;

	string ss = "1";
	for (int i = 0; i < zerCount; ++i) ss += '0';

	if (s.size() == 1) cout << s;
	else cout << ss;
	

    return 0;
}
