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
    ListNode* swapPairs(ListNode* head) {
        ListNode *one=head, *two;
        int temp;

        if(!one) return head;
        two=one->next;
        
        while(two){
            temp=one->val;
            one->val=two->val;
            two->val=temp;
            
            one=two->next;
            if(!one) break;
            two=one->next;
        }
        return head;
    }
};
