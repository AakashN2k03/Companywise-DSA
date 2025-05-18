// GFG: Diameter of a Binary Tree 

// Pattern : Depth / Height / Diameter Based

class Solution {
  public:
    int dia(Node* root , int& diameter_value)
    {
        if(!root) return 0;
        int left_subtree=dia(root->left,diameter_value);
        int right_subtree=dia(root->right,diameter_value);
        
        diameter_value=max(diameter_value,(left_subtree+right_subtree));
        return 1+max(left_subtree,right_subtree);
    }
    int diameter(Node* root) {
        
        int diameter_value=0;
        dia(root,diameter_value);
        return diameter_value;
        
    }
};
// Time Complexity: O(n)
// Space Complexity: O(h)
