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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p, * prev, *temp;
        long long num1=0, num2=0;

        // reverse list
        prev = l1; p = prev->next; prev->next = NULL; 
        while(p!=NULL){
            temp = p->next;
            p->next = prev;
            prev = p;
            p = temp;
        }
        l1 = prev;

        while(p!=NULL){
            num1 *= 10;
            num1 += p->val;
            p = p->next;
        }

        prev = l2; p = prev->next; prev->next = NULL; 
        while(p!=NULL){
            temp = p->next;
            p->next = prev;
            prev = p;
            p = temp;
        }
        l2 = prev;

        // add
        ListNode *p1 = l1, *p2=l2, *pre_temp, *node;
        temp = l1;
        int num=0, over=0;
        while( p1!=NULL || p2!=NULL){
            pre_temp = temp;
            temp = p1;
            if(p1==NULL){
                temp = p2; // reuse list 2
                num=p2->val+over;
                over = num/10;
                num = num%10;
                p2 = p2->next; 
                pre_temp->next = temp; // connect answer list
            }
            else if(p2==NULL){
                num=p1->val+over;
                over = num/10;
                num = num%10;
                p1 = p1->next;
            }
            else{
                num=p1->val+p2->val+over;
                over = num/10;
                num = num%10;
                p1 = p1->next; p2 = p2->next;
            }
            temp->val = num; // reuse list 1
        }
        if(over==1){ // if one more digit left
            node = new ListNode(1);
            temp->next = node;
        }

        // reverse list
        prev = l1; p = prev->next; prev->next = NULL; 
        while(p!=NULL){
            temp = p->next;
            p->next = prev;
            prev = p;
            p = temp;
        }
        l1 = prev;
        return l1;
    }
};
