/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
*/

#include <iostream>
#include <stack>

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
    bool findPath(TreeNode* node, TreeNode* p, stack<TreeNode*>& path) {
        if (!node) return false;
        if (node == p) {
            path.push(p);
            return true;
        }
        if (findPath(node->left, p, path) || findPath(node->right, p, path)) {
            path.push(node);
            return true;
        } else { 
            return false;
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pPath;
        stack<TreeNode*> qPath;
        findPath(root, p, pPath);
        findPath(root, q, qPath);

        TreeNode* lastCommon = nullptr;
        while (!pPath.empty() && !qPath.empty()) {
            if (pPath.top() == qPath.top()) {
                lastCommon = pPath.top();
                pPath.pop();
                qPath.pop();
            }
            else {
                break;
            }
        }
        return lastCommon;
    }
};

int main () {
    TreeNode* p2 = new TreeNode{4, nullptr, nullptr};
    TreeNode* p1 = new TreeNode {5, 
            new TreeNode {6, nullptr, nullptr}, 
            new TreeNode {2, 
                new TreeNode {7, nullptr, nullptr}, 
                p2}};
    TreeNode tree1 {3, 
        p1 , 
        new TreeNode {1, 
            new TreeNode {0, nullptr, nullptr}, 
            new TreeNode {8, nullptr, nullptr}}};
    
    cout << Solution{}.lowestCommonAncestor(&tree1, p1, p2) << endl;
}

/*
Extremely elegant solution
*/

class ProperSolution {
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(!left && !right) return nullptr; 
        if(left && right) return root;  
        return left ? left : right;
    }
};