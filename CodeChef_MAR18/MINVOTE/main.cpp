#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
#define cin fin
std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int main() {

	int t, n;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		int a[n];
		fl (i, 0, n) scanf("%d", &a[i]);

		ll ra[n], la[n];
		priority_queue <ll> rq, lq;

		ll run = 0, cc = 0;
		fl (i, 1, n) {
			rq.push(a[i] - run);
			run += a[i];
		}
		run = 0;
		fl (i, 1, n) {
			while (!rq.empty() && rq.top() + run >= 0) {
				rq.pop();
				++cc;
			}
			run += a[i];
			ra[i - 1] = cc;
			--cc;
		}

		cc = 0;
		run = 0;
		for (int i = n - 2; i > -1; --i) {
			lq.push(a[i] - run);
			run += a[i];
		}
		run = 0;
		for (int i = n - 2; i > -1; --i) {
			while (!lq.empty() && lq.top() + run >= 0) {
				lq.pop();
				++cc;
			}
			run += a[i];
			la[i + 1] = cc;
			--cc;
		}

		ra[n - 1] = 0;
		la[0] = 0;

		fl (i, 0, n) printf("%d ", la[i] + ra[i]);
		printf("\n");
	}

	return 0;
}

