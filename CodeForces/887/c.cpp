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

bool im(int a, int b, int c, int d) {
	return a == b && a == c && a == d;
}

int main() {

	int a[25];
	fl (i, 1, 25) cin >> a[i];

	cout << (
		im(a[1], a[3], a[6], a[8]) &&
		im(a[5], a[7], a[10], a[12]) &&
		im(a[9], a[11], a[21], a[23]) &&
		im(a[22], a[24], a[2], a[4]) &&
		im(a[13], a[15], a[14], a[16]) &&
		im(a[17], a[17], a[18], a[20])

			||

		im(a[2], a[4], a[5], a[7]) &&
		im(a[6], a[8], a[9], a[11]) &&
		im(a[10], a[12], a[22], a[24]) &&
		im(a[21], a[23], a[1], a[3]) &&
		im(a[13], a[15], a[14], a[16]) &&
		im(a[17], a[17], a[18], a[20])

			||

		im(a[13], a[14], a[7], a[8]) &&
		im(a[5], a[6], a[19], a[20]) &&
		im(a[17], a[18], a[23], a[24]) &&
		im(a[21], a[22], a[15], a[16]) &&
		im(a[1], a[2], a[3], a[4]) &&
		im(a[9], a[10], a[11], a[12])

			||

		im(a[15], a[16], a[5], a[6]) &&
		im(a[7], a[8], a[17], a[18]) &&
		im(a[19], a[20], a[21], a[22]) &&
		im(a[23], a[24], a[13], a[14]) && 
		im(a[1], a[2], a[3], a[4]) &&
		im(a[9], a[10], a[11], a[12])

			||

		im(a[3], a[4], a[18], a[20]) &&
		im(a[17], a[19], a[11], a[12]) &&
		im(a[9], a[10], a[13], a[15]) &&
		im(a[14], a[16], a[1], a[2]) &&
		im(a[5], a[6], a[7], a[8]) &&
		im(a[21], a[22], a[23], a[24])

			||

		im(a[1], a[2], a[17], a[19]) &&
		im(a[18], a[20], a[9], a[10]) &&
		im(a[11], a[12], a[14], a[16]) &&
		im(a[13], a[15], a[3], a[4]) &&
		im(a[5], a[6], a[7], a[8]) &&
		im(a[21], a[22], a[23], a[24])
	
		? "YES" : "NO"
		);

    return 0;
}
