/*
Expected correct output for made-up cases

3
5
580
7
1
3
2
22
23
27
902
1001
1950
750
*/


//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#define ll long long
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

using namespace std;

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int findMin(int a, int b, int c) {
    return min(min(a, b), min(b, c));
}

void finishTwos(int xyz[], int b, int c, int towers[], int* total) {

    int startHeight = towers[0];

    bool canFill;
    if (xyz[2] - xyz[1] - xyz[0] + startHeight > 0) canFill = false;
    else canFill = true;

    bool isOdd;
    if ((xyz[0] + xyz[1] + xyz[2] - 3 * startHeight) & 1) isOdd = true;
    else isOdd = false;

    if (!canFill) {
        towers[0] = xyz[0];
        towers[1] = xyz[1];
        towers[2] = xyz[0] + xyz[1] - startHeight;

        if (xyz[2] == 20) {
            cout << "";
        }
        //*total += b * ((xyz[0] - startHeight + xyz[1] - startHeight + (xyz[0] + xyz[1] - startHeight * 2)) / 2);
        *total += b * (xyz[0] + xyz[1] - 2 * startHeight);
        return;
    }

    if (!isOdd) {
        towers[0] = xyz[0];
        towers[1] = xyz[1];
        towers[2] = xyz[2];
        *total += b * (xyz[0] + xyz[1] + xyz[2] - 3 * startHeight) / 2;
        return;
    }
    else {
        towers[0] = xyz[0];
        towers[1] = xyz[1];
        towers[2] = xyz[2] - 1;
        *total += b * (xyz[0] + xyz[1] + xyz[2] - 3 * startHeight - 1) / 2;
        return;
    }
}

void finishOnes(int xyz[], int a, int towers[], int* total) {
    if (towers[0] < xyz[0]) *total += a * (xyz[0] - towers[0]);
    if (towers[1] < xyz[1]) *total += a * (xyz[1] - towers[1]);
    if (towers[2] < xyz[2]) *total += a * (xyz[2] - towers[2]);
}

int main() {

    ifstream finz("zin.txt");

    int t, x, y, z, a, b, c;

    finz >> t;

    while (t--) {

        finz >> x >> y >> z >> a >> b >> c;

        if (x == 7) {
            cout << "";
        }

        int xyz[3];
        xyz[0] = x; xyz[1] = y; xyz[2] = z;
        //Sort in ascending order
        qsort(xyz, (size_t)3, sizeof(int), compare);

        double aRatio = 1 / (a * 1.0);
        double bRatio = 2 / (b * 1.0);

        //A letter is viable if it is cheaper than every other letter that consists of fewer blocks

        bool bViable;

        if (bRatio > aRatio) bViable = true;
        else bViable = false;

        int cMin = 2000000000;
        int cMinI = 0;

        int towers[3];
        //int towersC[3];
        int roof = findMin(x, y, z);

        vector <int> ii = {0};

        if (roof > 1) ii.push_back(1);
        ii.push_back(roof);
        ii.push_back(roof - 1);
        for (int i = 300; i < roof; i += 300) {
            ii.push_back(i);
        }

        for (int i = 0; i <= ii.size(); ++i) {
            memset(towers, 0, sizeof(int) * 3);
            int indTotal = ii[i] * c;
            towers[0] = ii[i]; towers[1] = ii[i]; towers[2] = ii[i];

            if (t == 0) {
                cout << "";
            }
            if (bViable) {
                finishTwos(xyz, b, c, towers, &indTotal);
            }

            finishOnes(xyz, a, towers, &indTotal);

            if (indTotal < cMin) {
                cMin = indTotal;
                cMinI = i;
            }
        }

        for (int i = max(2, cMinI - 300); i < cMinI; ++i) {
            memset(towers, 0, sizeof(int) * 3);
            int indTotal = ii[i] * c;
            towers[0] = ii[i]; towers[1] = ii[i]; towers[2] = ii[i];

            if (t == 0) {
                cout << "";
            }
            if (bViable) {
                finishTwos(xyz, b, c, towers, &indTotal);
            }

            finishOnes(xyz, a, towers, &indTotal);

            if (indTotal < cMin) cMin = indTotal;
        }

        for (int i = cMinI; i < max(cMinI + 300, roof - 1); ++i) {
            memset(towers, 0, sizeof(int) * 3);
            int indTotal = ii[i] * c;
            towers[0] = ii[i]; towers[1] = ii[i]; towers[2] = ii[i];

            if (t == 0) {
                cout << "";
            }
            if (bViable) {
                finishTwos(xyz, b, c, towers, &indTotal);
            }

            finishOnes(xyz, a, towers, &indTotal);

            if (indTotal < cMin) cMin = indTotal;
        }

        cout << cMin << endl;
    }

    return 0;
}