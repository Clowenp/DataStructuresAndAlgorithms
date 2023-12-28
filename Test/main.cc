#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    vector<int> a {1,2,3};
    for (auto it = a.begin(); it != a.end();) {
        it = a.emplace(it, 4);
        it += 2;
    }

    for (auto n : a) {
        cout << n << endl;
    }
}