/*
Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 

Example 1:
[Image]

Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
Example 2:
[Image]

Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 105
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * Strategy 1:
 *  - Generate columns O(n^2)
 *  - Comapre rows and columns O(n^3)
 * 
*/

class Solution1 {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> cols;
        for (size_t c = 0; c < grid.size(); ++c) {
            vector<int> column;
            for (size_t r = 0; r < grid.size(); ++r) {
                column.emplace_back(grid[r][c]);
            }
            cols.emplace_back(column);
        }
        int same = 0;
        for (size_t r = 0; r < grid.size(); ++r) {
            for (size_t c = 0; c < cols.size(); ++c) {
                if (grid[r] == cols[c]) ++same;
            }
        }

        return same;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> cols;
        for (size_t c = 0; c < grid.size(); ++c) {
            vector<int> column;
            for (size_t r = 0; r < grid.size(); ++r) {
                column.emplace_back(grid[r][c]);
            }
            cols.emplace_back(column);
        }
        int same = 0;
        for (size_t r = 0; r < grid.size(); ++r) {
            for (size_t c = 0; c < cols.size(); ++c) {
                if (grid[r] == cols[c]) ++same;
            }
        }

        return same;
    }
};

int main () {
    vector<vector<int>> grid1 {{3,2,1},{1,7,6},{2,7,7}};
    vector<vector<int>> grid2 {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};

    cout << Solution{}.equalPairs(grid1) << endl;
    cout << Solution{}.equalPairs(grid2) << endl;
}
