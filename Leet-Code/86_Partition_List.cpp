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

// Solution 1
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

// Solution 2
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *first_head=NULL, *first_end=NULL, *second_head=NULL, *second_end=NULL, *p, *temp;

        p = head;
        if(p == NULL) return head;
        while(p!=NULL){
            cout<<p->val<<endl;
            temp = p->next;
            p->next = NULL;
            if(p->val<x){
                if(first_head==NULL) {
                    first_head = p;
                    first_end = p;
                }
                else{
                    first_end->next = p;
                    first_end = p;
                }
            }
            else{
                if(second_head==NULL) {
                    second_head = p;
                    second_end = p;
                }
                else{
                    second_end->next = p;
                    second_end = p;
                }
            }
            p = temp;
        }
        if(first_head==NULL) return second_head;
        first_end->next = second_head;
        return first_head;
    }
};
