#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <deque>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))
/*
#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif
*/
using namespace std;

typedef long long ll;

int n, m;

vector <vector <int>> graph;

bool hasLoopRecurse(bool visited[], bool path[], int ind) {

	if (!visited[ind]) {
		visited[ind] = true;
		path[ind] = true;

		fl (i, 0, graph[ind].size()) {
			if (!visited[graph[ind][i]] && hasLoopRecurse(visited, path, graph[ind][i])) return true;
			else if (path[graph[ind][i]]) return true;
		}
	}

	path[ind] = false;
	return false;
}

bool hasLoop() {
	bool visited[n] = {};
	bool path[n] = {};
	fl (i, 0, n) if (hasLoopRecurse(visited, path, i)) return true;
	return false;
}

void printdp(int a[][26], int n, int v) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << v + 1 << endl;
	cout << endl;
}

int main() {

	char s[300000];
	scanf("%d %d %s", &n, &m, s);

	int deg[n] = {};
	fl (i, 0, n) graph.push_back(vector <int>());
	fl (i, 0, m) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a - 1].push_back(b - 1);
		++deg[b - 1];
	}

	if (hasLoop()) return puts("-1"), 0;

	int dp[n][26] = {};
	deque <int> di;
	fl (i, 0, n) if (!deg[i]) di.push_back(i);
	fl (i, 0, n) ++dp[i][s[i] - 'a'];
	
	int mx = 1;
	while (!di.empty()) {
		int v = di.front();
		//printdp(dp, n, v);
		fl (i, 0, graph[v].size()) {
			fl (j, 0, 26) {
				dp[graph[v][i]][j] = max(dp[v][j] + (j == s[graph[v][i]] - 'a'), dp[graph[v][i]][j]);
				int dpr = dp[graph[v][i]][j];
				mx = max(dpr, mx);
			}
			--deg[graph[v][i]];
			if (!deg[graph[v][i]]) di.push_back(graph[v][i]);
		}
		di.pop_front();
	}

	cout << mx;

    return 0;
}
