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
    ListNode* reverseLL(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        ListNode* ptr3 = ptr2->next;
        head->next = nullptr;
        while (ptr3 != nullptr) {
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr3;
            ptr3 = ptr3->next;
        }
        ptr2->next = ptr1;
        return ptr2;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy; // dummy is used because if head is used and l=1
        // (from head), the final ans to be returned should be the last node

        for (int i = 1; i < left; i++) prev = prev->next;
        ListNode* l = prev->next;

        ListNode* r = l;
        for (int i = left; i < right; i++) r = r->next;

        ListNode* rightNxt = r->next;
        r->next = nullptr; // imp

        ListNode* newHead = reverseLL(l);
        prev->next = newHead;
        l->next = rightNxt;
        return dummy->next;
    }
};