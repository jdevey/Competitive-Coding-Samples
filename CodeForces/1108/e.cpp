#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int n, m;
	cin >> n >> m;
	int a[n];
	fl (i, 0, n) cin >> a[i];
	pair <int, int> segs[m];
	fl (i, 0, m) cin >> segs[i].first >> segs[i].second;
	fl (i, 0, m) --segs[i].first, --segs[i].second;

	int mxDiff = 0;
	vector <int> bestAns;
	fl (i, 0, n) {
		fl (j, 0, n) {
			if (i == j) continue;
			vector <int> currAns;
			int mx = a[i], mn = a[j];
			fl (k, 0, m) {
				if (segs[k].first <= j && segs[k].second >= j && !(segs[k].first <= i && segs[k].second >= i)) {
					--mn;
					currAns.push_back(k + 1);
				}
			}
			int diff = mx - mn;
			if (diff > mxDiff) {
				mxDiff = diff;
				bestAns = currAns;
			}
		}
	}

	cout << mxDiff << endl;
	cout << bestAns.size() << endl;
	for (auto x : bestAns) {
		cout << x << " ";
	}
	cout << endl;

    return 0;
}
