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

int main() {

	int l, c, g, j;
	cin >> l >> c >> g >> j;

	vector <int> dist;
	dist.push_back(g);
	bool isf = true;
	fl (i, 0, j - 1) {
		dist.insert(dist.end(), {isf ? 2 * (l - g) : 2 * g});
		isf = !isf;
	}
	dist.push_back(j & 1 ? l - g : g);

	if ((j == 1 && (g > c || l - g > c)) || (j == 2 && (2 * (l - g) > c || g > c)) || (j > 2 && (2 * (l - g) > c || 2 * g > c))) return puts("-1");

	int gas = c, count = 0;
	fl (i, 0, dist.size()) {
		//cout << i << " " << gas << " ";
		if (gas - dist[i] < 0) {
			gas = min(c, gas + c);
			++count;
		}
		gas -= dist[i];
		//cout << gas << endl;
	}

	cout << count;

    return 0;
}
