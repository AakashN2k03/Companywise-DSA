// CODE360:Spiral Matrix

#include <bits/stdc++.h> 
vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) 
{
    int left,top,right,bottom;
     vector<int>ans;
     left=top=0;
     right=m-1;
     bottom=n-1;

     while(left<=right && top<=bottom)
     {   // left to right
         for(int i=left;i<=right;i++)
         {
             ans.push_back(matrix[top][i]);
         }
         top++;

         // top to bottom
         for(int i= top;i<=bottom;i++)
         {
             ans.push_back(matrix[i][right]);
         }
         right--;

         //right to left
         if(top<=bottom)
         {
            for(int i=right;i>=left;i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
         }
         //bottom to top
         if(left<=right)
         {
             for(int i=bottom;i>=top;i--)
             {
                 ans.push_back(matrix[i][left]);
             }
             left++;
         }
     }
     return ans;
}

// Time Complexity: O(n * m) 
// Space Complexity: O(n * m) 
