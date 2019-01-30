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

vector <vector <pair <int, char>>> graph;
int memo[100][100][26][2];

bool recurse(int ind1, int ind2, char c, bool isMax) {
	if (memo[ind1][ind2][c - 'a'][(int)isMax] == 0) return false;
	if (memo[ind1][ind2][c - 'a'][(int)isMax] == 1) return true;
	if (isMax) {
		fl (i, 0, graph[ind1].size()) {
			if (graph[ind1][i].second >= c && !recurse(graph[ind1][i].first, ind2, graph[ind1][i].second, !isMax)) {
				memo[ind1][ind2][c - 'a'][(int)isMax] = 1;
				return true;
			}
		}
	}
	else {
		fl (i, 0, graph[ind2].size()) {
			if (graph[ind2][i].second >= c && !recurse(ind1, graph[ind2][i].first, graph[ind2][i].second, !isMax)) {
				memo[ind1][ind2][c - 'a'][(int)isMax] = 1;
				return true;
			}
		}
	}
	memo[ind1][ind2][c - 'a'][(int)isMax] = 0;
	return false;
}

int main() {

	memset(memo, -1, sizeof(memo));

	int n, m;
	cin >> n >> m;

	fl (i, 0, n) graph.push_back(vector <pair <int, char>>());
	fl (i, 0, m) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		graph[a - 1].push_back(make_pair(b - 1, c));
	}

	fl (i, 0, n) {
		fl (j, 0, n) {
			if (recurse(i, j, 'a', true)) cout << 'A';
			else cout << 'B';
		}
		cout << endl;
	}

	return 0;
}

