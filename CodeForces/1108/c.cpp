#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int recolor(string& s, int sz, string begin) {
	int cnt = 0;
	fl (i, 0, sz) {
		int needed = i % 3;
		if (s[i] != begin[needed]) ++cnt;
	}
	return cnt;
}

void print(string begin, int sz, int cnt) {
	cout << cnt << endl;
	fl (i, 0, sz) cout << begin[i % 3];
	cout << endl;
}

int main() {

	int n;
	cin >> n;
	string s;
	cin >> s;

	int cnt = 1e9;
	string perm = "BGR";
	string recPerm;
	do {
		int rec = recolor(s, n, perm);
		if (rec < cnt) {
			cnt = rec;
			recPerm = perm;
		}
	} while (next_permutation(perm.begin(), perm.end()));

	print(recPerm, n, cnt);

    return 0;
}
