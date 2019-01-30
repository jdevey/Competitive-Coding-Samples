#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	int a[n / 2];
	fl (i, 0, n / 2) cin >> a[i];

	sort(a, a + n / 2);

	//fl (i, 0, n / 2) cout << a[i] << " ";

	int score1 = 0, score2 = 0;
	int pt1 = 1, pt2 = 2;

	for (int i = 0; i < n / 2; ++i) {
		score1 += abs(a[i] - pt1);
		pt1 += 2;
		//cout << score1 << endl;
	}

	for (int i = 0; i < n / 2; ++i) {
		score2 += abs(a[i] - pt2);
		pt2 += 2;
	}

	cout << min(score1, score2);

    return 0;
}
