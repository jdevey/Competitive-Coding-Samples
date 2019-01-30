#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll smallestFactor(ll n) {
	for (int i = 4; i < max(100, (int)sqrt(n) + 1); i++)  {
		if (n % i == 0) {
			return i;
		}
	}

	return n;
}

int main() {;
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
			cout << smallestFactor(n - 3) << endl;
		}
		cin >> n;
	}
	

	return 0;
}
