// GFG:Rotate by 90 degree anti-clockwise 

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        int row=mat.size();
        int col=mat[0].size();
        
        for(int i=0;i<row;i++)
        {
            reverse(mat[i].begin(),mat[i].end());
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=i+1;j<col;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
};
// Time Complexity: O(n^2) 
// Space Complexity: O(1) 
