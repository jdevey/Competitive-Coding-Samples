#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int gac, gbc;

void dfs(bool visited[], int n, int a, int b, int ac, int bc, bool& good) {
	if (n < 0) return;
	if (!n) {
		gac = ac; gbc = bc;
		good = true;
		return;
	}
	if (visited[n]) return;
	visited[n] = true;
	dfs(visited, n - a, a, b, ac + 1, bc, good);
	dfs(visited, n - b, a, b, ac, bc + 1, good);
}

int main() {

	int n, a, b;
	cin >> n >> a >> b;
	
	bool visited[n + 1] = {};
	bool good = false;
	dfs(visited, n, a, b, 0, 0, good);
	if (!good) return puts("-1");

	int ans[n];
	memset(ans, -1, sizeof(ans));
	fl (i, 0, gac) {
		fl (j, 1, a + 1) {
			ans[i * a + j % a] = i * a + (j % a ? j % a : a);
		}
	}
	fl (i, 0, gbc) {
		fl (j, 1, b + 1) {
			ans[a * gac + i * b + j % b] = a * gac + i * b + (j % b ? j % b : b);
		}
	}

	fl (i, 0, n) cout << ans[i] << " ";

    return 0;
}
