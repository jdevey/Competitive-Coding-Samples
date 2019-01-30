#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m;
	cin >> n >> m;
	int s[m], d[m], c[m];
	fl (i, 0, m) cin >> s[i] >> d[i] >> c[i];

	fl (i, 0, m) {--s[i]; --d[i];}

	vector <int> release[n];
	int prog[m] = {}, mp[n] = {};
	priority_queue <pair <int, int>, vector <pair <int, int>>, greater<>> pq;

	fl (i, 0, n) mp[i] = -1;
	fl (i, 0, m) mp[d[i]] = i;
	fl (i, 0, m) release[s[i]].push_back(i);

	int ans[n];

	fl (i, 0, n) {
		for (auto x : release[i]) {
			pq.push({d[x], x});
		}
		if (mp[i] > -1) {
			if (prog[mp[i]] < c[mp[i]]) return puts("-1");
			else ans[i] = m + 1;
		}
		else if (!pq.empty()) {
			++prog[pq.top().second];
			ans[i] = pq.top().second + 1;
			if (prog[pq.top().second] == c[pq.top().second]) pq.pop();
		}
		else ans[i] = 0;
	}

	fl (i, 0, n) cout << ans[i] << " ";

    return 0;
}
