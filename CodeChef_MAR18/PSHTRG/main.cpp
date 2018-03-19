#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

struct PQS{
	map <int, int>::reverse_iterator ri;
	int val, ind;
	PQS(const map <int, int>::reverse_iterator& _ri, const int& _val, const int& _ind) {
		ri = _ri;
		val = _val;
		ind = _ind;
	}
	bool operator<(const PQS& rhs) const {
		if (val < rhs.val) return true;
		else if (val > rhs.val) return false;
		else return ind < rhs.ind;
	}
};

struct Edit{
	int node, val;
	Edit(const int& _node, const int& _val) {
		node = _node, val = _val;
	}
	bool operator<(const Edit& rhs) const {
		return val < rhs.val;
	}
};

inline bool isGood(ll& a, ll& b, ll& c) {
	return a && b && c && c < a + b;
}

void makeInit(map <int, int>* ST, map <PQS, int>& pq, ll* num) {
	priority_queue <int> mm;
	int i = 0;
	for (auto it = pq.rbegin(); it != pq.rend() && i < 3; ++it) {
		int j = 0;
		for (auto iit = it->first.ri; iit != ST[it->first.ind].rend() && j < 3 - i; ++iit) {
			fl (k, 0, min(3, iit->second)) mm.push(iit->first);
			++j;
		}
		++i;
	}

	for (int h = 2; h > -1; --h) {
		num[h] = mm.top();
		mm.pop();
	}
}

void queryUtil(map <int, int>* ST, map <PQS, int>& pq, int ql, int qr, int l, int r, int ind) {
	if (l > qr || r < ql) return;
	if (l >= ql && r <= qr) {
		++pq[PQS(ST[ind].rbegin(), ST[ind].rbegin()->first, ind)];
		return;
	}
	queryUtil(ST, pq, ql, qr, l, (l + r) / 2, ind * 2 + 1);
	queryUtil(ST, pq, ql, qr, (l + r) / 2 + 1, r, ind * 2 + 2);
}

ll query(map <int, int>* ST, int n, int ql, int qr) {
	if (qr - ql < 2) return 0;

	map <PQS, int> pq;
	map <Edit, int> eList;
	queryUtil(ST, pq, ql, qr, 0, n - 1, 0);

	ll num[3] = {};
	makeInit(ST, pq, num);
	while (true) {
		if (isGood(num[0], num[1], num[2])) return num[0] + num[1] + num[2];

		//Insert only if first element has one on top
		if (pq.rbegin()->first.ri != --ST[pq.rbegin()->first.ind].rend() && pq.rbegin()->first.ri->second - eList.count(Edit(pq.rbegin()->first.ind, pq.rbegin()->first.ri->first)) == 1) {
			auto rpib = pq.rbegin()->first.ri;
			++rpib;
			++pq[PQS(rpib, rpib->first, pq.rbegin()->first.ind)];
		}

		//Erase or increment the edit entry
		if (pq.rbegin()->first.ri->second - eList.count(Edit(pq.rbegin()->first.ind, pq.rbegin()->first.ri->first)) > 1)
			++eList[Edit(pq.rbegin()->first.ind, pq.rbegin()->first.ri->first)];
		else pq.erase(--pq.end());

		//Update num array
		priority_queue <int> mm;
		int i = 0;
		for (auto it = pq.rbegin(); it != pq.rend() && i < 3; ++it) {
			int j = 0;
			for (auto iit = it->first.ri; iit != ST[it->first.ind].rend() && j < 3 - i; ++iit) {
				fl (k, 0, min(3, iit->second)) mm.push(iit->first);
				++j;
			}
			++i;
		}
		if (mm.size() < 3) return 0;
		for (int h = 2; h > -1; --h) {
			num[h] = mm.top();
			mm.pop();
		}
	}
}

void updateUtil(map <int, int>* ST, int node, int val, int oldVal, int l, int r, int ind) {
	if (node >= l && node <= r) {
		++ST[ind][val];
		--ST[ind][oldVal];
		auto f = ST[ind].find(oldVal);
		if (!f->second) ST[ind].erase(f);
	}
	else return;
	if (l == r) return;
	updateUtil(ST, node, val, oldVal, l, (l + r) / 2, ind * 2 + 1);
	updateUtil(ST, node, val, oldVal, (l + r) / 2 + 1, r, ind * 2 + 2);
}

void update(map <int, int>* ST, int* a, int n, int node, int val) {
	int oldVal = a[node];
	a[node] = val;
	updateUtil(ST, node, val, oldVal, 0, n - 1, 0);
}

void construct(map <int, int>* ST, int* a, int l, int r, int ind) {
	fl (i, l, r + 1)
		++ST[ind][a[i]];
	if (l == r) return;
	construct(ST, a, l, (l + r) / 2, ind * 2 + 1);
	construct(ST, a, (l + r) / 2 + 1, r, ind * 2 + 2);
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
	#endif

	int n, q;
	scanf("%d %d", &n, &q);
	int a[n];
	fl (i, 0, n) scanf("%d", &a[i]);

	auto ST = new map <int, int>[4 * n]();
	construct(ST, a, 0, n - 1, 0);

	while (q--) {
		int type, x, y;
		scanf("%d %d %d", &type, &x, &y);
		if (type == 1) update(ST, a, n, x - 1, y);
		else printf("%lld\n", query(ST, n, x - 1, y - 1));
	}

	return 0;
}
