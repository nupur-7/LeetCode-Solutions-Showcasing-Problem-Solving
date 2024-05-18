/*
LeetCode 74. Search a 2D Matrix
Approach:
> It is given that each row in the matrix is sorted in ascending order.
> Imagine the matrix flattened into a single sorted array of size row * col. Apply binary search on this conceptual flattened array to find the target.Treat the matrix as a single sorted array with indices ranging from 0 to row * col - 1.
> Calculate the middle index mid as l + (r - l) / 2 to prevent overflow. Convert the 1D index   mid to a 2D index:
 Row index: mid / col
 Column index: mid % col
> If the element is less than the target, move the left pointer to mid + 1.If the element is greater than the target, move the right pointer to mid - 1. If the element is equal to the target, return true.
> If the loop ends without finding the target, return false
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get the number of rows and columns in the matrix
        int row = matrix.size(), col = matrix[0].size();
        
        // Initialize the left and right pointers for binary search
        int l = 0, r = row * col - 1, mid;
        
        // Perform binary search
        while (l <= r) {
            // Calculate the middle index to avoid overflow
            mid = l + (r - l) / 2;
            
            // Convert the 1D middle index to a 2D row and column index
            int elmnt = matrix[mid / col][mid % col];
            
            // Check if the element at the middle index is the target
            if (elmnt == target) {
                // If found, return true
                return true;
            }
            
            // If the target is greater than the middle element, adjust the left pointer
            if (target > elmnt) {
                l = mid + 1;
            }
            // If the target is less than the middle element, adjust the right pointer
            else {
                r = mid - 1;
            }
        }
        
        // If the target is not found, return false
        return false;        
    }
};
