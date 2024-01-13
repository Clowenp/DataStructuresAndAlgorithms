/*
You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

 

Example 1:


Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
Example 2:


Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
Example 3:

Input: root = [1]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 5 * 104].
1 <= Node.val <= 100
*/
#include <iostream>

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
    int longestZigZag(TreeNode* node, bool nextLeft) {
        if (!node) return 0;
        if (nextLeft) return 1 + longestZigZag(node->left, !nextLeft);
        else return 1 + longestZigZag(node->right, !nextLeft);
    }
    int myMax(int a, int b, int c, int d) {
        int ab = max(a,b);
        int abc = max(ab,c);
        int abcd = max(abc,d);
        return abcd;
    }
public:
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        return myMax(longestZigZag(root->left), longestZigZag(root->right) ,longestZigZag(root->left, false), longestZigZag(root->right, true));
    }   
};

int main () {
    TreeNode tree1 {1, new TreeNode {2, nullptr, nullptr}, new TreeNode {3, nullptr, nullptr}};
    TreeNode tree2 {1, new TreeNode {2, nullptr, new TreeNode {3, nullptr, nullptr}}, nullptr};
    TreeNode tree3 {1, nullptr, nullptr};
    TreeNode tree4 {0, nullptr, new TreeNode {1, nullptr, nullptr}};

    cout << Solution{}.longestZigZag(&tree1) << endl;
    cout << Solution{}.longestZigZag(&tree2) << endl;
    cout << Solution{}.longestZigZag(&tree3) << endl;
    cout << Solution{}.longestZigZag(&tree4) << endl;
}