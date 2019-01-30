#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int main() {

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		int a[n], b[n];
		fl (i, 0, n) cin >> a[i] >> b[i];

		int time = 1;
		fl (i, 0, n) {
			if (time <= a[i]) {
				time = a[i];
				cout << time << " ";
			}
			else if (time <= b[i]) {
				cout << time << " ";
			}
			else if (time > b[i]) {
				cout << 0 << " ";
				--time;
			}
			++time;
		}
		cout << endl;
	}

    return 0;
}
