/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool increasingTriplet(vector<int>& nums) {
        vector<vector<int>> triplet;

        for (size_t i = 0; i < nums.size(); ++i) {
            bool placed = false;
            for (size_t j = 0; j < triplet.size(); ++j) {
                if (triplet[j].size() == 1) {
                    placed = true;
                    if (nums[i] <= triplet[j][0]) {
                        triplet[j][0] = nums[i];
                    } else {
                        triplet[j].emplace_back(nums[i]);
                    }
                } else if (triplet[j].size() == 2) {
                    if (nums[i] > triplet[j][triplet[j].size() - 1]) {
                        return true;
                    } else if (nums[i] > triplet[j][0] && nums[i] <=  triplet[j][triplet[j].size() - 1]) {
                        placed = true;
                        triplet[j][triplet[j].size() - 1] = nums[i];
                    } else if (nums[i] == triplet[j][0] && j == triplet.size() - 1) {
                        placed = true;
                        break;
                    }
                } else {
                    cerr << "Error" << endl;
                }

            }
            if (!placed) triplet.emplace_back(vector<int> {nums[i]});
        }

        return false;
    }
};

int main () {
    // vector<int> num1 {1,2,3,4,5};
    // vector<int> num2 {5,4,3,2,1};
    // vector<int> num3 {2,1,5,0,4,6};
    // cout << Solution{}.increasingTriplet(num1) << endl;
    // cout << Solution{}.increasingTriplet(num2) << endl;
    // cout << Solution{}.increasingTriplet(num3) << endl;
    vector<int> num { };
    cout << Solution{}.increasingTriplet(num) << endl;



}