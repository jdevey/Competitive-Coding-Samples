//Good for the first two types of test cases

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

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

class LST {
public:
    int val;
    LST* next = nullptr;
    LST* prv = nullptr;
    LST (int _val) {
        val = _val;
    }
};

void caseTwo(int n, int q, ll a[], const ll* x, const ll* y) {
	bool dead[n] = {};
    bool nul[q] = {};

    LST* head = new LST(0);
    LST* prev = head;
    for (int i = 1; i < n; ++i) {
        LST* node = new LST(i);
        node->prv = prev;
        prev->next = node;
        prev = node;
    }

    fl (i, q - 1) {
        if (!nul[i]) {
            for (int j = i + 1; j < q; ++j) {
                //cout << x[i] << " " << x[j] << " " << (x[i] & x[j]) << " " << ((x[i] & x[j]) == x[j]) << endl;
                if ((x[j] & x[i]) == x[j]) nul[j] = true;
            }
        }
    }

    int run = n;
    fl (i, q) {
        //cout << "r " << run << endl;
        if (nul[i]) cout << run << endl;
        else {
            LST* currNode = head;
            while (currNode != nullptr) {
                LST* temp = currNode->next;
                if (!dead[currNode->val] && (x[i] & currNode->val) == currNode->val) {
                    dead[currNode->val] = true;
                    --run;

                    //Deleting a node from the list
                    if (currNode->prv == nullptr && currNode->next != nullptr) {
                        head = head->next;
                        currNode->next->prv = nullptr;
                    }
                    else if (currNode->prv != nullptr && currNode->next == nullptr) {
                        currNode->prv->next = nullptr;
                    }
                    else if (currNode->prv != nullptr && currNode->next != nullptr) {
                        currNode->prv->next = currNode->next;
                        currNode->next->prv = currNode->prv;
                    }
                    else {
                        head = nullptr;
                    }
                    delete currNode;
                }
                currNode = temp;
            }
            cout << run << endl;
        }
    }
}

void caseOne(int n, int q, ll a[], const ll* x, const ll* y) {
	bool deads[n] = {};
	int liveCount = n;
	fl (i, q) {
		fl (j, n) {
			if ((j & x[i]) == j) {
				a[j] -= y[i];
				if (!deads[j] && a[j] < 1) {
					--liveCount;
					deads[j] = true;
				}
			}
		}
		cout << liveCount << endl;
	}
}

int main() {

    int n, q;

	cin >> n;
	ll a[n];
	fl (i, n) cin >> a[i];
	cin >> q;
	ll x[q], y[q];
	fl (i, q) cin >> x[i] >> y[i];

	//Determining which test case we are dealing with
	bool c2 = true;
	fl (i, n) if (a[i] != 1) c2 = false;
	fl (i, q) if (y[i] != 1) c2 = false;

	if (!c2) caseOne(n, q, a, x, y);
	else caseTwo(n, q, a, x, y);

    return 0;
}
