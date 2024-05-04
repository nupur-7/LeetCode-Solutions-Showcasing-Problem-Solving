/*
LeetCode 881. Boats to Save People
Topics: Greedy, Sorting, Two Pointer
Approach: 
> Sort by weight: Begin by sorting the individuals based on their weight. This will enable us to efficiently manage the pairing process later on.
> Two-pointer approach: Utilize a two-pointer strategy, with one pointer starting from the lightest person and the other from the heaviest. These pointers will progressively converge towards the center of the sorted array.
> Greedy selection: Iterate through the sorted array, selecting pairs of individuals (one from each end) whose combined weight falls within the limit of the boat. Increment the boat count accordingly. Continue this process until all individuals are accommodated in boats.
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size(); 
        
        // Sort the people in ascending order of their weights
        sort(people.begin(), people.end());
        
        int i = 0, j = n - 1; // Pointers for the heaviest and lightest people
        int boats = 0; 

        while (i <= j) {
            // If the heaviest and lightest person can fit in one boat
            if (people[i] + people[j] <= limit) {
                i++; // Move to the next lightest person
                j--; // Move to the next heaviest person
            } else {
                j--; // If they can't fit, move to the next heaviest person only
            }
            boats += 1; // Increment the count of boats used
        }
        
        return boats; 
    }
};
