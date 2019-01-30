#include <bits/stdc++.h>

#define B 100000
#define fl(i,a,b) for(int(i)=(a);(i)<(b);++i)

using namespace std;

typedef long long ll;

void erato(vector <int>* fac) {
	fl (i, 2, 100001) for (int j = i; j < 100001; j += i) fac[j].push_back(i);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	vector <int>* fac = new vector <int>[100001]();
	erato(fac);

	int n;
	cin >> n;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	set <pair <int, int>> s;
	int mx = 1, *cs = new int[200001], *ident = new int[200001], *pt = new int[200001];
	memset(cs, 0, sizeof(cs));
	memset(ident, 0, sizeof(ident));
	memset(pt, -1, sizeof(pt));

	fl (i, 0, n) {
		//Recording
		++cs[a[i] + B];

		//Zero case
		if (!a[i]) continue;

		s.insert({a[i], -i});

		//Identical integer case
		mx = max(mx, cs[a[i] + B]);

		//Alternating signs case
		if (pt[a[i] + B] <= pt[-a[i] + B]) ident[a[i] + B] = ident[-a[i] + B] + 1;
		mx = max(mx, ident[a[i] + B]);
		pt[a[i] + B] = i;

		//K is positive
		for (auto it : fac[abs(a[i])]) {
			int x = a[i] / it, len = 1, top = -i;
			while (x) {
				auto f = s.lower_bound({x, top});
				try {
					if (f != s.end() && f->first == x) {
						++len;
						top = f->second;
						if (x % it == 0) x /= it;
						else break;
					}
					else break;
				}
				catch (std::exception& e) {
					cout << mx << endl;
				}
			}
			mx = max(mx, len);
		}

		//K is negative
		for (auto it : fac[abs(a[i])]) {
			int x = -a[i] / it, len = 1, top = -i;
			while (x) {
				auto f = s.lower_bound({x, top});
				try {
					if (f != s.end() && f->first == x) {
						++len;
						top = f->second;
						if (x % it == 0) x /= -it;
						else break;
					}
					else break;
				}
				catch (std::exception& e) {
					cout << mx << endl;
				}
			}
			mx = max(mx, len);
		}
	}
	mx = max(mx, cs[B] + (a[0] ? 1 : 0));

	cout << mx << endl;

	return 0;
}
