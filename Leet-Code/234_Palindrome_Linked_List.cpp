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
    bool isPalindrome(ListNode* head) {
        ListNode *head2, *p, *prev, *p2, *temp;
        int size, cnt = 0;

        p = head; cnt = 1;
        while(p->next!=NULL){ // count the size
            p = p->next;
            cnt ++;
        }
        if(cnt<=1) return true;
        size = (cnt+1)/2+1; // location of the second head

        p = head; cnt = 1;
        while(cnt<size){
            prev = p;
            p = p->next;
            cnt++;
        }
        prev->next = NULL; // cut in half

        temp = p->next; // reverse the second half
        p->next = NULL;
        prev = p;
        p = temp;
        while(p!=NULL){
            temp = p->next;
            p->next = prev;	
            prev = p;
            p = temp;	
        }
        head2 = prev; // found the second head

        p = head; p2 = head2;
        while(p!=NULL && p2!=NULL){
            if(p->val!=p2->val) return false;
            p = p->next; p2 = p2->next;
        }
        return true;
    }
};
