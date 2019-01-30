#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <set>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
#define cin fin
std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

void fill(queue <pair <pair <int, int>, int>>& pq, set <pair <int, int>>& m, int n, int i, int j, int depth) {
	int x = pq.front().first.first, y = pq.front().first.second;
	fl (a, 0, 2) {
		int rx = a ? i : -i;
		fl (b, 0, 2) {
			int ry = b ? j : -j;
			if (x + rx < n && x + rx > -1 && y + ry < n && y + ry > -1 && m.find({x + rx, y + ry}) == m.end()) {pq.push({{x + rx, y + ry}, depth}); m.insert({x + rx, y + ry});}
			if (x + ry < n && x + ry > -1 && y + rx < n && y + rx > -1 && m.find({x + ry, y + rx}) == m.end()) {pq.push({{x + ry, y + rx}, depth}); m.insert({x + ry, y + rx});}
		}
	}
}

int main() {

	int n;
	cin >> n;

	int ans[n][n];

	fl (i, 1, n) {
		fl (j, 1, n) {
			//BFS
			queue <pair <pair <int, int>, int>> pq;
			set <pair <int, int>> m;
			pq.push({{0, 0}, 0});
			m.insert({0, 0});
			bool found = false;

			while (!pq.empty()) {
				fill(pq, m, n, i, j, pq.front().second + 1);
				if (pq.front().first.first == n - 1 && pq.front().first.second == n - 1) {
					ans[i][j] = pq.front().second;
					found = true;
					break;
				}
				pq.pop();
			}
			if (!found) ans[i][j] = -1;
		}
	}

	fl (i, 1, n) {
		fl (j, 1, n) cout << ans[i][j] << " ";
		cout << endl;
	}

	return 0;
}

