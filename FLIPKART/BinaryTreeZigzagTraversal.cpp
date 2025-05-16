// CODE 360:  Binary Tree Zigzag Traversal

// PATTERN : TRAVERSAL

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{     
      queue<BinaryTreeNode<int>*> qu;
      qu.push(root);
      vector<int>ans;
        if(!root) return ans;
      bool zigzag=true;
      while(!qu.empty())
      {
         int size=qu.size();
         vector<int>level(size);
         for(int i=0;i<size;i++)
         {
             auto node=qu.front();
             qu.pop();
             if(node->left) qu.push(node->left);
             if(node->right) qu.push(node->right);

             int index=zigzag?i:(size-1-i);
             level[index]=node->data;

         }
         for(int val:level)
         {
             ans.push_back(val);

         }
         zigzag=!zigzag;

      }
      return ans;
}
//  Time Complexity: O(N)
// Space Complexity: O(N)
