#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int cnt = 0;
/*
template <class T> void swap (T& a, T& b)
{
    T c(std::move(a)); a=std::move(b); b=std::move(c);
}
template <class T, size_t N> void swap (T (&a)[N], T (&b)[N])
{
    for (size_t i = 0; i<N; ++i) swap (a[i],b[i]);
}
*/
//QUICKSORT STUFF
int partitioner(int start, int end, int array[]) {

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

        swap(array[i], array[j]);
		++cnt;
    }

}

void quicksort(int start, int end, int array[]) {

    if (start<end) {

        int p=partitioner(start, end, array);

        quicksort(start, p, array);

        quicksort(p+1, end, array);
    }
    else return;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	int a[n];
	fl (i, 0, n) scanf("%d", &a[i]);

	set <pair <int, int>> s;

	quicksort(0, n - 1, a);

	cout << ((n & 1) == (cnt & 1) ? "Petr" : "Um_nik") << endl;
	//cout << cnt << endl;

    return 0;
}
