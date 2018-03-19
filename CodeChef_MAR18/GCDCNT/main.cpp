//Final correct solution

#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <unordered_map>

#define BIG 100001
#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

vector <vector <vector <int>>> perm (7, vector <vector <int>>());

void primeSieve(vector <int>** fcs) {
	fl (i, 2, BIG) if (fcs[i]->empty()) for (int j = i; j < BIG; j += i) fcs[j]->push_back(i);
}

void factorSieve(vector <int>** ffs, vector <int>** fcs, int* trans) {
	fl (h, 2, BIG) {
		if (h != trans[h]) continue;
		int sz = (int)fcs[h]->size();
		fl (i, 1, sz + 1) {
			int psz = (int)perm[sz][i].size();
			fl (j, 0, psz) {
				int prod = 1, x = perm[sz][i][j];
				for (int k = sz - 1; k > -1; --k) {
					if (x & 1) prod *= (*fcs[h])[k];
					x >>= 1;
				}
				(*ffs[h]).push_back(prod);
			}
		}
	}
}

void initPerm() {
	fl (i, 0, 7) {
		fl (j, 0, i + 1) perm[i].emplace_back(vector <int>());
		fl (j, 0, 1 << i) perm[i][__builtin_popcount(j)].push_back(j);
	}
}

void trans(int* transform, vector <int>** fcs) {
	fl (i, 0, BIG) {
		int prod = 1;
		fl (j, 0, fcs[i]->size()) prod *= (*fcs[i])[j];
		transform[i] = prod;
	}
}

int query(unordered_map <int, int>* ST, vector <int>& gFac, int ql, int qr, int g, int l, int r, int ind) {
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) {
		unordered_map<int, int>& sti = ST[ind];
		vector <int> rev;
		fl (i, 0, gFac.size()) {
			auto stif = sti.find(gFac[i]);
			if (stif != sti.end() && stif->second) rev.push_back(gFac[i]);
		}
		int s = r - l + 1, sz = (int)rev.size();
		bool sign = true;
		fl (i, 1, sz + 1) {
			int psz = perm[sz][i].size();
			fl (j, 0, psz) {
				int prod = 1, x = perm[sz][i][j];
				for (int k = sz - 1; k > -1; --k) {
					if (x & 1) prod *= rev[k];
					x >>= 1;
				}
				auto fpe = sti.find(prod);
				if (fpe != sti.end()) s += (sign ? -1 : 1) * fpe->second;
			}
			sign = !sign;
		}
		return s;
	}
	return query(ST, gFac, ql, qr, g, l, (l + r) / 2, ind * 2 + 1) + query(ST, gFac, ql, qr, g, (l + r) / 2 + 1, r, ind * 2 + 2);
}

void updateUtil(unordered_map <int, int>* ST, vector <int>& vFac, vector <int>& oFac, int node, int val, int oldVal, int l, int r, int ind) {
	if (node > r || node < l) return;

	unordered_map<int, int>& sti = ST[ind];
	fl (i, 0, vFac.size()) ++sti[vFac[i]];
	fl (i, 0, oFac.size()) --sti[oFac[i]];

	if (l == r) return;

	updateUtil(ST, vFac, oFac, node, val, oldVal, l, (l + r) / 2, ind * 2 + 1);
	updateUtil(ST, vFac, oFac, node, val, oldVal, (l + r) / 2 + 1, r, ind * 2 + 2);
}

void update(unordered_map <int, int>* ST, vector <int>** ffs, int* a, int n, int node, int val) {
	vector <int>& vFac = *ffs[val], oFac = *ffs[a[node]];
	updateUtil(ST, vFac, oFac, node, val, a[node], 0, n - 1, 0);
	a[node] = val;
}

void construct(unordered_map <int, int>* ST, vector <int>** ffs, int* a, int l, int r, int ind) {
	if (l == r) {
		fl (i, 0, ffs[a[l]]->size()) ++ST[ind][(*ffs[a[l]])[i]];
		return;
	}
	construct(ST, ffs, a, l, (l + r) / 2, ind * 2 + 1);
	construct(ST, ffs, a, (l + r) / 2 + 1, r, ind * 2 + 2);
	ST[ind].rehash((r - l) * 25);
	for (auto x : ST[ind * 2 + 1]) ST[ind][x.first] += x.second;
	for (auto x : ST[ind * 2 + 2]) ST[ind][x.first] += x.second;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	initPerm();

	vector <int>* fcs[BIG], *ffs[BIG];
	int transform[BIG];
	fl (i, 0, BIG) {fcs[i] = new vector <int>(); ffs[i] = new vector <int>();}
	primeSieve(fcs);
	trans(transform, fcs);
	factorSieve(ffs, fcs, transform);

	int n, q, type, l, r, g;
	scanf("%d", &n);
	int a[n], tr[n];
	fl (i, 0, n) scanf("%d", &a[i]);
	scanf("%d", &q);

	fl (i, 0, n) tr[i] = transform[a[i]];
	auto ST = new unordered_map <int, int>[4 * n]();
	construct(ST, ffs, tr, 0, n - 1, 0);

	while (q--) {
		scanf("%d", &type);
		if (type == 1) {
			int x, y;
			scanf("%d %d", &x, &y);
			update(ST, ffs, tr, n, x - 1, transform[y]);
		}
		else {
			scanf("%d %d %d", &l, &r, &g);
			printf("%d\n", query(ST, *fcs[g], l - 1, r - 1, transform[g], 0, n - 1, 0));
		}
	}

	return 0;
}

