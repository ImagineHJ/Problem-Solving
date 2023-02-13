/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next->next!=NULL){
            node->val = node->next->val; // copy the data
            node = node->next;
        }
        // last node to servive
        node->val = node->next->val;
        node->next = NULL; // deleting the last node 1->2->4->5
    }
};
