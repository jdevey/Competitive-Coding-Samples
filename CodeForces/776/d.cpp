#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

vector <vector <pair <int, bool>>> graph;

void dfs(bool explored[], bool color[], bool& good, int node) {
	explored[node] = true;
	fl (i, 0, graph[node].size()) {
		if (explored[graph[node][i].first]) {
			if (graph[node][i].second ? color[graph[node][i].first] != color[node] : color[graph[node][i].first] == color[node]) good = false;
		}
		else {
			color[graph[node][i].first] = graph[node][i].second ? color[node] : !color[node];
			dfs(explored, color, good, graph[node][i].first);
		}
	}
}

int main() {

	int n, m;
	cin >> n >> m;
	bool type[n] = {};
	vector <vector <int>> rel (n, vector <int>());
	fl (i, 0, n) cin >> type[i];

	fl (i, 0, m) {
		int x;
		cin >> x;
		while (x--) {
			int a;
			cin >> a;
			rel[a - 1].push_back(i);
		}
	}

	fl (i, 0, m) graph.emplace_back(vector <pair <int, bool>>());
	fl (i, 0, n) {
		bool match = type[i];
		graph[rel[i][0]].push_back(make_pair(rel[i][1], match));
		graph[rel[i][1]].push_back(make_pair(rel[i][0], match));
	}

	bool color[m] = {};
	bool explored[m] = {}, good = true;

	fl (i, 0, m) if (!explored[i]) dfs(explored, color, good, i);

	cout << (good ? "YES" : "NO");

    return 0;
}
