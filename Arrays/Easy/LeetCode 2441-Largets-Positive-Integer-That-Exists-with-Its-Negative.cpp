/*LeetCode 2441. Largets Positive Integer That Exists with Its Negative
Approach:
> Frequency Counting: Iterate through the given array and count the frequency of each number using an unordered map.
> Search for Negatives: Iterate through the array again and for each negative number, check if its positive counterpart exists in the map. If it does, update the maximum value found so far.
> Return Maximum: After iterating through the array, return the maximum value found(if two or more numbers are found), which represents the largest negative number with its positive counterpart present in the array.
*/

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // Creating an unordered map to store the frequency of each number
        unordered_map<int, int> mp;
        
        // Counting the frequency of each number in the input vector
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        // Variable to store the maximum value found so far
        int found = -1;
        
        // Iterating through the input vector to find the maximum value
        for(int i = 0; i < nums.size(); i++) {
            // Checking if the current number is negative
            if(nums[i] < 0) {
                // Checking if the absolute value of the current number exists in the map
                if(mp.find(-1 * nums[i]) != mp.end()) {
                    // Updating 'found' with the maximum
value found
                    found = max(found, abs(nums[i]));
                }
            }
        }

        return found;
    }
};
