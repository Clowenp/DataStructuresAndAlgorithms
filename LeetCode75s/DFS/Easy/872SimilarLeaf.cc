/*
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Example 1:


Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
Example 2:


Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
 

Constraints:

The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200].
*/

#include <iostream>
#include <vector>

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

    void leafsSimilar(TreeNode* root, vector<int>& leafs) {
        if (!root->left && !root->right) leafs.emplace_back(root->val);
        if (root->left) leafsSimilar(root->left, leafs);
        if (root->right) leafsSimilar(root->right, leafs);
    }

    void printVector(vector<int>& v) {
        for (int n : v) {
            cout << n << " ";
        }
        cout << endl;
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) {
            if (root1 == root2) return true;
            else return false;
        }

        vector<int> leaf1;
        leafsSimilar(root1, leaf1);
        vector<int> leaf2;
        leafsSimilar(root2, leaf2);

        if (leaf1 == leaf2) return true;
        else return false;
    }
};

int main () {
    TreeNode tree1 {1, new TreeNode {2, nullptr, nullptr}, new TreeNode {3, nullptr, nullptr}};
    TreeNode tree2 {1, new TreeNode {2, nullptr, new TreeNode {3, nullptr, nullptr}}, nullptr};
    TreeNode tree3 {1, nullptr, nullptr};
    TreeNode tree4 {0, nullptr, new TreeNode {1, nullptr, nullptr}};

    cout << "Solution" << endl;
    cout << Solution{}.leafSimilar(&tree1, &tree2) << endl;
    cout << "Solution" << endl;
    cout << Solution{}.leafSimilar(&tree3, &tree4) << endl;
}