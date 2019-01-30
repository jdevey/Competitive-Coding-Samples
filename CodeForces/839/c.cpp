#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <iomanip>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

vector <long double> lens;
vector <vector <int>> graph;

void dfs(int node, int depth, long double whole, bool visited[]) {
	bool rc = true;
	if (!graph[node].empty()) {
		fl (i, 0, graph[node].size()) {
			if (!visited[graph[node][i]]) {
				rc = false;
				visited[graph[node][i]] = true;
				dfs(graph[node][i], depth + 1, whole / (node == 0 ? graph[node].size() : graph[node].size() - 1), visited);
			}
		}
	}
	if (rc) lens.push_back(depth * whole);
}

int main() {

    int n;
	cin >> n;
	fl (i, 0, n) graph.emplace_back(vector <int>());
	fl (i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	bool visited[n] = {};
	visited[0] = true;
	dfs(0, 0, 1.0, visited);

	//fl (i, 0, lens.size()) cout << lens[i] << endl;

	long double sum = 0;
	fl (i, 0, lens.size()) sum += lens[i];
	cout << fixed << setprecision(16) << (n == 1 ? 0 : sum);

    return 0;
}
