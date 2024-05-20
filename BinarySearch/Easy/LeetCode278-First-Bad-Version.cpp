/*
LeetCode 278 First Bad Version
Topics: BinarySearch,Interactive

Approach:
> we set the search range from version 0 to n, where n represents the total number of versions.
> We then iteratively narrow down this search range by calculating the middle version (mid) and determining whether it is a bad version or not using the isBadVersion function.
> If mid is a bad version, we update a variable ans to store this potential candidate for the first bad version and continue searching for earlier bad versions in the left half of the range by updating j to mid - 1. If mid is not a bad version, we adjust the search range to the right half by updating i to mid + 1.
> This process continues until the search range is exhausted, at which point ans holds the potential candidate for the first bad version, and we return it as the final result.
> This approach ensures an efficient search by halving the search space in each iteration, resulting in a time complexity of O(log n), where n represents the total number of versions.
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 0, j = n;
        int ans = 0; // Variable to store the potential candidate for the first bad version

        // Binary search for the first bad version
        while (i <= j) {
            long long mid = i + (j - i) / 2; // Calculate the middle version
            if (isBadVersion(mid) == true) { // If mid is a bad version
                ans = mid; // Update ans to store the potential candidate for the first bad version
                j = mid - 1; // Search for the first bad version in the left half
            } else if (isBadVersion(mid) == false) { // If mid is not a bad version
                i = mid + 1; // Search for the first bad version in the right half
            }
        }
        return ans; // Return the potential candidate for the first bad version
    }
};
