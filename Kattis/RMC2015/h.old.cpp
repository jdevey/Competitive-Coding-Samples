#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> primeSieve(ll n) {
	vector<bool> isPrime(n + 1, true);

	vector<ll> primes;

	for (ll i = 4; i < isPrime.size(); i++) {
		if (isPrime[i]) {		
			primes.push_back(i);
			for (ll j = i * i; j < isPrime.size(); j += i) {
				isPrime[j] = false;
			}
		}
	}

	return primes;
}	

ll smallestFactor(vector<ll>& primes, ll n) {
	for (const auto& p : primes) {
		if (n % p == 0) {
			return p;
		}
	}

	return n;
}

int main() {
	auto primes = primeSieve(sqrt(1ll << 31 + 1));

	ll n;
	cin >> n;
	while (n > 0) {
		if (n == 3) {	
			cout << 4 << endl;
		}
		else if (n < 7) {
			cout << "no such base" << endl;
		}
		else {
			cout << smallestFactor(primes, n - 3) << endl;
		}
		cin >> n;
	}
	

	return 0;
}
