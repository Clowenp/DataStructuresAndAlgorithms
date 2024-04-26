#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> numberSet;
        for (int& n : nums) {
            if (numberSet.count(n) > 0) {
                return true;
            } else {
                ++numberSet[n];
            }
        }
        return false;
    }
};