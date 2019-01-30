#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

ll fac[20] = {};

ll ncr(ll n, ll k) {
	if (k < 0) return 0;
	return fac[n] / fac[k] / fac[n - k];
}

ll cp(string s) {
	int cs[10] = {};
	for (auto c : s) ++cs[c - '0'];
	ll prod1 = 1, sz = s.size();
	fl (i, 0, 10) {
		prod1 *= ncr(sz, cs[i]);
		sz -= cs[i];
	}
	ll prod2 = cs[0];
	sz = s.size() - 1;
	--cs[0];
	fl (i, 0, 10) {
		prod2 *= ncr(sz, cs[i]);
		sz -= cs[i];
	}
	return prod1 - prod2;
}

string mkstr(int* cs) {
	string ret;
	fl (i, 0, 10) {
		fl (j, 0, cs[i]) {
			ret += (char)('0' + i);
		}
	}
	return ret;
}

void printcs(int* cs) {
	fl (i, 0, 10) cout << i << " " << cs[i] << endl;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	fac[0] = 1;
	fl (i, 1, 20) fac[i] = fac[i - 1] * i;

	string s;
	cin >> s;

	int cs[10] = {};
	fl (i, 0, 10) ++cs[s[i] - '0'];

	ll prod = 1;
	fl (i, 0, 10) if (cs[i]) prod *= cs[i];

	ll sm = 0;

	fl (i, 0, prod) {
		int ccs[10] = {};
		int pr = i;
		fl (j, 0, 10) {
			if (!cs[j]) continue;
			ccs[j] = pr % cs[j] + 1;
			pr /= cs[j];
		}
		sm += cp(mkstr(ccs));
	}

	cout << sm << endl;

    return 0;
}
