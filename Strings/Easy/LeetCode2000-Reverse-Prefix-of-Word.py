#LeetCode 2000. Reverse Prefix of Word
class Solution(object):
    def reversePrefix(self, word, ch):
        # Initialize variables to store prefix, suffix, and found flag
        str1, str2 = "", ""
        found = False
        
        # Iterate through each character of the word
        for i in range(len(word)):
            # Check if the current character matches the specified character 'ch'
            if word[i] == ch:
                # Store the prefix up to the current character
                str1 = word[:i + 1]
                # Store the suffix from after the current character
                str2 = word[i + 1:]
                # Set found flag to true
                found = True
                # Exit the loop since we found the character
                break
        
        # Reverse the prefix
        str1 = str1[::-1]
        
        # If the character 'ch' was not found, return the original word
        if not found:
            return word
        
        # Otherwise, concatenate the reversed prefix with the suffix and return
        return str1 + str2

        