#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	ll l, r;
	cin >> l >> r;
	ll ind = l;
	cout << "YES" << endl;
	while (ind < r) {
		cout << ind << " " << ind + 1 << endl;
		++++ind;
	}

    return 0;
}
