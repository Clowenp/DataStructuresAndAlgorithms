/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
    int longestOnes(vector<int>& nums, int k) {
        int max = 0; //length of window
        size_t end = 0;
        int tmpK = k;
        while (end < nums.size() && (nums[end] == 1 || tmpK > 0)) {
            if (nums[end] == 0) --tmpK;
            ++end;
            ++max;
        }
        int kLeft = 0;
        while (end < nums.size()) {
            if (nums[end - max] - nums[end] < 0) {
                if (kLeft >= 0) ++max;
                else ++kLeft;
            } else if (nums[end - max] - nums[end] == 0) {
                if (kLeft >= 0 && nums[end] == 1) ++max;
            } else if (kLeft > 0) {
                ++max;
                --kLeft;
            } else { 
                --kLeft;
            }
            ++end;
        }
        return max;
    }
};

int main() {
    vector<int> num1 {1,1,1,0,0,0,1,1,1,1,0};
    vector<int> num2 {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    vector<int> num3 {1,1,0,1,1,1,0,1,0};
    cout << Solution{}.longestOnes(num1,2) << endl;
    cout << Solution{}.longestOnes(num2,3) << endl;
    cout << Solution{}.longestOnes(num3,0) << endl;

}