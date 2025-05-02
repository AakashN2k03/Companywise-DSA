GFG:Detect Loop in linked list

class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        Node*slow=head;
        Node*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};
// Time Complexity:O(n)
// Space Complexity:O(1)
