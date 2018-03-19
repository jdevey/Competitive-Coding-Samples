#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <deque>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
#define cin fin
std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	int cts[n + 1] = {};
	cts[0] = 1;
	vector <deque <int>> pos;
	fl (i, 0, n + 1) pos.emplace_back(deque <int>());
	fl (i, 0, n) {
		++cts[a[i]];
		pos[a[i]].push_back(i + 1);
	}

	int count = 0;
	fl (i, 1, n + 1) if (!cts[i]) ++count;

	cout << count << endl;

	int ans[n + 1];
	memset(ans, -1, sizeof(ans));

	int mn = 0;
	fl (i, 1, n + 1) {
		if (cts[i] == 1) {
			ans[pos[i][0]] = i;
			--cts[i];
		}
		else if (cts[i] > 1) {
			ans[pos[i][0]] = i;
			--cts[i];
			pos[i].pop_front();
		}
		else {
			fl (j, mn, n) {
				if (ans[j + 1] == -1 && (cts[a[j]] > 1 || cts[a[j]] == 1 && a[j] < i)) {
					mn = j;
					break;
				}
			}
			ans[pos[a[mn]][0]] = i;
			pos[a[mn]].pop_front();
			--cts[a[mn]];
			++mn;
		}
	}

	fl (i, 1, n + 1) cout << ans[i] << " ";

	return 0;
}
