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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* i=head;
        ListNode* j=head->next;
        ListNode* curr=j;
        while(i->next!=nullptr && j->next!=nullptr){
            i->next=i->next->next;
            j->next=j->next->next;
            i=i->next;
            j=j->next;
        }
        i->next=curr;
        return head;
    }
};