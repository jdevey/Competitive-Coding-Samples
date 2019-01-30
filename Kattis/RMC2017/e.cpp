#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPal(string s) {
	for (int i = 0; i < s.size() / 2; ++i) if (s[i] != s[s.size() - i - 1]) return false;
	return true;
}

int bs(vector <int>& a, int val) {
	int base = 0, n = a.size();
	for (int jump = n; jump; jump /= 2) while (base + jump < n && a[base + jump] < val) base += jump;
	int d1 = val - a[base];
	int d2 = base == n - 1 ? d1 : a[base + 1] - val;
	if (d2 < d1) return a[base + 1];
	else return a[base];
}

int main() {

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector <int> pals;
	for (int i = 1e5; i < 1e6; ++i) if (isPal(to_string(i))) pals.push_back(i);

	for (int i = 0; i < n; ++i) {
		int val;
		cout << bs(pals, a[i]) << endl;
	}

	return 0;
}
