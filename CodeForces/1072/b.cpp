#include <bits/stdc++.h>

using namespace std;

void victory(vector <int>& v, int i) {
	cout << "YES" << endl;
	for (auto x : v) cout << x << " ";
	cout << i;
	exit(0);
}

void rec(int n, int* a, int* b, vector <int>& v) {
	int sz = v.size();
	int cnt[4] = {};
	if (sz < n - 1) {
		for (int i = 0; i < 4; ++i) {cnt[i] += (a[sz] | i) <= a[sz];}
		for (int i = 0; i < 4; ++i) {cnt[i] += (b[sz] & i) == b[sz];}
	}
	if (sz > 0) {
		for (int i = 0; i < 4; ++i) {cnt[i] += (i | v.back()) == a[sz - 1];}
		for (int i = 0; i < 4; ++i) {cnt[i] += (i & v.back()) == b[sz - 1];}
	}/*
	for (int i = 0; i < 4; ++i) cout << cnt[i] << " ";
	cout << endl;
	cout << "f ";
	for (auto x : v) cout << x << " ";
	cout << endl;*/
	int expc = (sz == 0 || sz == n - 1) ? 2 : 4;
	for (int i = 0; i < 4; ++i) if (cnt[i] == expc) {
		if (sz == n - 1) {
			victory(v, i);
		}
		else {
			v.push_back(i);
			rec(n, a, b, v);
			v.pop_back();
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	int a[n - 1], b[n - 1];
	for (int i = 0; i < n - 1; ++i) cin >> a[i];
	for (int i = 0; i < n - 1; ++i) cin >> b[i];

	vector <int> v;

	rec(n, a, b, v);

	cout << "NO";

	return 0;
}
