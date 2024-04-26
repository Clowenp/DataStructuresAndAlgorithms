#include <vector>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::unordered_map;
using std::iostream;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;

        // iterate through twice

        // 1) map all the elements
        for (size_t i = 0; i < nums.size(); ++i) {
            numToIndex[nums[i]] = i;
        }

        // 2) see if there exists an element where target - num[i] = element
        for (size_t i = 0; i < nums.size(); ++i) {
            if (numToIndex.contains(target - nums[i]) && i != numToIndex[target - nums[i]]) {
                return vector<int> {static_cast<int>(i), numToIndex[target-nums[i]]};
            }
        }
        return vector<int>{};
    }
};