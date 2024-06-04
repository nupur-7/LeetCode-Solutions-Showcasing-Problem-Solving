/*
LeetCode 409. Longest Palindrome
Description: Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome that can be built with those letters.

Approach:
> To form the longest palindrome from a given string, at most one character can have an odd frequency, while the rest must have even frequencies.
> We use an unordered set to track character frequencies. As we iterate through the string, we insert each character into the set if it's not already present. If it is present, we remove it and add 2 to our palindrome length, indicating we have found a pair.
> After processing all characters, if the set is not empty, we can include one remaining odd-frequency character in the middle, adding 1 to the length. This ensures the maximum length palindrome is calculated efficiently.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int c = 0;  // Variable to keep track of the length of the palindrome
        unordered_set<char> st;  // Set to track characters with odd frequencies

        int n = s.size();
        for (int i = 0; i < n; i++) {  // Iterate through each character in the string
            if (st.find(s[i]) != st.end()) {  // If the character is already in the set
                c += 2;  // We can form a pair, so add 2 to the length
                st.erase(s[i]);  // Remove the character from the set
            } else {
                st.insert(s[i]);  // Otherwise, add the character to the set
            }
        }

        // If there are characters left in the set, add 1 to the length
        // because we can place one odd-frequency character in the middle
        return !st.empty() ? c + 1 : c;
    }
};
