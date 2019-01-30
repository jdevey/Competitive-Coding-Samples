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

	string sc;
	char curLet = 'a';
	fl (i, 0, s.size()) {
		if (s[i] > curLet || curLet == 'z' + 1) {sc += s[i]; continue;}
		sc += curLet;
		++curLet;
	}

	if (curLet != 'z' + 1) return puts("-1");
	cout << sc;

    return 0;
}

