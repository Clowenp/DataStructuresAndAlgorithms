/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107
*/

#include <iostream>
#include <vector>

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        else if (root->val == val) return root;
        else if (val < root->val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }
};

class Solution {

    vector<TreeNode*> findNode(TreeNode* node, TreeNode* prevNode, int key) {
        if (!node) return vector<TreeNode*> {nullptr, nullptr};
        else if (key == node->val) return vector<TreeNode* >{node, prevNode};
        else if (key < node->val) return findNode(node->left, node, key);
        else return findNode(node->right, node, key);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<TreeNode*> nodeAndParent = findNode(root, nullptr, key);
        if (!nodeAndParent[0]) return root;

        // node is found, we will delete
        if (!nodeAndParent[0]->left) {  // 1) search left find largest

        } else if (!nodeAndParent[0]->right) { // 2) search right find bigger

        } else { // 3) none exist then just delete the node
            if (!nodeAndParent[1]) { // parent is nullptr
                return nullptr;
            } else {

            }
        }
    }
};