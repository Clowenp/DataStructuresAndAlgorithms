/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:

[Graph of Example 1]

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/

#include <vector>
#include <iostream>

using namespace std;


/*
Solution 1: Brute Force
*/

class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        for (size_t index1 = 0; index1 < height.size(); ++index1) {
            for (size_t index2 = index1 + 1; index2 < height.size(); ++index2) {
                int area = (index2 - index1) * min<int>(height[index1], height[index2]);
                if (area > maxArea) maxArea = area;
            }
        }
        return maxArea;
    }
};

/*
Solution: O(n)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int index1 = 0;
        int index2 = height.size() - 1;
        int lastMinHeight = min<int>(height[index1], height[index2]);
        int maxArea = lastMinHeight * (index2 - index1);;
        while (index1 < index2) {
            if (height[index1] <= lastMinHeight) ++index1;
            else if (height[index2] <= lastMinHeight) --index2;
            else {
                lastMinHeight = min<int>(height[index1], height[index2]);
                int area = lastMinHeight * (index2 - index1);
                if (area > maxArea) maxArea = area;
            }
        }
        return maxArea;
    }
};

int main () {
    vector<int> height1 {1,8,6,2,5,4,8,3,7};
    vector<int> height2 {1,1};
    cout << Solution{}.maxArea(height1) << endl;
    cout << Solution{}.maxArea(height2) << endl;
}