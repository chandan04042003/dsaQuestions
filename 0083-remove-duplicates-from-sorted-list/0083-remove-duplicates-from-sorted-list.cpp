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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* i=head;
        ListNode* j=head->next;
        while(j!=nullptr){
            if(i->val!=j->val){
                swap(i->next->val,j->val);
                i=i->next;
            }
            j=j->next;
        }
        i->next=nullptr;
        return head;
    }
};