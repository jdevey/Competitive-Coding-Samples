#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

	int segLen = 1e9, right = 1e9, left = 0;

	for (int i = 0; i < n; ++i) {
		right = min(right, b[i]);
		left = max(left, a[i]);
		segLen = right - left;
	}

	multiset <int> sa, sb;
	for (int i = 0; i < n; ++i) {
		sa.insert(a[i]);
		sb.insert(b[i]);
	}

	//cout << "! " << right << " " << left << endl;

	for (int i = 0; i < n; ++i) {
		sa.erase(sa.find(a[i]));
		auto it = sa.upper_bound(left);
		if (it != sa.begin()) --it;
		//if (it == sa.begin()) {++it; cout << "hi";}

		sb.erase(sb.find(b[i]));
		auto iit = sb.lower_bound(right);
		if (iit == sb.end()) --iit;

		//cout << *it << " " << *iit << endl;

		segLen = max(segLen, *iit - *it);

		sa.insert(a[i]);
		sb.insert(b[i]);
	}

	cout << max(segLen, 0) << endl;

    return 0;
}
