#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

void factorLister(vector <int>& completeList, int n) {
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			completeList.push_back(i);
			if (i * i != n) completeList.push_back(n / i);
		}
	}
	sort(completeList.begin(), completeList.end());
}

int main() {

	int n;
	cin >> n;
	vector <int> a(n);
	fl (i, 0, n) cin >> a[i];

	int mx = 0;
	fl (i, 0, n) mx = max(mx, a[i]);

	vector <int> fac;
	factorLister(fac, mx);

	for (auto x : fac) {
		a.erase(find(a.begin(), a.end(), x));
	}

	int end = 0;
	for (auto x : a) end = max(end, x);

	cout << mx << " " << end << endl;

    return 0;
}
