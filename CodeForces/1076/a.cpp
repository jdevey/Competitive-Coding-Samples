#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int n;
	cin >> n;
	string s;
	cin >> s;

	fl (i, 0, n - 1) {
		if (s[i] > s[i + 1]) {
			s.erase(s.begin() + i);
			cout << s;
			return 0;
		}
	}

	s.pop_back();
	cout << s;

    return 0;
}
