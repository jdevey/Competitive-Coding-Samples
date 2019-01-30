#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int main() {

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set <string> s;
		for (int i = 0; i < n; ++i) {
			string ss;
			cin >> ss;
			s.insert(ss);
		}
		cout << s.size() << endl;
	}

	return 0;
}
