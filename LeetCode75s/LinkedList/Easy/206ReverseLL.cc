/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <stack>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ~ListNode() {
        delete next;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp = head;
        stack<int> s;
        
        while (tmp != nullptr) {
            s.push(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp != nullptr) {
            tmp->val = s.top();
            s.pop();
            tmp = tmp->next;
        }
        return head;
    }
};


void printLinkedList(ListNode* l) {
    while (l != nullptr) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

int main () {
    ListNode l1 {1, nullptr};
    ListNode l2 {1, new ListNode {2 , new ListNode {3, nullptr}}};

    printLinkedList(Solution{}.reverseList(&l1));
    printLinkedList(Solution{}.reverseList(&l2));

}