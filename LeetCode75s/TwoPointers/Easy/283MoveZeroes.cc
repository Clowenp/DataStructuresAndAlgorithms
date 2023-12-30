/*
 Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1 
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t ptr1 = 0;
        size_t ptr2 = 0;

        while (ptr2 < nums.size() && ptr1 < nums.size()) {
            if (nums[ptr1] != 0) ++ptr1;
            else if (ptr2 <= ptr1 || nums[ptr2] == 0) ++ptr2;
            else swap(nums[ptr1], nums[ptr2]);
        }
    }
};

int main () {
    vector<int> num {0, 1, 2, 3, 0};
    Solution{}.moveZeroes(num);
    for (int n : num) {
        cout << n << " ";
    }
    cout << endl;
}