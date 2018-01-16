//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstring>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

typedef long long ll;
typedef vector <vector <int>> vvi;

using namespace std;

int n;

class Node {
public:
    Node* parent;
    Node* leftC;
    Node* rightC;

    int value;
    int nodeSum; //In other words, the # of descendants it has

    Node(Node* _parent, Node* _leftC, Node* _rightC, int _value, int _nodeSum) {
        parent = _parent;
        leftC = _leftC;
        rightC = _rightC;
        value = _value;
        nodeSum = _nodeSum;
    }
};

void query() {

}

void add() {

}

void remove(Node* BST, int num) {

}

Node* construct(const int* a) {

    auto head = new Node(nullptr, nullptr, nullptr, a[0], 1);

    Node* currParent = head;
    fl (i, n) {
        while (true) {
            if (a[i] > currParent->value) {
                if (currParent->rightC == nullptr) {
                    int tempSum = currParent->nodeSum;
                    if (currParent->leftC != nullptr) tempSum -= currParent->leftC->nodeSum;
                    currParent->rightC = new Node(currParent, nullptr, nullptr, a[i], tempSum);
                    ++currParent->nodeSum;
                    break;
                }
                else {
                    currParent = currParent->rightC;
                }
            }
            else {
                if (currParent->leftC == nullptr) {
                    int tempSum = currParent->nodeSum;
                    if (currParent->rightC != nullptr) tempSum -= currParent->rightC->nodeSum;
                    currParent->leftC = new Node(currParent, nullptr, nullptr, a[i], tempSum);
                    ++currParent->nodeSum;
                    break;
                }
                else {
                    currParent = currParent->leftC;
                }
            }
        }
    }
    return head;
}

int main() {

    ifstream finz("zin.txt");

    int t;

    finz >> t;

    while (t--) {
        finz >> n;
        int a[n];
        fl (i, n) finz >> a[i];

        //Two trees are needed, one that starts out existing, and one that is created as we remove vertices
        Node* startBST = construct(a);
        auto finBST = new Node(nullptr, nullptr, nullptr, a[0], 1);

    }

    return 0;
}