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
    ListNode * prev;
    // use recursion
    void add(ListNode* l1, ListNode* l2, int over){
        int sum;
        if(l1 == NULL && l2 == NULL){
            ListNode* node;
            if(over==1){ // if one more digit left
                node = new ListNode(1);
                prev->next = node;
            }
        }
        else if(l1 == NULL) { 
            sum = l2->val + over;
            over = sum/10; sum%=10;
            l2->val = sum;
            prev->next = l2;
            prev = l2;
            add(NULL, l2->next, over);
        }
        else if(l2 == NULL) {
            sum = l1->val + over;
            over = sum/10; sum%=10;
            l1->val = sum;
            prev = l1;
            add(l1->next, NULL, over);
        }
        else{
            sum = l1->val + l2->val + over;
            over = sum/10; sum%=10;
            l1->val = sum;
            prev = l1;
            add(l1->next, l2->next, over);
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node;
        prev = l1;
        add(l1, l2, 0);
        return l1;
    }
};
