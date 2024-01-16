/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 

Example 1:


Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105

*/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    ~TreeNode() {
        delete left;
        delete right;
    }
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);


        int maxLevel = 1;
        int maxSum = -100000;

        int level = 1;
        while (!q.empty()) {
            
            int originalSize = q.size();
            int sum = 0;

            for (int i = 0; i < originalSize; ++i) {
                sum += q.front()->val;
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }

            if (sum > maxSum) {
                maxSum = sum;
                maxLevel = level;
            }
            ++level;
        }

        return maxLevel;
    }
};
int main() {
    TreeNode t1 {-5, nullptr, nullptr};
    TreeNode t2 {-5, 
        new TreeNode {-5, 
            nullptr, 
            nullptr}, 
        new TreeNode {5, 
            nullptr, 
            nullptr}};

    cout << Solution{}.maxLevelSum(&t1) << endl; // 1
    cout << Solution{}.maxLevelSum(&t2) << endl; // 2


}