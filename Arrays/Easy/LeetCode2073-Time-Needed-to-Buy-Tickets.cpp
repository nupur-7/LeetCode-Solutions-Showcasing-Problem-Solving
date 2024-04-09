/*
LeetCode 2073. Time Needed to Buy Tickets

Brief description : The problem is asking for the time taken for a specific person (at position k) to finish buying tickets given a queue of people with varying ticket demands.

This approach iterates through each person in the queue, simulating the process of buying tickets one by one until the target person at position k finishes buying all their tickets.

Approach:

1. Initialize a variable `time` to keep track of the total time taken.
2. Run a loop until the person at position k has finished buying all their tickets (tickets[k] becomes 0).
3. Within the loop, iterate through each person in the queue and process them one by one:
   - For each person, if they have tickets left (`tickets[i] > 0`), decrement their ticket count by 1 and increment the `time` variable to represent the time taken for them to buy a ticket.
   - Check if the person at position k has finished buying tickets (tickets[k] becomes 0) and if the current person being processed is at position k. If so, break out of the loop as the required person has finished buying tickets.
4. Return the total time taken (`time`) for the person at position k to finish buying tickets.

*/
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0; 

        // Continue the loop until tickets[k] becomes 0
        while (tickets[k]) {
            for (int i = 0; i < tickets.size(); i++) {
                // If there are tickets available for the current ticket type
                if (tickets[i] > 0) {
                    // Decrease the count of each available tickets by 1
                    tickets[i] = tickets[i] - 1;
                    // Increment the time required to buy a ticket
                    time++;
                }
                // Check if tickets[k] has become 0 and if i is equal to k
                // If so, break out of the loop
                if (tickets[k] == 0 && i == k) {
                    break;
                }
            }
        }
        return time; // Return the total time required to buy all tickets
    }
};
