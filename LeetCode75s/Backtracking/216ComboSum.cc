/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 

Constraints:

2 <= k <= 9
1 <= n <= 60
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {

    vector<vector<int>> combos;
    vector<int> path;

    vector<bool> numLeft {true, true, true, true, true, true, true, true, true} ;

    bool hasSum(int k, int n) {
        if (n == 0) return true;
        if (n < 0 || k == 0) return false;

        if ()

        if (path.empty()) {
            if (hasSum(k - 1, n-=1))
        }

    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n > 45) return combos;
        
        for (int i = 1; i <= 9; ++i) {
            numLeft[i] = false;
            path.emplace_back(i);
            if (hasSum(k - 1, n - i)) {
                
            }        
        }
        return combos;
    }
};

int main () {

}