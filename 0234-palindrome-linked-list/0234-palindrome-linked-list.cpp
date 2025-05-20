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
private:
    ListNode* reverseLL(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* ptr1=head;
        ListNode* ptr2=head->next;
        ListNode* ptr3=ptr2->next;
        head->next=NULL;
        while(ptr3!=nullptr){
            ptr2->next=ptr1;
            ptr1=ptr2;
            ptr2=ptr3;
            ptr3=ptr3->next;
        }
        ptr2->next=ptr1;
        return ptr2;
    }
public:
    bool isPalindrome(ListNode* head) {
       if(!head) return false;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast!=nullptr) slow=slow->next; // if odd no. of nodes
        
        // palindrome check
        ListNode *rev = reverseLL(slow);
        ListNode *start=head;
        while(rev!=nullptr){
            if(start->val != rev->val) return false;
            rev=rev->next;
            start=start->next;
        }
        return true;
    }
};