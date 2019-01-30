#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int n;
	cin >> n;
	cout << (n % 4 == 0 || n % 4 == 3 ? 0 : 1);

    return 0;
}
