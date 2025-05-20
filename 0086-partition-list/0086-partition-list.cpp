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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode* i=head;
        while(i!=nullptr){
            if(i->val<x){
                ListNode* newNode= new ListNode(0);
                newNode->val=i->val;
                temp->next=newNode;
                temp=temp->next;
            }
            i=i->next; 
        }
        i=head;
        while(i!=nullptr){
            if(i->val>=x){
                ListNode* newNode= new ListNode(0);
                newNode->val=i->val;
                temp->next=newNode;
                temp=temp->next;
            }
            i=i->next; 
        }  
        return dummy->next;
    }
};