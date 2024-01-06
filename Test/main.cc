#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    string s = "helloasd";
    istringstream iss {s};

    int n = 0;
    bool found = true;
    while (!(iss >> n) && !iss.eof()) {
        iss.clear();
        iss.ignore();
        if (iss.eof()) found = false;
    }
    if (found) cout << n << endl;
    else cout << "nothing" << endl;
}