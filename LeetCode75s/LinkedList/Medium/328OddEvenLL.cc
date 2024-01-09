/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* even = head->next;
        
        ListNode* odd_cpy = head;
        ListNode* even_cpy = even;

        while (odd_cpy && even_cpy) {
            ListNode* next_odd = even_cpy->next;
            ListNode* next_even = nullptr;
            if (next_odd && next_odd->next) {
                next_even = next_odd->next;
            }

            if (!next_odd) { // reached last 2 elements
                odd_cpy->next = even;
                break;
            } else if (!next_even) { // reached last 3 elements
                odd_cpy->next = next_odd;
                even_cpy->next = nullptr;
                next_odd->next = even;
                break;
            } else {
                odd_cpy->next = next_odd;
                even_cpy->next = next_even;
                odd_cpy = next_odd;
                even_cpy = next_even;
            }
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
    ListNode l2 {1, new ListNode {2 , nullptr}};
    ListNode l3 {1, new ListNode {2 , new ListNode {3, nullptr}}};

    printLinkedList(Solution{}.oddEvenList(&l1));
    printLinkedList(Solution{}.oddEvenList(&l2));
    printLinkedList(Solution{}.oddEvenList(&l3));
}