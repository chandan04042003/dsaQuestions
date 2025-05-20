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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        // l1=reverseLL(l1);
        // l2=reverseLL(l2);
        ListNode* i=l1;
        ListNode* j=l2;
        int carry=0;
        while(i!=nullptr && j!=nullptr){
            ListNode* newNode = new ListNode(0); 
            int sum=i->val+j->val+carry;
            if(sum>9){
                newNode->val=sum%10;
                carry=1;
            }
            else{
                newNode->val=sum;
                carry=0;
            }
            temp->next=newNode;
            temp=temp->next;
            i=i->next;
            j=j->next;
        }
        while(i!=nullptr){
            ListNode* newNode = new ListNode(0); 
            int sum=i->val+carry;
            if(sum>9){
                newNode->val=sum%10;
                carry=1;
            }
            else{
                newNode->val=sum;
                carry=0;
            }
            temp->next=newNode;
            temp=temp->next;
            i=i->next;
        }
        while(j!=nullptr){
            ListNode* newNode = new ListNode(0); 
            int sum=j->val+carry;
            if(sum>9){
                newNode->val=sum%10;
                carry=1;
            }
            else{
                newNode->val=sum;
                carry=0;
            }
            temp->next=newNode;
            temp=temp->next;
            j=j->next;
        }
        if (carry) {
            temp->next = new ListNode(carry);
        }
        return dummy->next;
    }
};