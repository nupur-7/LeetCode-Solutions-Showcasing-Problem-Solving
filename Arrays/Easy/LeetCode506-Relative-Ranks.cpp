/*
LeetCode 506. Relative Ranks

You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique. Return an array answer of size n where answer[i] is the rank of the ith athlete.

Approch:
> Sort the Scores: Start by making a copy of the original scores and sorting them in descending order. This step is crucial as it helps us determine the ranks based on the sorted order of scores.
> Assign Ranks: After sorting the scores, iterate through the sorted scores and assign ranks accordingly. The top three scores receive special medals (Gold, Silver, and Bronze), while the rest receive their rank represented as a string.
> Map Scores to Ranks: Utilize an unordered map to associate each score with its corresponding rank. This mapping allows for easy retrieval of ranks for the original scores.
> Finally, iterate through the original scores and fetch their ranks from the map. Populate a vector with the ranks corresponding to each original score. This vector represents the relative ranks of the scores as required.
*/ 
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // Copy the scores to another vector to preserve the original order
        vector<int> scores;
        scores = score;
        
        // Sort the scores in descending order
        sort(scores.begin(), scores.end());
        reverse(scores.begin(), scores.end());
        
        // Map to store the rank (as string) corresponding to each score
        unordered_map<int, string> mp;
        
        // Assign ranks based on the sorted order of scores
        for (int i = 0; i < scores.size(); i++) {
            // Assigning ranks as per the requirements
            if (i > 2) {
                mp[scores[i]] = to_string(i + 1);
            } else if (i == 0) {
                mp[scores[i]] = "Gold Medal";
            } else if (i == 1) {
                mp[scores[i]] = "Silver Medal";
            } else if (i == 2) {
                mp[scores[i]] = "Bronze Medal";
            }
        }
        
        // Vector to store the result
        vector<string> res;
        
        // Assigning ranks to original scores
        for (int i = 0; i < score.size(); i++) {
            res.push_back(mp[score[i]]);
        }
        
        return res;
    }
};
