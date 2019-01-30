#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
using namespace std;
typedef long long ll;
typedef long double ld;

void dfs(int* a, set <pair <int, int>>& vis, vector <int>& ans, int ind, int f, int n) {
	if (vis.find({ind, f}) != vis.end()) return;
	vis.insert({ind, f});
	ans.push_back(f);
	if (ind == n - 1) {
		for (auto x : ans) cout << x + 1 << " ";
		exit(0);
	}
	if (a[ind] == a[ind + 1]) {
		fl (i, 0, 5) if (f != i) dfs(a, vis, ans, ind + 1, i, n);
	}
	else if (a[ind] < a[ind + 1]) {
		fl (i, 0, 5) if (f < i) dfs(a, vis, ans, ind + 1, i, n);
	}
	else if (a[ind] > a[ind + 1]) {
		fl (i, 0, 5) if (f > i) dfs(a, vis, ans, ind + 1, i, n);
	}
	ans.pop_back();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	int a[n];
	fl (i, 0, n) cin >> a[i];

    set <pair <int, int>> vis;

	vector <int> ans;
	fl (i, 0, n) dfs(a, vis, ans, 0, i, n);

	cout << -1;
	
    return 0;
}
