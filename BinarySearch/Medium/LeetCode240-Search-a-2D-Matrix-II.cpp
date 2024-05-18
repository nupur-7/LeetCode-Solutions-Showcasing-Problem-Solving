/*
LeetCode 240. Search a 2D Matrix II
Approach:
> Starting from the top-right corner(or bottom left), we have access to the largest element in the row and the smallest element in the column.Comparing the target with this element allows us to determine whether the target could be in the current row or column, or if it's not present in the matrix at all.
> We start from the top-right corner of the matrix because it provides a unique way to compare elements and reduce the search space.
> As we move left, the values decrease, and as we move down, the values increase. This is because both rows and columns are sorted in ascending order.
> By moving left or down based on the comparison with the target, we effectively eliminate rows or columns containing values that are not equal to the target.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get the number of rows and columns in the matrix
        int m = matrix.size(); // Number of rows
        int n = matrix[0].size(); // Number of columns
        
        // Start from the top-right corner of the matrix
        int row = 0; // Start from the first row
        int col = n - 1; // Start from the last column
        
        // While within the bounds of the matrix
        while (row < m && col >= 0) {
            // Retrieve the current element
            int elmnt = matrix[row][col];
            
            // Check if the current element is the target
            if (elmnt == target) {
                return true; // Target found
            }
            // If the target is less than the current element
            else if (target < elmnt) {
                col--; // Move left: discard the current column
            }
            // If the target is greater than the current element
            else if (target > elmnt) {
                row++; // Move down: discard the current row
            }
        }
        
        // If the target is not found in the matrix, return false
        return false;
    }
};
