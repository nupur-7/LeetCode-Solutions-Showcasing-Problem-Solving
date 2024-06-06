/*
LeetCode 350. Intersection of Two Arrays II
Approach:
> The given code finds the intersection of two arrays, nums1 and nums2, by using hash maps to count the frequency of each element. First, it populates two unordered maps, mp1 and mp2, with the frequencies of elements in nums1 and nums2 respectively.
> Then, it iterates through nums1 and checks if each element exists in mp2 and has a non-zero count in both maps. If so, the element is added to the result vector res, and the counts in both maps are decremented.
> This ensures that only common elements, up to their minimum frequency in both arrays, are included in the result.
>It has a time complexity of O(n + m), where n and m are the lengths of the two arrays.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int> mp1, mp2;

        // Count the frequency of each element in nums1
        for (int x : nums1) {
            mp1[x]++;
        }

        // Count the frequency of each element in nums2
        for (int x : nums2) {
            mp2[x]++;
        }

        vector<int> res;

        // Iterate through each element in nums1
        for (int &x : nums1) {
            // Check if the element is in nums2 and has non-zero counts in both maps
            if (mp2.find(x) != mp2.end() && mp1[x] > 0 && mp2[x] > 0) {
                res.push_back(x);  // Add the element to the result
                mp2[x]--;  // Decrement the count in mp2
                mp1[x]--;  // Decrement the count in mp1
            }
        }

        return res;
    }
};
