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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur=head, *backn=head, *prev=head;
        
        for(int i=1;i<n; i++)
            cur=cur->next;
            
        while(cur->next){
            cur=cur->next;
            prev=backn;
            backn=backn->next;
        }
        if(backn==head) return head->next;
        
        prev->next=backn->next;
        return head;
    }
};
