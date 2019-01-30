#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>

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

typedef unsigned long long ull;
typedef long long ll;
typedef vector <vector <int>> vvi;

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

int main() {

	string a, b;
	cin >> a >> b;
	int n = a.size();

	sort(a.begin(), a.end());

	string::size_type sz;
	ll bNum = stoll(b, &sz);
	ll grandMax = stoll(a, &sz);
	
	fl (i, n - 1) {
		fle (j, i + 1, n) {
			string s = a;
			swap(s[i], s[j]);
			sort(s.begin() + j, s.begin() + n);
			ll num = stoll(s, &sz);
			if (num > grandMax && num <= bNum) {
				grandMax = num;
				a = s;
			}
		}
	}

	cout << grandMax;

    return 0;
}

