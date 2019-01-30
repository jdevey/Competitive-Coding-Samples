#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
	    for (int j = i; j < n; ++j) {
	        if (a[j] - a[i] > d) {
	            cnt = max(cnt, j - i);
	            break;
	        }
	        if (j == n - 1) cnt = max(cnt, j - i + 1);
	    }
	}
	cout << n - cnt;
	return 0;
}
