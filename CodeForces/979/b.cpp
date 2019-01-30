#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

bool isHomo(string s) {
	fl (i, 0, s.size()) if (s[i] != s[0]) return false;
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	int cs1[256] = {}, cs2[256] = {}, cs3[256] = {};

	for (auto x : s1) ++cs1[x];
	for (auto x : s2) ++cs2[x];
	for (auto x : s3) ++cs3[x];

	int mx1 = 0, mx2 = 0, mx3 = 0;
	fl (i, 0, 256) mx1 = max(mx1, cs1[i]);
	fl (i, 0, 256) mx2 = max(mx2, cs2[i]);
	fl (i, 0, 256) mx3 = max(mx3, cs3[i]);

	mx1 += n;
	mx2 += n;
	mx3 += n;

	if (mx1 > s1.size()) mx1 = s1.size();
	if (mx2 > s1.size()) mx2 = s1.size();
	if (mx3 > s1.size()) mx3 = s1.size();

	if (isHomo(s1) && n == 1) mx1 = s1.size() - 1;
	if (isHomo(s2) && n == 1) mx2 = s1.size() - 1;
	if (isHomo(s3) && n == 1) mx3 = s1.size() - 1;

	if (mx1 > mx2 && mx1 > mx3) cout << "Kuro";
	else if (mx2 > mx1 && mx2 > mx3) cout << "Shiro";
	else if (mx3 > mx2 && mx3 > mx1) cout << "Katie";
	else cout << "Draw";

    return 0;
}
