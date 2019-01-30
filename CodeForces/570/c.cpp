#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m;
	scanf("%d %d", &n, &m);
	char s[n];
	scanf("%s", s + 1);
	s[0] = 'a'; s[n + 1] = 'a';

	int val = 0;
	fl (i, 1, n + 1) {
		if (s[i] == '.' && s[i - 1] == '.') ++val;
	}

	while (m--) {
		int x;
		char c;
		scanf("%d %c", &x, &c);

		int cnt = 0;
		if (c == '.' && s[x] != '.') {
			if (s[x + 1] == '.') ++cnt;
			if (s[x - 1] == '.') ++cnt;

			val += cnt;
		}
		else if (c != '.' && s[x] == '.') {
			if (s[x + 1] == '.') ++cnt;
			if (s[x - 1] == '.') ++cnt;

			val -= cnt;
		}
		s[x] = c;

		printf("%d\n", val);
	}

    return 0;
}
