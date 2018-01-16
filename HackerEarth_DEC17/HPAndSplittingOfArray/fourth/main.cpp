//DONE

//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstring>
#include <array>
#include <algorithm>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

using namespace std;

typedef long long ll;
typedef vector <vector <int>> vvi;

class Node {
public:
    Node* parent;
    Node* leftC;
    Node* rightC;

    int value;
    int sum;

    Node(Node* _parent, Node* _leftC, Node* _rightC, int _value, int _sum) {
        parent = _parent;
        leftC = _leftC;
        rightC = _rightC;
        value = _value;
        sum = _sum;
    }
};

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int binarySearch(const int* array, int start, int end, int desired) {
    while (start <= end) {

        int mid = start + (end - start) / 2;

        if (array[mid] == desired) return mid;
        else if (desired > array[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);

    //ifstream cin("zin.txt");

    int t, n;

    cin >> t;

    while (t--) {
        cin >> n;
        int a[n];
        fl (i, n) cin >> a[i];

        int aCopy[n];
        fl (i, n) aCopy[i] = a[i];

        qsort(aCopy, (size_t) n, sizeof(int), compare);

        ll total = 0;
        using namespace __gnu_pbds;
        tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> BST;
        total += binarySearch(aCopy, 0, n - 1, a[0]);
        BST.insert(a[0]);

        //Finding the value for the first rotation
        for (int i = 1; i < n; ++i) {
            total += binarySearch(aCopy, 0, n - 1, a[i]);
            total -= BST.order_of_key(a[i]);
            BST.insert(a[i]);
        }

        fl (i, n) {
            ll rank = binarySearch(aCopy, 0, n - 1, a[i]);
            total += n - 2 * rank - 1;
            cout << total << " ";
        }

        cout << endl;
    }

    return 0;
}