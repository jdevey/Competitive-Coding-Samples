#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

vector <set <int>> nadj (200001, set <int>());
set <int> uv;

void dfs(int node, int& sz) {
	++sz;
	uv.erase(node);
	int lowLim = 0;
	while (true) {
		auto next = uv.upper_bound(lowLim);
		if (next == uv.end()) return;
		lowLim = *next;
		if (nadj[node].find(lowLim) == nadj[node].end()) dfs(lowLim, sz);
	}
}

int main() {

	int n, m;
	cin >> n >> m;
	fl (i, 0, m) {
		int a, b;
		cin >> a >> b;
		nadj[a - 1].insert(b - 1);
		nadj[b - 1].insert(a - 1);
	}
	fl (i, 0, n) uv.insert(i);

	vector <int> sizes;
	int count = 0, sz = 0;
	fl (i, 0, n) {
		if (uv.find(i) != uv.end()) {
			dfs(i, sz); ++count;
			sizes.push_back(sz);
			sz = 0;
		}
	}

	cout << count << endl;
	sort(sizes.begin(), sizes.end());
	fl (i, 0, sizes.size()) cout << sizes[i] << " ";

    return 0;
}
