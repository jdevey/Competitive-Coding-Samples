#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <random>
#include <ctime>

#define BIG 1000000007
#define INF 0x7fffffff
#define INFL 0x7fffffffffffffffLL
#define SPEED_IO ios_base::sync_with_stdio(false);
#define fl(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define fle(i,l,u) for(int (i) = (l);(i) < (u); ++(i))
#define ea(it,a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
#define mset(m,v) memset(m,v,sizeof(m))
#define sz(x) (x).size()

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;
typedef vector <vector <int>> vvi;

clock_t start = clock();

int main() {

	srand(time(NULL));

    int n;

	cin >> n;
	int a[n], b[n], num[n];
	fl (i, n) cin >> a[i];
	fl (i, n) cin >> b[i];
	fl (i, n) num[i] = i + 1;

	string ss[n];
	fl (i, n) {
		fl (j, a[i] - b[i]) {
			ss[i] += 'w';
		}
		fl (j, b[i]) {
			ss[i] += 'b';
		}
		/*fl (j, n) {
            int rn = rand() % n;
            char temp = ss[i][j];
     	    ss[i][j] = ss[i][rn];
            ss[i][rn] = temp;
        }*/
	}
	fl (i, n) {
        int rn = rand() % n;
        int temp = num[i];
        num[i] = num[rn];
        num[rn] = temp;
    }

	fl (i, n) cout << ss[i] << endl;
	fl (i, n) cout << num[i] << " ";
	cout << endl;

    return 0;
}
