#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <utility>
#include <set>
#include <iomanip>
#include <tuple>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
#define cin fin
std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

ll n, m, r;

ll mn(ll a, ll b) {
	return a < b ? a : b;
}

ll findVal(ll i, ll j) {
    return mn(r * r, min(mn(i, r), mn(n - r + 1, n - i + 1)) * mn(min(j, r), mn(m - r + 1, m - j + 1)));
}

int main() {

    ll k;
    cin >> n >> m >> r >> k;

    ll sum = 0;
    priority_queue <tuple <ll, ll, ll, ll>> q;
    set <pair <ll, ll>> s;

    ll x = (n + 1) / 2, y = (m + 1) / 2, indx = 0;

    sum = findVal(x, y);
    q.push(make_tuple(sum, 0, x, y));
    s.insert(make_pair(x, y));

    fl (i, 1, k) {
        if (x != 1 && s.find(make_pair(x - 1, y)) == s.end()) {
			s.insert(make_pair(x - 1, y));
            q.push(make_tuple(findVal(x - 1, y), indx - 1, x - 1, y));
		}
        if (x != n && s.find(make_pair(x + 1, y)) == s.end()) {
			s.insert(make_pair(x + 1, y));
            q.push(make_tuple(findVal(x + 1, y), indx - 1, x + 1, y));
		}
        if (y != 1 && s.find(make_pair(x, y - 1)) == s.end()) {
			s.insert(make_pair(x, y - 1));
            q.push(make_tuple(findVal(x, y - 1), indx - 1, x, y - 1));
		}
        if (y != m && s.find(make_pair(x, y + 1)) == s.end()) {
			s.insert(make_pair(x, y + 1));
            q.push(make_tuple(findVal(x, y + 1), indx - 1, x, y + 1));
		}
        --indx;

        q.pop();
        sum += get <0> (q.top());
        x = get <2> (q.top()), y = get <3> (q.top());
    }

    cout << fixed << setprecision(12) << 1.0 * sum / ((ll)(n - r + 1) * (m - r + 1));

    return 0;
}

