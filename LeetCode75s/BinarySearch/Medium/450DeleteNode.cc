/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
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

class Solution { // with proper memory management
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr; // not found
        if (root->val == key) {
            // case 1, no children
            if (!root->left && !root->right) {
                // possibly delete node of heap allocated
                delete root;
                return nullptr;
            } else if (root->left && !root->right) { // left child only
                TreeNode* tmpLeft = root->left;
                root->left = nullptr;
                delete root;
                return tmpLeft;
            } else if (root->right && !root->left) { // right child only
                TreeNode* tmpRight = root->right;
                root->right = nullptr;
                delete root;
                return tmpRight;
            } else { // 2 children;
                TreeNode* nextSmaller = root->left;
                while (nextSmaller->right) {
                    nextSmaller = nextSmaller->right;
                }
                root->val = nextSmaller->val;
                root->left = deleteNode(root->left, nextSmaller->val);
            }
        } else if (key < root->val) {
            root->left = deleteNode(root->left,key);
        } else {
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};

void displayTree(TreeNode* t) {
    queue<TreeNode*> q;
    q.push(t);

    // bfs
    while(!q.empty()) {
        int originalSize = q.size();
        for (int i = 0; i < originalSize; ++i) {
            cout << q.front()->val << " ";
            if (q.front()->left) q.push(q.front()->left);
            if (q.front()->right) q.push(q.front()->right);
            q.pop();
        }
        cout << endl;
    }
}

int main () {
    // TreeNode t1 {2, new TreeNode {1, nullptr, nullptr}, nullptr};
    // TreeNode t2 {2, 
    //     new TreeNode {1, 
    //         nullptr, 
    //         nullptr}, 
    //     new TreeNode {3, 
    //         nullptr, 
    //         nullptr}};
    TreeNode* t3 = new TreeNode {2, 
        new TreeNode {1, 
            nullptr, 
            nullptr},
        new TreeNode {4, 
            new TreeNode {3, nullptr, nullptr}, 
            new TreeNode {5, nullptr, nullptr}}};

    // displayTree(Solution{}.deleteNode(&t1 ,1));
    // displayTree(Solution{}.deleteNode(&t2 ,3));
    displayTree(Solution{}.deleteNode(t3 ,2));
    delete t3;
}