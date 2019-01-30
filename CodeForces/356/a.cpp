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

int n, m;

void updateUtil(int* ST, int ind, int x) {
	ind += n;
	ST[ind] = x;
}

void update(int* ST, int ql, int qr, int sl, int sr, int x) {
	if (!ind) {
		if (sl >= ql && sr <= qr) {
			
		}
	}
}

int main() {

	cin >> n >> m;
	
	int ST[log2(n) * 4] = {};



    return 0;
}
