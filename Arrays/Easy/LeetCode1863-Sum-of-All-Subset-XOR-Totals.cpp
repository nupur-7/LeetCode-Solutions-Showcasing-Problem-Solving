/*
LeetCode 1863. Sum of All Subset XOR Totals
Topics: Array ,Math, Backtracking,Bit Manipulation, Combinatorics ,Enumeration

Approach 1:
> The approach to solve the problem of finding the sum of XORs of all subsets of a given list of integers involves generating all possible subsets of the list and then calculating the XOR of each subset.
> A recursive function calc_subsets that generates all subsets using a depth-first search approach. Once all subsets are generated, the function subsetXORSum iterates over each subset to compute its XOR value. 
> The XOR value of each subset is then added to a cumulative sum, which is finally returned as the result.
*/
class Solution {
public:
    vector<vector<int>> res; // To store all subsets

    // Helper function to calculate all subsets
    void calc_subsets(vector<int>& nums, int i, vector<int>& temp) {
        // Base case: if the index is out of bounds, add the current subset to the result
        if (i >= nums.size()) {
            res.push_back(temp);
            return;
        }
        // Include the current element in the subset
        temp.push_back(nums[i]); // take
        calc_subsets(nums, i + 1, temp);
        
        // Exclude the current element from the subset
        temp.pop_back(); // not take
        calc_subsets(nums, i + 1, temp);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int> temp; // Temporary vector to store current subset
        calc_subsets(nums, 0, temp); // Calculate all subsets

        int sum = 0; // To store the sum of XORs of all subsets
        for (vector<int>& vec : res) {
            int xor_tot = 0; // To store the XOR of the current subset
            for (int &x : vec) {
                xor_tot ^= x; // Calculate the XOR of the current subset
            }
            sum += xor_tot; // Add the XOR of the current subset to the sum
        }
        return sum; // Return the final sum of XORs
    }
};

/*
Approach 2:
In this the XOR total is calculated directly during the subset generation process without explicitly storing the subsets
*/

class Solution {
public:
    // Helper function to calculate the sum of XORs of all subsets recursively
    int calc_subsets(vector<int>& nums, int i, int xor_tot) {
        // Base case: if the index is out of bounds, return the current XOR total
        if (i >= nums.size()) {
            return xor_tot;
        }
        
        // Include the current element in the subset and calculate the XOR total
        int include = calc_subsets(nums, i + 1, nums[i] ^ xor_tot);

        // Exclude the current element from the subset and calculate the XOR total
        int exclude = calc_subsets(nums, i + 1, xor_tot);
        
        // Return the sum of XOR totals from both including and excluding the current element
        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {
        // Initial call to calc_subsets with the first index and initial XOR total of 0
        return calc_subsets(nums, 0, 0);
    }
};

