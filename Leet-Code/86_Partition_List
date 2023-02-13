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
    ListNode* partition(ListNode* head, int x) {
        ListNode * tail, * last, * prev; 
        ListNode* p = head;
        ListNode* temp;

        if(head==NULL) return head; // 0 node

        while(p->next!=NULL){ // find tail
            p = p->next;
        }
        last = tail = p;

        if(head == tail) return head; // 1 node
        
        p = prev = head;
        while(true){
            temp = p->next;
            if(p->val>=x){
                if(p==tail) break; // searched all node
                tail->next = p; // inserted into tail
                p->next = NULL;
                tail = p;
                if(p!=head)prev->next = temp;
                else {head = temp;} // head is in the back, change head
            }
            else{
                prev = p;
            }
            if(p==last) break; // searched all node
            p = temp;
        }
        return head;
    }
};
