/*
LeetCode 2007. Find Original Array From Doubled Array
> The goal is to find the original array from a changed array where each element have its double.Since theres always a double present in the array for each element the size of orginal 
  array will alway be half the size of changed array(and its size should be even)
> It begins by counting the frequency of each unique element using a map and then sorts the changed array for orderly iteration. 
> As it iterates through each element, it checks for its pair by verifying the existence and frequency of its double. 
> If a valid pair is found, the element is added to the result and its frequency is updated accordingly. This process ensures that all elements are successfully paired
> If any element's double is not found in the array return empty vector
*/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // Check if the size of the changed vector is odd return an empty vector
        if(changed.size() % 2 != 0) {
            return {};
        }
        
        vector<int> res;
        unordered_map<int, int> mp; // Map to store the frequency of each element
        sort(changed.begin(), changed.end()); // Sort the changed vector in ascending order as always the minimum element will have its double in the array
        
        for(int n : changed) {
            mp[n]++;
        }

        for(int x : changed) {
            // If the frequency of the current element is 0 skip it
            if(mp[x] == 0) {
                continue;
            }
            
            // If the double of the current element is not found in the map or its frequency is zero,
            // it's not possible to form pairs, return an empty vector
            if(mp.find(x * 2) == mp.end() || mp[x * 2] == 0) {
                return {};
            }
            
            res.push_back(x);
            // Decrement the frequency of the current element and its double in the map
            mp[x]--;
            mp[x * 2]--;
        }
        
        return res; 
    }
};
