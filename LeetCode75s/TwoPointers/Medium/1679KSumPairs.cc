/*
You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

 

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= 10^9
*/

#include <iostream>
#include <vector>

using namespace std;

/*
Solution 1: Brute Force
*/

class Solution1 {
    bool removePair(vector<int>&nums, int k) {
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == k) {
                    auto itJ = nums.begin() + j;
                    nums.erase(itJ);
                    auto itI = nums.begin() + i;
                    nums.erase(itI);
                    return true;
                }
            }
        }
        return false;
    }
public:

    int maxOperations(vector<int>& nums, int k) {
        int counter = 0;
        while (removePair(nums, k)) ++counter;
        return counter; 
    }
};

void printVec(vector<int> num) {
    for (auto n: num) {
        cout << n << " ";
    }
    cout << endl;
}

/*
Solution2
*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) { 
    }
};

int main () {
    vector<int> num1 {1,2,3,4};
    vector<int> num2 {3,1,3,4,3};
    cout << Solution{}.maxOperations(num1, 5) << endl;
    printVec(num1);
    cout << Solution{}.maxOperations(num2, 6) << endl;
    printVec(num2);

}