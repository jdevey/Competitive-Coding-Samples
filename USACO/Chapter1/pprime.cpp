/*
ID: deveyjo1
TASK: pprime
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	if (n == 2 || n == 3) return true;
	int sqt = sqrt(n);
	for (int i = 2; i <= sqt; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}


int main() {

	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w+", stdout);

	int n, m;
	cin >> n >> m;

	vector <int> pal;
	set <int> primes;
	for (int i = 1; i < 10000; ++i) {
		string s1 = to_string(i), s2 = s1;
		reverse(s2.begin(), s2.end());
		pal.push_back(stoi(s1 + s2));
		s1.pop_back();
		pal.push_back(stoi(s1 + s2));
	}

	for (auto x : pal) if (isPrime(x)) primes.insert(x);

	for (auto it = lower_bound(primes.begin(), primes.end(), n); *it <= m && it != primes.end(); ++it) printf("%d\n", *it);

	return 0;
}
