/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000
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


// WAY TOO SLOW
class SlowSolution {

    int pathStartingAtNode (TreeNode* node, int sum, int targetSum) {
        if (!node) return 0;
        if (node->val + sum == targetSum) {
            cout << "node val: " << node->val << endl;
            return 1 + pathStartingAtNode(node->left, node->val+sum, targetSum) 
            + pathStartingAtNode(node->right, node->val+sum, targetSum);
        } else {
            return pathStartingAtNode(node->left, node->val+sum, targetSum) 
            + pathStartingAtNode(node->right, node->val+sum, targetSum);
        }
    }   

public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        return pathStartingAtNode(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};

// Somehow working??? Same solution except answer is stored
class SolutionProper {
    int ans = 0;

    void pathStartingAtNode (TreeNode* node, double sum, int targetSum) {
        if (!node) return;
        if (node->val + sum == targetSum) {
            ++ans;
        } 
        pathStartingAtNode(node->left, node->val+sum, targetSum); 
        pathStartingAtNode(node->right, node->val+sum, targetSum);
    }   

public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        pathStartingAtNode(root, 0, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return ans;
    }
};

// ==================================== RELATED ========================================

// faster solution than 1st version
class SolutionWorkingSlow {
    int pathSum(TreeNode* node, int targetSum, vector<int> path) {
        if (!node) return 0;
        path.emplace_back(node->val);
        int validPaths = 0;
        double sum = 0;
        for (int i = path.size() - 1; i >= 0; --i) {
            sum += path[i];
            if (sum == targetSum) {
                ++validPaths;
            }
        }
        return validPaths + pathSum(node->left, targetSum, path) + pathSum(node->right, targetSum, path);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        return pathSum(root, targetSum, vector<int>{});
    }
};

// Possible faster? NOOO, how.
class SolutionNotFaster {
    int ans = 0;
    void pathSum(TreeNode* node, int targetSum, vector<int> path) {
        if (!node) return ;
        path.emplace_back(node->val);
        int validPaths = 0;
        double sum = 0;
        for (int i = path.size() - 1; i >= 0; --i) {
            sum += path[i];
            if (sum == targetSum) {
                ++validPaths;
            }
        }
        ans += validPaths;
        pathSum(node->left, targetSum, path);
        pathSum(node->right, targetSum, path);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        pathSum(root, targetSum, vector<int>{});
        return ans;
    }
};

class Solution {
    int ans = 0;
    vector<int> path;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        path.emplace_back(root->val);
        int validPaths = 0;
        double sum = 0;
        for (int i = path.size() - 1; i >= 0; --i) {
            sum += path[i];
            if (sum == targetSum) {
                ++validPaths;
            }
        }
        ans += validPaths;
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        path.erase(path.begin() + path.size() - 1);
        return ans;
    }
};

// ==================================== END RELATED ========================================

int main () {
    TreeNode tree1 {1, new TreeNode {2, nullptr, nullptr}, new TreeNode {3, nullptr, nullptr}};
    TreeNode tree2 {1, new TreeNode {2, nullptr, new TreeNode {3, nullptr, nullptr}}, nullptr};
    TreeNode tree3 {1, nullptr, nullptr};
    TreeNode tree4 {0, nullptr, new TreeNode {1, nullptr, nullptr}};

    cout << Solution{}.pathSum(&tree1, 3) << endl;
    cout << Solution{}.pathSum(&tree2, 2) << endl;
    cout << Solution{}.pathSum(&tree4, 1) << endl;

}