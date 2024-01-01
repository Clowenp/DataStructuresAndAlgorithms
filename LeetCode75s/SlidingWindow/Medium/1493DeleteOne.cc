/*
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max = 0; // size of the window
        size_t end = 0; // end of the window

        // find size of subarray containing first element
        int zeroLeft = 1;
        while (end < nums.size() && (zeroLeft > 0 || nums[end] == 1)) {
            if (nums[end] == 0) --zeroLeft;
            ++max;
            ++end;
        }
        while (end < nums.size()) {
            if (nums[end] - nums[end - max] > 0) {
                if (zeroLeft < 0) ++zeroLeft; 
                else ++max;
            } else if (nums[end] - nums[end-max] == 0) {
                if (nums[end] == 1 && zeroLeft >= 0) ++max;
            } else { // nums [end] < nums[end-max]
                if (zeroLeft > 0) ++max;
                --zeroLeft;
            }
            ++end;
        }
        return max - 1;
    }
};

int main() {
    // size 1
    vector<int> num1 {0,1,1,1,0,1,1,0,1};
    //vector<int> num2 {1};
    cout << Solution{}.longestSubarray(num1) << endl; // 0
    //cout << Solution{}.longestSubarray(num2) << endl; // 1

 /*
    // size 6
    vector<int> num3 {0, 0, 1, 1, 1, 0}; // 3
    vector<int> num4 {1, 1, 0, 0, 0, 1}; // 2
    cout << Solution{}.longestSubarray(num3) << endl;
    cout << Solution{}.longestSubarray(num4) << endl;


    // connection
    vector<int> num5 {0, 1, 0, 1, 0, 1, 1}; // 3
    cout << Solution{}.longestSubarray(num5) << endl;
*/
}