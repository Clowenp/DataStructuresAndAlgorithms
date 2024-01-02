/*
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {

public:
    void removeDuplicates(vector<int>& nums1) {
        // remove duplicates in nums1
        for (size_t i = 0; i < nums1.size(); ++i) {
            for (size_t j = i + 1; j < nums1.size(); ++j) {
                if (nums1[i] == nums1[j]) {
                    nums1.erase(nums1.begin() + j);
                    --j;
                }
            }
        }
    }
    void removeCommon(vector<int>& nums1, vector<int>& nums2) {
        for (auto i = nums1.begin(); i != nums1.end();) {
            bool common = false;
            for (auto j = nums2.begin(); j != nums2.end();) {
                if (*j == *i) {
                    nums2.erase(j);
                    common = true;
                } else {
                    ++j;
                }
            }
            if (common) nums1.erase(i);
            else ++i;
        }
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // remove duplicates in nums1
        removeDuplicates(nums1);
        removeDuplicates(nums2);
        // remove commons
        removeCommon(nums1, nums2);        

        vector<vector<int>> answer;
        answer.emplace_back(nums1);
        answer.emplace_back(nums2);
        return answer;
    }
};

int main () {
    vector<int> nums1 {1,1,2,3,4,4,4};
    vector<int> nums2 {1,1,1,1,3,3,3,6,6,6};
    Solution{}.findDifference(nums1, nums2);
    for (int n : nums1) {
        cout << n << " ";
    }
    cout << endl;
    for (int n : nums2) {
        cout << n << " ";
    }
    cout << endl;
}