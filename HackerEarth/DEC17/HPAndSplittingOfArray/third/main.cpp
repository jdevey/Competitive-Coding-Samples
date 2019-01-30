//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstring>
#include <array>
#include <algorithm>

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

void addNode (Node* head, int newValue) {
    //Node* currParent = head;
    while (true) {
        ++head->sum;
        if (newValue < head->value) {
            if (head->leftC != nullptr) {
                head = head->leftC;
            }
            else {
                if (head->parent->parent != nullptr) {
                    if (head->rightC == nullptr) {
                        if (head->parent->leftC == head->parent) {
                            Node* newBrother = head->parent;
                            head->parent = head;
                            head->parent->rightC = newBrother;
                            head->parent->leftC = new Node(head->parent, nullptr, nullptr, newValue, 1);
                            head->sum = 2;
                            head->parent->rightC->sum = 1;
                            break;
                        }
                        else {
                            Node* newBrother = head->parent;
                            head->parent = new Node(head->parent->parent, nullptr, nullptr, newValue, 1);
                            head->parent->leftC = newBrother;
                            head->parent->sum = 2;
                            head->parent->leftC->sum = 1;
                            break;
                        }
                    }
                }
                head->leftC = new Node(head, nullptr, nullptr, newValue, 1);
                break;
            }
        }
        else {
            if (head->rightC != nullptr) {
                head = head->rightC;
            }
            else {
                head->rightC = new Node(head, nullptr, nullptr, newValue, 1);
                break;
            }
        }
    }
}

//Returns the number of elements in the binary search tree strictly less than the value passed to the function
int query (Node* head, int qValue) {
    //Node* currParent = head;
    int numLess = 0;
    while (true) {
        if (qValue < head->value) {
            if (head->leftC == nullptr) break;
            head = head->leftC;
        }
        else {
            int rightSub = 0;
            if (head->rightC != nullptr) rightSub += head->rightC->sum;
            numLess += head->sum - rightSub;
            if (rightSub == 0) break;
            head = head->rightC;
        }
    }
    return numLess;
}

int main() {

    ios_base::sync_with_stdio(false);

    //ifstream cin("zin.txt");

    int t, n;

    //scanf("%d", &t);
    cin >> t;

    while (t--) {
        //scanf("%d", &n);
        cin >> n;
        int a[n];
        //fl (i, n) scanf("%d", &a[i]);
        fl (i, n) cin >> a[i];

        //std::array <int, n> aCopy;
        int aCopy[n];
        fl (i, n) aCopy[i] = a[i];

        //sort(aCopy, aCopy + sizeof(aCopy) / sizeof(int));
        qsort(aCopy, (size_t)n, sizeof(int), compare);

        //int total = 0;
        ll total = binarySearch(aCopy, 0, n - 1, a[0]);
        auto BST = new Node(nullptr, nullptr, nullptr, a[0], 1);

        //Finding the value for the first rotation
        for (int i = 1; i < n; ++i) {
            total += binarySearch(aCopy, 0, n - 1, a[i]);
            total -= query(BST, a[i]);
            addNode(BST, a[i]);
        }

        //int finalValue = total;
        //cout << total << endl;

        fl (i, n) {
            ll rank = binarySearch(aCopy, 0, n - 1, a[i]);
            total += n - 2 * rank - 1;
            //printf("%lld ", &total);
            cout << total << " ";
        }
        //printf("\n");
        cout << endl;
    }

    return 0;
}