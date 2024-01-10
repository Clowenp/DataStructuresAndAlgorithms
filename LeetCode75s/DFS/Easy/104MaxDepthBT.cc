/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/

#include <iostream>

using namespace std;

//Definition for a binary tree node.
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

// recursive

class Solution {
    int maxDepth(TreeNode* root, int curr_depth) {
        if (!root) return curr_depth;
        else return max<int>(maxDepth(root->left, curr_depth + 1), maxDepth(root->right, curr_depth + 1));
    }
public:
    int maxDepth(TreeNode* root) {
        return maxDepth(root, 0);
    }
};

int main () {
    TreeNode tree1 {1, new TreeNode {2, nullptr, nullptr}, new TreeNode {3, nullptr, nullptr}};
    TreeNode tree2 {1, new TreeNode {2, nullptr, new TreeNode {3, nullptr, nullptr}}, nullptr};
    TreeNode tree3 {1, nullptr, nullptr};

    cout << Solution{}.maxDepth(&tree1) << endl;
    cout << Solution{}.maxDepth(&tree2) << endl;
    cout << Solution{}.maxDepth(&tree3) << endl;
    cout << Solution{}.maxDepth(nullptr) << endl;

}