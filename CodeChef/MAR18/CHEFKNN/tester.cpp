#include <iostream>
#include <set>

#define fl(x,a,b) for (int (x) = (a); (x) < (b); ++(x))

using namespace std;

void dfs(set <string>& ss, string s, int kc, int& n, int& k) {
	fl (i1, 0, n)
		fl (i2, i1, n) {
			string sp = s;
			fl (i3, i1, i2 + 1) sp[i3] = '0' + kc;
			if (kc == k) ss.insert(sp);
			else dfs(ss, sp, kc + 1, n, k);
		}
}

int main() {
	freopen("zin.txt", "r", stdin);

	int t, n, k;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &k);

		set <string> ss;

		string s;
		fl (i, 0, n) s += '0';

		dfs(ss, s, 1, n, k);

		//for (auto x : ss) cout << x << endl;
		cout << ss.size() << endl;
	}

	return 0;
}
