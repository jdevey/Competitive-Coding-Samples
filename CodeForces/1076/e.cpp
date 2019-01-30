#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define MX 300010

using namespace std;

typedef long long ll;
typedef long double ld;

ll query(ll* fTree, ll left, ll right) {
	++right;
	ll sum = 0;
	while (right > 0) {
		sum += fTree[right - 1];
		right -= right & -right;
	}
	if (left != 0) {
		while (left > 0) {
			sum -= fTree[left - 1];
			left -= left & -left;
		}
	}
	return sum;
}

void update(ll* fTree, ll sz, ll ind, ll val) {
	++ind;
	while (ind <= sz) {
		fTree[ind - 1] += val;
		ind += ind & -ind;
	}
}

void construct(ll* fTree, const ll* arr, ll sz) {
	for (ll i = 0; i < sz; ++i) update(fTree, sz, i, arr[i]);
}

void dfs(vector <ll>* adj, ll* sms, ll* ft, ll* ans, vector <pair <ll, ll>>* q, ll n, ll ind, ll depth, bool* vis) {
	vis[ind] = true;
	for (auto x : q[ind]) {
		ll pos = min(depth + x.first, (ll)(MX - 2));
		sms[pos] += x.second;
		update(ft, MX, pos, x.second);
	}
	ans[ind] = query(ft, depth, MX - 1);
	for (auto x : adj[ind]) {
		if (!vis[x]) dfs(adj, sms, ft, ans, q, n, x, depth + 1, vis);
	}
	for (auto x : q[ind]) {
		ll pos = min(depth + x.first, (ll)(MX - 2));
		sms[pos] -= x.second;
		update(ft, MX, pos, -x.second);
	}
}

int main() {

	vector <ll>* adj = new vector <ll>[MX]();
	ll n;
	scanf("%lld", &n);
	fl (i, 0, n - 1) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	ll m;
	cin >> m;
	vector <pair <ll, ll>>* q = new vector <pair <ll, ll>>[MX]();
	fl (i, 0, m) {
		ll v, d, x;
		scanf("%lld %lld %lld",&v, &d, &x);
		q[v].push_back({d, x});
	}

	ll* sms = new ll[MX];
	memset(sms, 0, sizeof(sms));
	ll* ft = new ll[MX];
	memset(ft, 0, sizeof(ft));
	ll* ans = new ll[MX];
	memset(ans, 0, sizeof(ans));
	
	bool vis[MX] = {};
	dfs(adj, sms, ft, ans, q, n, 1, 0, vis);

	fl (i, 1, n + 1) printf("%lld ", ans[i]);

    return 0;
}
