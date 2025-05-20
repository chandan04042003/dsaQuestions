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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *ptr1=head;
        ListNode *ptr2=head->next;
        ListNode *ptr3=ptr2->next;
        head->next=nullptr;
        while(ptr3!=nullptr){
            ptr2->next=ptr1;
            ptr1=ptr2;
            ptr2=ptr3;
            ptr3=ptr3->next;
        }
        ptr2->next=ptr1;
        return ptr2;
    }
};