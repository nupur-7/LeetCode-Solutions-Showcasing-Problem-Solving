/* 
LeetCode 1700. Number of Students Unable to Eat Lunch
Approach:
To solve the problem, we simulate the process of serving sandwiches to students. We maintain two data structures: a stack for sandwiches and a queue for students.

> We iterate over the sandwiches and push each onto the stack, ensuring the last-in, first-out order. 
> We iterate over the students and push each student's preference onto the queue, maintaining the first-in, first-out order.
> We simulate serving sandwiches to students until all sandwiches are served or all students are served:
	->If the top sandwich matches the front student's preference, we serve the sandwich to the student by removing both from their respective data structures.
	->If not, we move the student to the end of the queue for the next serving round.
> Finally, we return the number of students remaining in the queue, representing those unable to eat their preferred sandwiches.
*/


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // Create a stack to represent the sandwiches stack
        stack<int> st;
        for(int i=sandwiches.size()-1;i>=0;i--)
        {
            st.push(sandwiches[i]);
        }
        
        // Create a queue to represent the students queue
        queue<int> q;
        for(int i:students)
        {
            q.push(i);
        }
        
        // Initialize a variable to keep track of served students
        int served = 0;
        
        // Iterate over the sandwiches stack until it's empty or all students are served
        while(!st.empty() && served < q.size())
        {
            // If the top sandwich matches the preference of the front student, serve the student
            if(st.top() == q.front())
            {
                st.pop();
                q.pop();
                served = 0; // Reset served counter if a student gets served
            }
            else
            {
                // If the sandwich doesn't match the preference, move the student to the end of the queue
                int x = q.front();
                q.pop();
                q.push(x);
                served++; // Increment served counter to keep track of consecutive students who didn't get sandwiches
            }
        }
        
        // Return the number of students who didn't get served sandwiches
        return q.size();
    }
};
