/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/

#include <vector>
#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        for (int n : arr) {
            if (m.count(n)) ++m[n];
            else m[n] = 1;
        }
        unordered_set<int> set;
        for (auto& p : m) {
            if (set.count(p.second)) return false;
            else set.insert(p.second);
        }
        return true;
    }
};

int main () {
    vector<int> num1 {1,2,2,1,1,3};
    vector<int> num2 {1,2};
    vector<int> num3 {-3,0,1,-3,1,1,1,-3,10,0};
    cout << Solution{}.uniqueOccurrences(num1) << endl;
    cout << Solution{}.uniqueOccurrences(num2) << endl;
    cout << Solution{}.uniqueOccurrences(num3) << endl;
}