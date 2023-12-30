/*
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104

*/
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

/*
Solution 1
*/

class Solution1 {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = 0;
        double maxAvg = -1000.00000;
        while (n + k - 1 < static_cast<int>(nums.size())) {
            int sum = 0;
            for (int i = n; i < n + k; ++i) {
                sum += nums[i];
            }
            double avg = static_cast<double>(sum) / static_cast<double>(k);
            if (avg > maxAvg) maxAvg = avg;
            ++n;
        }
        return maxAvg;
    }
};

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // set variables
        int n = static_cast<int>(nums.size());
        int lastWindow = 0; // holds sum of elements in the last window besides first element

        // special window case for start position
        for (int i = 0; i < k; ++i) {
            lastWindow += nums[i];
        }
        int maxTotal = lastWindow;

        for (int i = k; i < n; ++i) {
            lastWindow = lastWindow + nums[i] - nums[i - k];
            if (lastWindow > maxTotal) maxTotal = lastWindow;
        }
        return (static_cast<double>(maxTotal) / static_cast<double>(k));
    }
};

int main () {
    vector<int> num1 {1,12,-5,-6,50,3};
    vector<int> num2 {5};
    cout << Solution{}.findMaxAverage(num1, 4) << endl;
    cout << Solution{}.findMaxAverage(num2, 1) << endl;
}