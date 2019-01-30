#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	string s;
	cin >> s;

	int pCount = 0, lCount = 0;

	for (auto x : s) {if (x == 'o') ++pCount; else ++lCount;}

	if (!pCount || !lCount) return puts("YES");
	return puts(lCount % pCount == 0 ? "YES" : "NO");
}
