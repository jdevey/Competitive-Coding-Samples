#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isUni(int* a, int s, int n, int skip) {
	int home = a[s];
	for (int i = s; i < n; i += skip) if (a[i] != home) return false;
	return true;
}

void rec(int* a, int& cnt, int s, int n, int skip) {
	++cnt;
	if (isUni(a, s, n, skip)) return;
	rec(a, cnt, s, n, skip * 2);
	rec(a, cnt, s + skip, n, skip * 2);
}

int main() {

	int n;
	scanf("%d", &n);
	int a[1 << n];
	for (int i = 0; i < 1 << n; ++i) scanf("%d", &a[i]);
	int cnt = 0;
	rec(a, cnt, 0, 1 << n, 1);
	printf("%d", cnt);

	return 0;
}
