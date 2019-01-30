#include <bits/stdc++.h>

#define fl(i,m,n) for(long long (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m, target;
	scanf("%d %d", &n, &m);
	tg = n / m;
	int a[n];
	fl (i, 0, n) scanf("%intd", &a[i]);

	vector <int> m[200001], sp[200001], db[200001];

	fl (i, 0, n) mp[a[i] % m].push_back(i);
	for (auto x : mp) {
		if (x.second.size() > tg) for (auto y : x.second) sp.push_back(y);
		else if (x.second.size() < tg) for (auto y : x.second) db.push_back(y);
	}

	ll sc = 0;

	fl (i, 0, m) {
		
	}

	fl (i, 0, m) {
		int deficit = target - mp[i].size();
		if (deficit < 1) continue;
		for (int j = 0; j < deficit; ++j) {
			auto it = surplus.lower_bound(i);
			if (it == surplus.begin()) it = --surplus.end();
			else --it;
			score += (i - it->first + m) % m;
			a[it->second.back()] += (i - it->first + m) % m;
			mp[i].push_back(it->second.back());
			mp[it->first].pop_back();
			it->second.pop_back();
			if (it->second.empty()) surplus.erase(it);
		}
	}

	printf("%d\n", score);

	fl (i, 0, n) printf("%d ", a[i]);

    return 0;
}
