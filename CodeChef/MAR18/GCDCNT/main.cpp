#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>

#define BIG 100001
#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

struct Node {
	unordered_map <int, int> fac;
	int sz;
};

void sieve(vector <int>** fcs) {
	fl (i, 2, BIG) if (fcs[i]->empty()) for (int j = i; j < BIG; j += i) fcs[j]->push_back(i);
}

void trans(int* transform, vector <int>** fcs) {
	fl (i, 0, BIG) {
		int prod = 1;
		fl (j, 0, fcs[i]->size()) prod *= (*fcs[i])[j];
		transform[i] = prod;
	}
}

int query(Node* ST, vector <int>** fcs, vector <int>& gFac, int ql, int qr, int& g, int l, int r, int ind) {
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) {
		Node& sti = ST[ind];

		int hCount = 0, fCount = 1;
		fl (i, 0, gFac.size()) {
			bool ff = sti.fac.find(gFac[i]) != sti.fac.end();
			int amt = ff ? sti.fac.find(gFac[i])->second : -1;
			if (ff && amt == sti.sz) return 0;
			if (hCount && ff && amt) fCount = 0;
			if (fCount && !hCount && ff && amt) hCount = amt;
		}
		if (fCount) {
			return sti.sz - hCount;
		}
	}

	int s = query(ST, fcs, gFac, ql, qr, g, l, (l + r) / 2, ind * 2 + 1) +
		query(ST, fcs, gFac, ql, qr, g, (l + r) / 2 + 1, r, ind * 2 + 2);
	return s;
}

void updateUtil(Node* ST, vector <int>** fcs, vector <int>& vFac, vector <int>& oFac, int node, int val, int oldVal, int l, int r, int ind) {
	if (node > r || node < l) return;

	Node& sti = ST[ind];
	fl (i, 0, vFac.size()) ++sti.fac[vFac[i]];
	fl (i, 0, oFac.size()) --sti.fac[oFac[i]];

	if (l == r) return;

	updateUtil(ST, fcs, vFac, oFac, node, val, oldVal, l, (l + r) / 2, ind * 2 + 1);
	updateUtil(ST, fcs, vFac, oFac, node, val, oldVal, (l + r) / 2 + 1, r, ind * 2 + 2);
}

void update(Node* ST, vector <int>** fcs, int* a, int n, int node, int val) {
	vector <int>& vFac = *fcs[val], oFac = *fcs[a[node]];
	updateUtil(ST, fcs, vFac, oFac, node, val, a[node], 0, n - 1, 0);
	a[node] = val;
}

void construct(Node* ST, vector <int>** fcs, int* a, int l, int r, int ind) {
	if (l == r) {
		fl (i, 0, fcs[a[l]]->size()) ++ST[ind].fac[(*fcs[a[l]])[i]];
		ST[ind].sz = 1;
		return;
	}
	construct(ST, fcs, a, l, (l + r) / 2, ind * 2 + 1);
	construct(ST, fcs, a, (l + r) / 2 + 1, r, ind * 2 + 2);
	ST[ind].fac.rehash((r - l) * 30);
	for (auto x : ST[ind * 2 + 1].fac) ST[ind].fac[x.first] += x.second;
	for (auto x : ST[ind * 2 + 2].fac) ST[ind].fac[x.first] += x.second;
	ST[ind].sz = r - l + 1;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
	#endif

	vector <int>* fcs[BIG];
	int transform[BIG];
	fl (i, 0, BIG) fcs[i] = new vector <int>();
	sieve(fcs);
	trans(transform, fcs);

	int n, q;
	scanf("%d", &n);
	int a[n], tr[n];
	fl (i, 0, n) scanf("%d", &a[i]);
	scanf("%d", &q);

	fl (i, 0, n) tr[i] = transform[a[i]];
	auto ST = new Node[4 * n]();
	construct(ST, fcs, a, 0, n - 1, 0);

	while (q--) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int x, y;
			scanf("%d %d", &x, &y);
			update(ST, fcs, a, n, x - 1, transform[y]);
		}
		else {
			int l, r, g;
			scanf("%d %d %d", &l, &r, &g);
			printf("%d\n", query(ST, fcs, *fcs[g], l - 1, r - 1, transform[g], 0, n - 1, 0));
		}
	}

	return 0;
}

