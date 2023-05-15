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


struct comp{
    bool operator()(ListNode * a, ListNode* b){
        if(a->val>b->val) return true;
        return false;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, comp>  pq;
        ListNode *head=NULL, *tail=NULL, *ptr;

        // 가장 앞 부분을 우선순위 큐에 넣는다
        // 우선순위큐에서 가장 작은 값을 뽑는다
        // 가장 작은 값을 리스트에 넣고, 그 값이 나온 리스트의 다음 값을 우선순위큐에 넣는다
        for(int i=0; i<lists.size(); i++){
            if(lists[i]==NULL) continue;
            pq.push(lists[i]);
        }

        while(!pq.empty()){
            ptr = pq.top(); pq.pop();
            
            if(ptr->next) pq.push(ptr->next);

            // 삽입
            if(head==NULL){
                head = ptr;
            }
            else tail->next = ptr;
            tail = ptr;
        }
        return head;
    }
};
