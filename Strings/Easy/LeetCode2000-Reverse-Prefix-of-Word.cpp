/*
LeetCode 2000. Reverse Prefix of Word
Approach:
> Initialize two empty strings str1 and str2 to store the prefix and suffix of the word respectively.
>Iterate through each character of the word.If the current character matches the specified character 'ch', store the substring of the word from the beginning up to the current character in str1, and store the substring from after the current character to the end in str2.
> Reverse str1.Concatenate str1 with str2 and return the result if 'ch' is found. If 'ch' is not found, return the original word.
*/

class Solution {
public:
    string reversePrefix(string word, char ch) {
        // Initialize two empty strings to store the parts before and after the character
        string str1="",str2="";
        // Initialize a boolean variable to track if the character is found
        bool found=false;-
        
        // Loop through each character in the word
        for(int i=0;i<word.size();i++)
        {
            // If the current character matches the specified character 'ch'
            if(word[i]==ch)
            {
                // Store the substring from the beginning up to the current character (inclusive) in str1
                str1 = word.substr(0, i + 1);
                // Store the substring from after the current character to the end in str2
                str2 = word.substr(i + 1);
                // Set the found flag to true
                found=true;
                // Break out of the loop since we found the character
                break;
            }
        }
        
        // Reverse the characters in str1
        reverse(str1.begin(),str1.end());
        
        // If the character 'ch' was not found in the word, return the original word
        if(found==false)
        {return word;}
        
        // Otherwise, concatenate the reversed prefix (str1) with the suffix (str2) and return
        return str1+str2;
    }
};
