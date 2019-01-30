#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	ll t, s, a, b, c;
	cin >> t;
	while(t--) {
		cin >> s >> a >> b >> c;
		cout << s / c + s / c / a * b << endl;
	}

    return 0;
}
