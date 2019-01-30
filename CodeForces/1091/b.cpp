#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int n;
	cin >> n;
	pair <int, int> pos[n], vec[n];
	fl (i, 0, n) cin >> pos[i].first >> pos[i].second;
	fl (i, 0, n) cin >> vec[i].first >> vec[i].second;

	map <pair <int, int>, int> occ;

	fl (i, 0, n) {
		fl (j, 0, n) {
			auto p = make_pair(pos[i].first + vec[j].first, pos[i].second + vec[j].second);
			++occ[p];
			if (occ[p] == n) {
				cout << p.first << " " << p.second << endl;
				return 0;
			}
		}
	}

    return 0;
}
