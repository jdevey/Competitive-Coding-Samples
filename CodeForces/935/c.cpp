#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <iomanip>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

bool isInside(ld r, ld x1, ld y1, ld x2, ld y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) < r;
}

int main() {

	ld r, x1, y1, x2, y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;

	if (!isInside(r, x1, y1, x2, y2)) {
		cout << fixed << setprecision(16) << x1 << " " << y1 << " " << r;
		return 0;
	}

	ld dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) + r;
	
	ld uvX = x1 - x2, uvY = y1 - y2;
	if (uvX == 0 && uvY == 0) {
		uvX = 1 / sqrt(2);
		uvY = 1 / sqrt(2);
	}
	else {
		uvX /= sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); uvY /= sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	}

	uvX *= r; uvY *= r;
	uvX += x1; uvY += y1;

	ld nx = (uvX + x2) / 2, ny = (uvY + y2) / 2;

	cout << fixed << setprecision(16) << nx << " " << ny << " " << dist / 2;

    return 0;
}
