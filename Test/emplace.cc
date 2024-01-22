#include <vector>
#include <iostream>

using namespace std;

void printVector(vector<int>& v) {
    for (int n : v) {
        cout << n << " ";
    }
    cout << endl;
}

struct pos {
    int x;
    int y;
};

void printPosVector(vector<pos>& v) {
    for (pos p : v) {
        cout << "(" << p.x << "," << p.y << ") ";
    }
    cout << endl;
}

int main () {
// pos
    vector<pos> vpos {pos {1,2}, pos {3,4}};
    vector<vector<pos>> vvpos;

    vvpos.push_back(vpos);
    // vvpos.emplace_back(vpos);
    printPosVector(vpos);


// int 
    vector<int> v1 {1,2,3};
    vector<vector<int>> vv1;

    vv1.emplace_back(v1);

    printVector(v1);
}