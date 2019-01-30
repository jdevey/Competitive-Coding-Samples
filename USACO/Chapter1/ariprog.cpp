/*
ID: deveyjo1
TASK: ariprog
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w+", stdout);

	int n, m;
	scanf("%d %d", &n, &m);

	vector <pair <int, int>> ans;

	set <int> S;
	for (int i = 0; i <= m; ++i) for (int j = 0; j <= m; ++j) S.insert(i * i + j * j);

	bool cs[125001] = {};
	vector <int> ref;
	for (auto x : S) {
		ref.push_back(x);
		cs[x] = true;
	}

	for (auto it1 = ref.begin(); it1 != ref.end(); ++it1) {
		auto it2 = it1;
		++it2;
		for (; it2 != ref.end(); ++it2) {
			int diff = *it2 - *it1;
			if (*it1 + diff * (n - 1) > *--ref.end()) break;
			for (int i = *it2 + diff, cnt = 2; i <= *--ref.end(); i += diff) {
				if (!cs[i]) break;
				++cnt;
				if (cnt == n) {
					ans.push_back({diff, *it1});
					break;
				}
			}
		}
	}

	if (ans.empty()) {
		cout << "NONE\n";
		return 0;
	}

	sort(ans.begin(), ans.end());
	for (auto x : ans) printf("%d %d\n", x.second, x.first);

    return 0;
}
