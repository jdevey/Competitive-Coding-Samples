//DONE

//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstring>

#define ll long long
#define vvi vector <vector <int>>
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

using namespace std;

//TODO Binary search that returns the index of the element to the LEFT of index that is inputted

//TODO Binary search that returns the index of the element to the RIGHT of index that is inputted

int main() {

    //ifstream cin("zin3.txt");

    int n, q, y, z;
    char d;

    cin >> n >> q;
    int a[n];

    fl (i, n) cin >> a[i];

    //List of indices of vertices with a given value
    vvi pos;
    vector <int> emptyVec;
    fl (i, 200001) pos.emplace_back(emptyVec);
    fl (i, n) pos[a[i]].push_back(i);

    while (q--) {
        cin >> y >> z >> d;
        int index = 0, distance;
        auto loopSize = (int)pos[z].size();

        if (d == 76) {
            if (pos[z].empty()) {
                cout << -1 << endl;
                continue;
            }
            else if (pos[z].size() == 1) {
                if (pos[z][0] == y) distance = 0;
                else if (pos[z][0] > y) distance = n - pos[z][0] + y;
                else distance = y - pos[z][0];
                cout << distance << endl;
                continue;
            }
            else if (pos[z][0] > y || pos[z][loopSize - 1] < y) {
                if (pos[z][0] > y) distance = n - pos[z][loopSize - 1] + y;
                else distance = y - pos[z][loopSize - 1];
                cout << distance << endl;
                continue;
            }
            while (true) {
                //if (index >= loopSize) break;
                if ((pos[z][index] == y) || (pos[z][index] < y && pos[z][(index + 1) % loopSize] > y)) {
                    if (pos[z][index] == y) distance = 0;
                    //else if (pos[z][index] > y) distance = n - pos[z][index] + y;
                    else distance = y - pos[z][index];
                    break;
                }
                ++index;
            }
            //if (distance == -5) distance = pos[z][pos[z].size()-1];
        }
        else {
            index = loopSize - 1;
            if (pos[z].empty()) {
                cout << -1 << endl;
                continue;
            }
            else if (pos[z].size() == 1) {
                if (pos[z][0] == y) distance = 0;
                else if (pos[z][0] < y) distance = n + pos[z][0] - y;
                else distance = pos[z][0] - y;
                cout << distance << endl;
                continue;
            }
            else if (pos[z][0] > y || pos[z][loopSize - 1] < y) {
                if (pos[z][0] > y) distance = pos[z][0] - y;
                else distance = n - y + pos[z][0];
                cout << distance << endl;
                continue;
            }
            while (true) {
                //if (index >= loopSize) break;
                if ((pos[z][index] == y) || (pos[z][index] > y && pos[z][(index - 1 + loopSize) % loopSize] < y)) {
                    if (pos[z][index] == y) distance = 0;
                    //else if (pos[z][index] < y) distance = n + pos[z][index] - y;
                    else distance = pos[z][index] - y;
                    break;
                }
                --index;
            }
        }

        cout << distance << endl;
    }

    return 0;
}