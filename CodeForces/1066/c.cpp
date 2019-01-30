#include <bits/stdc++.h>

using namespace std;

int* cs = new int[250000];

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	memset(cs, 0, sizeof(cs));

	int q;
	scanf("%d", &q);

	char c;
	int p;
	scanf(" %c", &c);
	scanf("%d", &p);

	cs[p] = 0;

	int lp = 0, rp = 0;
	
	q--;

	while (q--) {
		scanf(" %c", &c);
		scanf("%d", &p);
		//printf("%c %d", c, p);
		if (c == 'L') {
			cs[p] = lp - 1;
			--lp;
		}
		else if (c == 'R') {
			cs[p] = rp + 1;
			++rp;
		}
		else {
			printf("%d\n", min(abs(cs[p] - lp), abs(cs[p] - rp)));
		}
	}

    return 0;
}
