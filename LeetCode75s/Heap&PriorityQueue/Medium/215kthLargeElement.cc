/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq (nums.begin(), nums.end());

        for (int i = 1; i < k; ++i) {
            pq.pop();
        }
        return pq.top();
    }
};

int main () {
    vector<int> nums1 {3,2,1,5,6,4};
    vector<int> nums2 {3,2,3,1,2,4,5,5,6};

    cout << Solution{}.findKthLargest(nums1, 2) << endl;
    cout << Solution{}.findKthLargest(nums2, 4) << endl;
}