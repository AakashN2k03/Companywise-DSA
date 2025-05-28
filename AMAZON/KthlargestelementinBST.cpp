// GFG: Kth largest element in BST

// Pattern: BST Specific Problems

class Solution {
  public:
  void inorder(Node* root, int k, int& largest, int& count)
{
    if (!root) return;

    inorder(root->right, k, largest, count);

    count++;
    if (count == k) 
    { 
        largest = root->data; 
        return;
    }

    inorder(root->left, k, largest, count);
}

    int kthLargest(Node *root, int k) {
        // Your code here
    int largest = -1;
    int count = 0;
    inorder(root, k, largest, count);
    return largest;
    }
};

// Time Complexity: O(n) (without return) , ( with return ) O(k)
// Space Complexity:O(h)
