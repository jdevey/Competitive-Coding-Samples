#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define fl(i,n) for(int (i) = 0; (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int main() {

    int n;
	cin >> n;
	int a[n];
	fl (i, n) cin >> a[i];

	int freq[100001] = {};
	fl (i, n) freq[a[i]]++;

	bool good = false;
	fl (i, 100001) if (freq[i] & 1) good = true;

	cout << (good ? "Conan" : "Agasa") << endl;

    return 0;
}
