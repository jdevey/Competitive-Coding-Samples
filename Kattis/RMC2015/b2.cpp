#include <bits/stdc++.h>

using namespace std;

int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		pair <int, int> a[n];
		for (int i = 0; i < n; ++i) {
			int a1, a2;
			scanf("%d %d", &a1, &a2);
			a[i] = make_pair(a1, a2);
		}
		sort(a, a + n);
		bool good = true;
		for (int i = 1; i < n; ++i) {
			if (a[i] == a[i - 1]) good = false;
		}
		printf(good ? "possible\n" : "impossible\n");
	}

	return 0;
}
