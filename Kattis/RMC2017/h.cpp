#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int t;
	cin >> t;
	while (t--) {
		int b;
		ld p;
		cin >> b >> p;
		cout << (b - 1) * 60.0 / p << " " << b * 60.0 / p << " " << (b + 1) * 60.0 / p << endl;
	}


	return 0;
}
