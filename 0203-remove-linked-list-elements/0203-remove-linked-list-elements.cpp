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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* i=head;
        ListNode* prev=i;
        while(i!=nullptr){
            if(i->val==val){
                if(i==head){
                    head=head->next;
                    i=head;
                }
                else{
                    prev->next=i->next; // if i->next is there in left side of eqn =>
                    //boundary condn for it must be checked
                    i = i->next;
                } 
            }
            else{
                prev=i;
                i=i->next;
            }
        }
        return head;
    }
};