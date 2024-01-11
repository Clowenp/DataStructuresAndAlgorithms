/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

 

Example 1:



Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
Example 2:



Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
Example 3:

Input: root = [1]
Output: 1
Explanation: Root is considered as good.
 

Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].
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


class Solution {

    int goodNodes(TreeNode* node, int highest_val) {
        if (!node) return 0;

        if (node->val >= highest_val) {
            highest_val = node->val;
            return 1 + goodNodes(node->left, highest_val) + goodNodes(node->right, highest_val);
        } else {
            return 0 + goodNodes(node->left, highest_val) + goodNodes(node->right, highest_val);
        }
    }

public:
    int goodNodes(TreeNode* root) {
        return goodNodes(root, -10000);
    }
};

int main () {
    TreeNode tree1 {1, new TreeNode {2, nullptr, nullptr}, new TreeNode {3, nullptr, nullptr}};
    TreeNode tree2 {1, new TreeNode {2, nullptr, new TreeNode {3, nullptr, nullptr}}, nullptr};
    TreeNode tree3 {1, new TreeNode {3, nullptr, new TreeNode {2, nullptr, nullptr}}, nullptr};
    TreeNode tree4 {1, nullptr, nullptr};
    TreeNode tree5 {1, nullptr, new TreeNode {0, nullptr, nullptr}};

    cout << Solution{}.goodNodes(&tree1) << endl; // 3
    cout << Solution{}.goodNodes(&tree2) << endl; // 3
    cout << Solution{}.goodNodes(&tree3) << endl; // 2
    cout << Solution{}.goodNodes(&tree4) << endl; // 1
    cout << Solution{}.goodNodes(&tree5) << endl; // 1


}