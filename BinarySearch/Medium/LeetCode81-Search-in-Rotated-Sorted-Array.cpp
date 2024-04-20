/*
LeetCode 81. Search in Rotated Sorted Array II
This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates.
To resolve this we have used a condition to remove duplicates while finding pivot index.
*/

class Solution {
public:
    // Function to find the pivot index in the rotated sorted array
    int findPivot(vector<int>& nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        
        // Binary search to find the pivot index
        while (l < r) {
            // Skip duplicates from left and right
            while (l < r && nums[l] == nums[l + 1]) {
                l++;
            }
            while (l < r && nums[r] == nums[r - 1]) {
                r--;
            }
            
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
    bool BinarySearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] == target) {
                return true; // If target found, return true
            }
            if (nums[mid] < target) {
                l = mid + 1; // If target is greater than mid, search in the right half
            } else {
                r = mid - 1; // Otherwise, search in the left half
            }
        }
        return false; // If target not found, return false
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Find the pivot index
        int pivot = findPivot(nums);
        
        // Perform binary search on left side of pivot (0 to pivot_index-1)
        if (BinarySearch(nums, 0, pivot - 1, target)) {
            return true; // If target found, return true
        }
        
        // Perform binary search on right side of pivot (pivot_index to n-1)
        return BinarySearch(nums, pivot, n - 1, target); // Return true if target found, otherwise false
    }
};
