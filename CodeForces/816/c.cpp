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

vector <string> rowFirst(int n, int m, vector <vector <int>> g) {
	vector <string> moves;

	fl (i, 0, n) {
		int mn = 1000000;
		fl (j, 0, m) {
			if (g[i][j] < mn) mn = g[i][j];
		}
		fl (j, 0, m) {
			g[i][j] -= mn;
		}
		fl (j, 0, mn) moves.push_back("row " + to_string(i + 1));
	}
	fl (i, 0, m) {
		int mn = 1000000;
		fl (j, 0, n) {
			if (g[j][i] < mn) mn = g[j][i];
		}
		fl (j, 0, n) {
			g[j][i] -= mn;
		}
		fl (j, 0, mn) moves.push_back("col " + to_string(i + 1));
	}

	bool empty = true;
	fl (i, 0, n) fl (j, 0, m) if (g[i][j]) empty = false;

	if (!empty) {
		moves.clear();
		moves.push_back("-1");
	}
	return moves;
}

vector <string> colFirst(int n, int m, vector <vector <int>> g) {
	vector <string> moves;

	fl (i, 0, m) {
		int mn = 1000000;
		fl (j, 0, n) {
			if (g[j][i] < mn) mn = g[j][i];
		}
		fl (j, 0, n) {
			g[j][i] -= mn;
		}
		fl (j, 0, mn) moves.push_back("col " + to_string(i + 1));
	}
	fl (i, 0, n) {
		int mn = 1000000;
		fl (j, 0, m) {
			if (g[i][j] < mn) mn = g[i][j];
		}
		fl (j, 0, m) {
			g[i][j] -= mn;
		}
		fl (j, 0, mn) moves.push_back("row " + to_string(i + 1));
	}

	bool empty = true;
	fl (i, 0, n) fl (j, 0, m) if (g[i][j]) empty = false;

	if (!empty) {
		moves.clear();
		moves.push_back("-1");
	}
	return moves;
}

int main() {

	int n, m;
	cin >> n >> m;
	vector <vector <int>> g(n, vector <int> (m, 0));
	fl (i, 0, n) fl (j, 0, m) cin >> g[i][j];

	vector <string> rf, cf;
	rf = rowFirst(n, m, g);
	cf = colFirst(n, m, g);

	if (rf.size() && rf[0] == "-1") return puts("-1");

	if (rf.size() < cf.size()) {
		cout << rf.size() << endl;
		fl (i, 0, rf.size()) cout << rf[i] << endl;
	}
	else {
		cout << cf.size() << endl;
		fl (i, 0, cf.size()) cout << cf[i] << endl;
	}
    return 0;
}
