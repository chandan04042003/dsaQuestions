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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return nullptr;
        ListNode* i=head;
        ListNode* j=head;
        int cnt=1;
        while(cnt!=n){
            j=j->next;
            cnt++;
        }
        ListNode* prev=nullptr;
        while(j->next){
            prev=i;
            i=i->next;
            j=j->next;
        }
        if(i==head) head=head->next;
        else {
            prev->next=i->next;
            i->next=nullptr;
        }
        return head;
    }
};