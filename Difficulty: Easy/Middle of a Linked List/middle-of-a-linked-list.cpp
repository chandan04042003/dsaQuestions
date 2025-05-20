/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        Node *slow=head;
        Node *fast=head;
        // because fast jumps two steps 1->nullptr , there is nothing after nullptr,
        // so either it should end on nullptr or before nullptr
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow->data;
    }
};
