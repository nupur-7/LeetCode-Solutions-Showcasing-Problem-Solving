/*
LeetCode 3 Longest Substring Without Repeating Characters
Approach:
> Sliding Window Technique: Use two pointers 'i' and 'j' to define a sliding window that represents the current substring without repeating characters.
> Count Array: Initialize a count array of size 256 (assuming ASCII characters) to store the count of characters encountered within the sliding window.
> Iterate Through the String: Iterate through the string using pointer 'j'. Increment the count of the character at position 'j'. If a duplicate character is encountered, move the window by incrementing 'i' until there are no duplicate characters within the window.
> Update Maximum Length: Update the maximum length of the substring without repeating characters (stored in 'ans') based on the length of the current window. Continue this process until 'j' reaches the end of the string. Return the maximum length 'ans'.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count[256]={0}; // Count array to store the count of characters in 's'
        int  i=0,j=0; // Pointers 'i' and 'j' for the sliding window
        int ans=0; // Variable to store the length of the longest substring without repeating characters
        
        // Loop through the string using pointer 'j'
        while(j<s.size())
        {
            count[s[j]]++; // Increment the count of the character at position 'j'
            
            // If there is a duplicate character, move the window by incrementing 'i'
            while(count[s[j]]>1)
            {
                count[s[i]]--; // Decrement the count of the character at position 'i'
                i++; // Move the window by incrementing 'i'
            }
            
            ans=max(ans,j-i+1); // Update 'ans' with the maximum length of substring without repeating characters
            
            j++; // Move the window by incrementing 'j'
        }
        
        return ans; // Return the length of the longest substring without repeating characters
    }
};
