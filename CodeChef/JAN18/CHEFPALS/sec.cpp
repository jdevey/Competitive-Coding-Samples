#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <random>
#include <ctime>
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

typedef long long ll;
typedef vector <vector <int>> vvi;

clock_t start = clock();

template <class T> void swapp (T& a, T& b)
{
    T c(std::move(a)); a=std::move(b); b=std::move(c);
}

//QUICKSORT STUFF
int partitioner(int start, int end, int array[], string arraySister[]) {

    int pivot=array[start];
    int i=start-1;
    int j=end+1;

    while(true) {
        do {
            i++;
        } while (array[i]<pivot);

        do {
            j--;
        } while (array[j]>pivot);

        if (i>=j) return j;

        swapp(array[i], array[j]);
        swapp(arraySister[i], arraySister[j]);
    }
}

void quicksort(int start, int end, int array[], string arraySister[]) {

    if (start<end) {

        int p=partitioner(start, end, array, arraySister);

        //Lower quicksort
        quicksort(start, p, array, arraySister);

        //Higher quicksort
        quicksort(p+1, end, array, arraySister);
    }
    else return;
}

void shuff(string a[], int num[], int n) {
	fl (i, n) {
		int rn = rand() % n;

		int t = num[i];
		string temp = a[i];

		num[i] = num[rn];
		a[i] = a[rn];

		num[rn] = t;
		a[rn] = temp;
	}
}

int palCount(string s[], int n) {
	string nns;
	int count = 0;
	fl (i, n) {
		int wCount = 0;
		fl (j, s[i].size()) {
            if (s[i][j] == 'w') ++ wCount;
            else {
                if (wCount != 0) nns += to_string(wCount);
                wCount = 0;
            }
		}
        if (wCount != 0) nns += to_string(wCount);
	}
    size_t sz = nns.size();
	fl (i, sz)
        if (nns[i] != nns[sz - i - 1]) ++count;
	return count;
}

int main() {

	srand(time(NULL));

    int n;

	cin >> n;
	int a[n], b[n], num[n];
	fl (i, n) cin >> a[i];
	fl (i, n) cin >> b[i];
	fl (i, n) num[i] = i + 1;

	double tim = 0.0;

	string ss[n];
	fl (i, n) {
		string ts;
		fl (j, a[i] - b[i]) ts += 'w';
		fl (j, b[i]) ts += 'b';
		ss[i] = ts;
	}
	//string ssCopy[n];
	//fl (i, n) ssCopy[i] = ss[i];

	int grandMin = INF;
	string grandArr[n];
	int grandA[n];

	while (tim < 0.96) {
		shuff(ss, num, n);
		int p = palCount(ss, n);
		if (p < grandMin) {
			grandMin = p;
			fl (i, n) grandArr[i] = ss[i];
			fl (i, n) grandA[i] = num[i];
		}
		clock_t end = clock();
		tim = (end - start) / (CLOCKS_PER_SEC * 1.0);
	}

	int nCopy[n];
	fl (i, n) nCopy[i] = grandA[i];
/*
	cout << endl << grandMin << endl;
	fl (i, n) cout << grandArr[i] << " ";
	cout << endl;
	fl (i, n) cout << grandA[i] << " ";
	cout << endl;
*/
	//transposing the array back into original order
	quicksort(0, n - 1, grandA, grandArr);

	fl (i, n) cout << grandArr[i] << endl;
	fl (i, n) cout << nCopy[i] << " ";

    return 0;
}

