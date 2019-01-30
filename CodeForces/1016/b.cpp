#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	string s, t;
	int g, gg, q;
	cin >> g >> gg >> q >> s >> t;

	vector <int> pos;
	int c = s.find(t);
	while (c != string::npos) {
		pos.push_back(c);
		c = s.find(t, c + 1);
	}

	//for (auto x : pos) cout << x << "! " << endl;

	while (q--) {
		int start, end;
		cin >> start >> end;
		--start;
		int cnt = 0;
		int ts = t.size();
		for (auto x : pos) if (x >= start && x <= end - ts) ++cnt;
		cout << cnt << endl;
		//cout << --upper_bound(pos.begin(), pos.end(), end - t.size()) - lower_bound(pos.begin(), pos.end(), start) + 1 << endl;
	}

    return 0;
}
