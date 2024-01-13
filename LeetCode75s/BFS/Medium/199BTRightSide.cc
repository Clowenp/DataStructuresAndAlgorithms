/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/


#include <iostream>
#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<int> highestVals;

        if (!root) return highestVals;

        nodes.push(root);

        while (!nodes.empty()) {
            int originalNodeSize = nodes.size(); // number of nodes at current height
            for (int i = 0; i < originalNodeSize; ++i) {
                if (nodes.front()->left) nodes.push(nodes.front()->left);
                if (nodes.front()->right) nodes.push(nodes.front()->right);
                if (i == originalNodeSize - 1) {
                    highestVals.emplace_back(nodes.front()->val);
                }
                nodes.pop();
            }
        }
        return highestVals;
    }
};

void printVector(vector<int> vec) {
    cout << "[";
    for (int n : vec) {
        cout << n << " ";
    }
    cout << "]" << endl;
}

int main () {
    TreeNode t1 {1 , 
        new TreeNode {2, 
            nullptr, 
            new TreeNode {5, nullptr, nullptr}}, 
        new TreeNode{3, 
            nullptr, 
            new TreeNode {4, nullptr, nullptr}}};

    TreeNode t2 {1 , 
        nullptr, 
        new TreeNode{3, 
            nullptr, 
            nullptr}};
    
    printVector(Solution{}.rightSideView(&t1)); // [1 3 4 ]
    printVector(Solution{}.rightSideView(&t2)); // [1 3 ]
    printVector(Solution{}.rightSideView(nullptr)); // []

}