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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode*, bool> um;
    ListNode *p=headA;

    while(p!=NULL){
        um[p]=true;
        p = p->next;
    } 
    p = headB;
    while(p!=NULL){
        if(um[p]) return p;
        p = p->next;
    }
    return NULL;
    }
};

// faster solution
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a=headA, *b=headB;

    while(a!=b){
        a = a!=NULL? a->next : headB;
        b = b!=NULL? b->next : headA;
    } 
    return a;
    }
};
