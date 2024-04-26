#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // ascii 'a' = 96 & 26 letters in the alphabet

        vector<int> charCount (26);

        for (char c : s) {
            ++charCount[c - 'a'];
        }

        for (char c : t) {
            --charCount[c - 'a'];
        }

        for (int n : charCount) {
            if (n != 0) {
                return false;
            }
        }

        return true;
    }
};