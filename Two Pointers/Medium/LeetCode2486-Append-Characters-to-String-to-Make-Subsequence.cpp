/*
LeetCode 2486. Append Characters to String to Make Subsequence
Description:Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

Approach:
The goal was to simply find the longest common subsequence and then return the difference of its size with the length of t.
> we use two pointers, i and j, to traverse s and t respectively. We iterate through s and for each character in s, we check if it matches the current character in t.
> If they match, we move both pointers forward. If they don't match, we move only the pointer in s forward. Throughout this process, we keep track of the longest prefix of t that we can match as a subsequence within s using the variable maxlen. 
> After traversing through s, the number of characters needed to be appended to s to make t a subsequence is calculated as the difference between the length of t and maxlen.

*/

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length(); 
        int m = t.length(); 
        int i = 0, j = 0; // Pointers to traverse s and t
        int maxlen = 0; //to store the length of the longest prefix of t that is a subsequence of s

        // Traverse through both strings
        while (i < n && j < m) {
            // If the current characters match, move both pointers
            while (i < n && j < m && s[i] == t[j]) {
                i++;
                j++;
            }
            // Update maxlen with the maximum value of j encountered
            maxlen = max(maxlen, j);
            // Move to the next character in s
            i++;
        }

        // The number of characters to append to s to make t a subsequence
        return m - maxlen;
    }
};
