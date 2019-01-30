#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define BIG 1000000
#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
#define cin fin
std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

void sieve(int sv[]) {
	fl (i, 1, BIG + 1) for (int j = i; j <= BIG; j += i) ++sv[j];
}

pair <ll, ll> update(pair <ll, ll> ST[], int arr[], int sv[], int ql, int qr, int l, int r, int ind) {
	if (l > qr || r < ql || ST[ind].second < 3) return ST[ind];
	if (l == r) {
		ST[ind].first = sv[ST[ind].first];
		ST[ind].second = ST[ind].first;
		return ST[ind];
	}
	int mid = (l + r) / 2;
	auto lft = update(ST, arr, sv, ql, qr, l, mid, ind * 2 + 1), rgt = update(ST, arr, sv, ql, qr, mid + 1, r, ind * 2 + 2);
	ST[ind].first = lft.first + rgt.first;
	ST[ind].second = max(lft.second, rgt.second);
	return ST[ind];
}

ll query(pair <ll, ll> ST[], int ql, int qr, int l, int r, int ind) {
	if (l > qr || r < ql) return 0;
	else if (l >= ql && r <= qr) return ST[ind].first;
	else {
		int mid = (l + r) / 2;
		return query(ST, ql, qr, l, mid, 2 * ind + 1) + query(ST, ql, qr, mid + 1, r, 2 * ind + 2);
	}
}

pair <ll, ll> construct(pair <ll, ll> ST[], int arr[], int l, int r, int ind) {
	if (l == r) {
		ST[ind].first = arr[l];
		ST[ind].second = arr[l];
		return ST[ind];
	}
	int mid = (l + r) / 2;
	pair <ll, ll> lft = construct(ST, arr, l, mid, 2 * ind + 1), rgt = construct(ST, arr, mid + 1, r, 2 * ind + 2);
	ST[ind].first = lft.first + rgt.first;
	ST[ind].second = max(lft.second, rgt.second);
	return ST[ind];
}

int main() {

	auto sv = new int[BIG + 1];
	memset(sv, 0, sizeof(sv));
	sieve(sv);

	int n, m;
	scanf("%d %d", &n, &m);
	int a[n];
	fl (i, 0, n) scanf("%d", &a[i]);

	auto ST = new pair <ll, ll>[4 * n];
	construct(ST, a, 0, n - 1, 0);

	while (m--) {
		int type, l, r;
		scanf("%d %d %d", &type, &l, &r);
		if (type == 1) update(ST, a, sv, l - 1, r - 1, 0, n - 1, 0);
		else printf("%lld\n", query(ST, l - 1, r - 1, 0, n - 1, 0));
	}

	return 0;
}
