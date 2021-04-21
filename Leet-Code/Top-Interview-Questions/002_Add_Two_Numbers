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
        ListNode* ptr1=l1, * ptr2=l2, * ans, * ptr3=NULL;
        int sum, digit=0;
        
        while(ptr1!=NULL&&ptr2!=NULL){
            sum=ptr1->val+ptr2->val+digit;
            digit=0;
            if(sum>=10) {
                sum-=10;
                digit=1;}
            
            ans=new ListNode;
            ans->val=sum;
            ans->next=ptr3;
            ptr3=ans;
            cout<<ans->val;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            
        }
        
        if(ptr1==NULL) ptr1=ptr2;
        
        while(ptr1!=NULL){
            sum=ptr1->val+digit;
            digit=0;
            if(sum>=10) {
                sum-=10;
                digit=1;}
            ans=new ListNode;
            ans->val=sum;
            ans->next=ptr3;
            ptr3=ans;
            ptr1=ptr1->next;
        }
        if(digit==1){
            ans=new ListNode;
            ans->val=1;
            ans->next=ptr3;
            ptr3=ans;
        }
        
        ptr1=ptr3;
        ptr3=NULL;
        while(ptr1!=NULL){
            ans=new ListNode;
            ans->val=ptr1->val;
            ans->next=ptr3;
            ptr3=ans;
            ptr1=ptr1->next;
        }
        
        return ptr3;
    }
};
