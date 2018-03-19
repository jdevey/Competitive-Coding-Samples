#pragma GCC optimize("03")
 
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <ctime>
 
#define ll long long
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
#define CPS CLOCKS_PER_SEC
 
using namespace std;
 
clock_t start = clock();
 
int n, m;
vector <vector <int>> aPos;
 
struct Quad {
    int aPosX;
    int aPosY;
    int bPosX;
    int bPosY;
    int cPosX;
    int cPosY;
    int dPosX;
    int dPosY;
 
    Quad(int _aPosX, int _aPosY, int _bPosX, int _bPosY, int _cPosX, int _cPosY, int _dPosX, int _dPosY);
};
 
Quad::Quad(int _aPosX, int _aPosY, int _bPosX, int _bPosY, int _cPosX, int _cPosY, int _dPosX, int _dPosY) {
    aPosX = _aPosX;
    aPosY = _aPosY;
    bPosX = _bPosX;
    bPosY = _bPosY;
    cPosX = _cPosX;
    cPosY = _cPosY;
    dPosX = _dPosX;
    dPosY = _dPosY;
}
 
vector <Quad*> quadList;
 
void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
 
void randomShuffle(int a[], int size) {
    fl (i, size) {
        int rNum = rand() % size;
        swap(&a[i], &a[rNum]);
    }
}
 
void quadRecurse(int xInd, int yInd, char** grid, int curBX, int curBY, int curCX, int curCY, int curDX, int curDY, char curLet) {
 
    if (xInd == 3 && yInd == 0) {
        cout << "";
    }
 
    if (curLet == 'a') {
        if (yInd - 1 >= 0 && grid[yInd - 1][xInd] == 'b') quadRecurse(xInd, yInd, grid, xInd, yInd - 1, 0, 0, 0, 0, 'b');
        if (xInd + 1 < m && grid[yInd][xInd + 1] == 'b') quadRecurse(xInd, yInd, grid, xInd + 1, yInd, 0, 0, 0, 0, 'b');
        if (yInd  + 1 < n && grid[yInd + 1][xInd] == 'b') quadRecurse(xInd, yInd, grid, xInd, yInd + 1, 0, 0, 0, 0, 'b');
        if (xInd - 1 >= 0 && grid[yInd][xInd - 1] == 'b') quadRecurse(xInd, yInd, grid, xInd - 1, yInd, 0, 0, 0, 0, 'b');
    }
    else if (curLet == 'b') {
        if (curBY - 1 >= 0 && grid[curBY - 1][curBX] == 'c') quadRecurse(xInd, yInd, grid, curBX, curBY, curBX, curBY - 1, 0, 0, 'c');
        if (curBX + 1 < m && grid[curBY][curBX + 1] == 'c') quadRecurse(xInd, yInd, grid, curBX, curBY, curBX + 1, curBY, 0, 0, 'c');
        if (curBY  + 1 < n && grid[curBY + 1][curBX] == 'c') quadRecurse(xInd, yInd, grid, curBX, curBY, curBX, curBY + 1, 0, 0, 'c');
        if (curBX - 1 >= 0 && grid[curBY][curBX - 1] == 'c') quadRecurse(xInd, yInd, grid, curBX, curBY, curBX - 1, curBY, 0, 0, 'c');
    }
    else if (curLet == 'c') {
        if (curCY - 1 >= 0 && grid[curCY - 1][curCX] == 'd') quadRecurse(xInd, yInd, grid, curBX, curBY, curCX, curCY, curCX, curCY - 1, 'd');
        if (curCX + 1 < m && grid[curCY][curCX + 1] == 'd') quadRecurse(xInd, yInd, grid, curBX, curBY, curCX, curCY, curCX + 1, curCY, 'd');
        if (curCY  + 1 < n && grid[curCY + 1][curCX] == 'd') quadRecurse(xInd, yInd, grid, curBX, curBY, curCX, curCY, curCX, curCY + 1, 'd');
        if (curCX - 1 >= 0 && grid[curCY][curCX - 1] == 'd') quadRecurse(xInd, yInd, grid, curBX, curBY, curCX, curCY, curCX - 1, curCY, 'd');
    }
    else {
        auto qObj = new Quad(xInd, yInd, curBX, curBY, curCX, curCY, curDX, curDY);
        quadList.emplace_back(qObj);
    }
}
 
int main() {
    
    srand(time(NULL));
 
    //ifstream cin("zin2.txt");
 
    cin >> n >> m;
 
    auto a = new char *[n];
    fl (i, n) a[i] = new char[m];
 
    //Reading in and building the a-position vector
    fl (i, n)
        fl (j, m) {
            cin >> a[i][j];
            if (a[i][j] == 'a') {
                aPos.emplace_back(vector <int> (2, 0));
                aPos[aPos.size() - 1][0] = j;
                aPos[aPos.size() - 1][1] = i;
            }
        }
 
    //Navigating the grid to make quads
    fl (i, aPos.size()) {
        quadRecurse(aPos[i][0], aPos[i][1], a, 0, 0, 0, 0, 0, 0, 'a');
    }
 
    //Selecting options over and over until time runs out
    ll grandMax = 0;
 
    int quadSize = quadList.size();
    int mix[quadSize];
    fl (i, quadSize) mix[i] = i;
    while ((clock() - start) / (CPS * 1.0) < 0.95) {
        fl (i, 5) randomShuffle(mix, quadSize);
        bool takeSpace[n][m];
        memset(takeSpace, 0, sizeof(bool) * n * m);
        ll domainCount = 0;
        fl (i, quadSize) {
            if (takeSpace[quadList[mix[i]]->aPosY][quadList[mix[i]]->aPosX] == 0) {
                if (takeSpace[quadList[mix[i]]->bPosY][quadList[mix[i]]->bPosX] == 0) {
                    if (takeSpace[quadList[mix[i]]->cPosY][quadList[mix[i]]->cPosX] == 0) {
                        if (takeSpace[quadList[mix[i]]->dPosY][quadList[mix[i]]->dPosX] == 0) {
                            ++domainCount;
                            takeSpace[quadList[mix[i]]->aPosY][quadList[mix[i]]->aPosX] = true;
                            takeSpace[quadList[mix[i]]->bPosY][quadList[mix[i]]->bPosX] = true;
                            takeSpace[quadList[mix[i]]->cPosY][quadList[mix[i]]->cPosX] = true;
                            takeSpace[quadList[mix[i]]->dPosY][quadList[mix[i]]->dPosX] = true;
                        }
                    }
                }
            }
        }
        if (domainCount > grandMax) grandMax = domainCount;
    }
 
    cout << grandMax;
 
    return 0;
}
