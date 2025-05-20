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
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        ListNode *s= head;
        ListNode *f=head;
        while(f!=nullptr and f->next!=nullptr){
            f=f->next->next;
            s=s->next;
            if(f==s) break;
        }
        if(f==nullptr or f->next==nullptr) return false;
        return true;
    }
};