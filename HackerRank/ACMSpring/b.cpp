#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int sumDig(int n) {
	int sum = 0;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	string ans;

	fl (i, 0, 4) {
		int hSum = 0, mSum = 0;
		fl (j, 0, 4) {
			int n;
			cin >> n;
			hSum += n / 100;
			mSum += n % 100;
		}
		hSum %= 24;
		mSum %= 60;

		int g = (hSum + mSum) % 42;
		int s = sumDig(g);
		int sdd = sumDig(s);

		if (s < 10) ans += to_string(s);
		else ans += to_string(sdd);
	}

	cout << ans << endl;

    return 0;
}
