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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr) return NULL;
        ListNode *s= head;
        ListNode *f=head;
        while(f!=nullptr and f->next!=nullptr){
            f=f->next->next;
            s=s->next;
            if(f==s) break;
        }
        if(f==nullptr or f->next==nullptr) return NULL;
        s=head;
        while(s!=f){
            s=s->next;
            f=f->next;
        }
        return s;
    }
};