/*
LeetCode 33. Search in Rotated Sorted Array
Approach:
> Find Pivot Index: Use binary search to locate the pivot index where the rotation occurs in the rotated sorted array.
> Binary Search on Left Side: Perform binary search on the left side of the pivot index to find the target element.
> Binary Search on Right Side: If the target is not found on the left side, perform binary search on the right side of the pivot index.
> Handle Rotated Array: Adjust binary search indices based on the pivot index to handle the rotation of the sorted array.
> Return Index: Return the index of the target element if found, otherwise return -1 indicating that the target is not present in the array.
*/

class Solution {
public:
    // Function to find the pivot index in the rotated sorted array
    int findPivot(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        
        // Binary search to find the pivot index
        while (l < r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] > nums[r]) {
                // If mid element is greater than the rightmost element, the pivot is on the right side
                l = mid + 1; // Move towards the right
            } else {
                r = mid; // Otherwise, the pivot can be mid or towards the left
            }
        }
        return r; // Return the pivot index
    }
    
    // Function to perform binary search on a sorted array
    int BinarySearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] == target) {
                return mid; // If target found, return the index
            }
            if (nums[mid] < target) {
                l = mid + 1; // If target is greater than mid, search in the right half
            } else {
                r = mid - 1; // Otherwise, search in the left half
            }
        }
        return -1; // If target not found, return -1
    }
    

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Find the pivot index
	//The pivot index signifies the point in a rotated sorted array where the rotation occurs, dividing the array into two sorted subarrays.
        int pivot_index = findPivot(nums);
        
        // Apply binary search on left side of pivot (0 to pivot_index-1)
        int idx = BinarySearch(nums, 0, pivot_index - 1, target); 
        if (idx != -1) {
            return idx; // If target found, return the index
        } else {
            // If not found in left half, apply binary search on right side of pivot (pivot_index to n-1)
            idx = BinarySearch(nums, pivot_index, n - 1, target); 
        }
        return idx; 
    }
};
