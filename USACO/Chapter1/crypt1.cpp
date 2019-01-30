/*
ID: deveyjo1
TASK: crypt1
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

bool isGood(bool* cs, int n) {
	while (n) {
		if (!cs[n % 10]) return false;
		n /= 10;
	}
	return true;
}

bool combGood(bool* cs, int n1, int n2) {
	return to_string(n2 % 10 * n1).size() == 3 & to_string(n2 / 10 * n1).size() == 3 & to_string(n2 * n1).size() == 4 & isGood(cs, n2 % 10 * n1) & isGood(cs, n2 / 10 * n1) & isGood(cs, n2 * n1);
}

pair <int, int> genPair(int* a, int n, int num) {
	int f = 0, s = 0;

	s += a[num % n];
	num /= n;
	s += a[num % n] * 10;
	num /= n;

	f += a[num % n];
	num /= n;
	f += a[num % n] * 10;
	num /= n;
	f += a[num % n] * 100;

	return make_pair(f, s);
}

int main() {
    
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w+", stdout);

	int n, cnt = 0;
	cin >> n;
	int a[n];
	bool cs[10] = {};
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		cs[a[i]] = true;
	}
	
	for (int i = 0; i < pow(n, 5); ++i) {
		pair <int, int> pi = genPair(a, n, i);
		if (combGood(cs, pi.first, pi.second)) ++cnt;
	}

	cout << cnt << endl;

    return 0;
}
