#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int n;
	cin >> n;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	vector <int> dist;
	fl (i, 1, n - 1) if (!a[i] && a[i - 1] && a[i + 1]) dist.push_back(i);

	int doub = 0;
	bool vis[dist.size()] = {};
	for (int i = dist.size() - 1; i > 0; --i) {
		if (!vis[i] && dist[i] == dist[i - 1] + 2) {
			++doub;
			vis[i] = true;
			vis[i - 1] = true;
		}
	}

	cout << dist.size() - doub << endl;

    return 0;
}
