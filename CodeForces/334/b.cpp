#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	pair <int, int> a[8];
	fl (i, 0, 8) cin >> a[i].first >> a[i].second;

	fl (i, 0, 8) fl (j, i + 1, 8) if (a[i].first == a[j].first && a[i].second == a[j].second) return puts("ugly");

	int hCount = 0, vCount = 0;
	map <int, int> hm, vm;
	fl (i, 0, 8) ++hm[a[i].first];
	fl (i, 0, 8) ++vm[a[i].second];

	if (hm.size() != 3 || vm.size() != 3) return puts("ugly");

	map <int, int> hc, vc;
	for (map <int, int>::iterator mi = hm.begin(); mi != hm.end(); ++mi) ++hc[mi->second];
	for (map <int, int>::iterator mi = vm.begin(); mi != vm.end(); ++mi) ++vc[mi->second];

	if (hc.find(3) == hc.end() || hc.find(2) == hc.end() || vc.find(3) == vc.end() || vc.find(2) == vc.end() ||
			hc.find(3)->second != 2 || hc.find(2)->second != 1 || vc.find(3)->second != 2 || vc.find(2)->second != 1) return puts("ugly");

	auto hi = hm.begin(), vi = vm.begin();
	++hi; ++vi;
	if (hi->second != 2 || vi->second != 2) return puts("ugly");

    return puts("respectable");
}
