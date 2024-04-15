/*
LeetCode 129. Sum Root to Leaf Numbers
Approach:
> The sumNumbers function uses recursion to find the total sum of all paths from the root to the leaves in a binary tree. It starts from the top (the root) and looks at each node one by one.
> As it goes, it keeps track of a running total, which is like adding up the numbers along the path it's taken so far.
> When it reaches a leaf (a node with no more branches), it adds up the numbers it's been keeping track of to the grand total.
> Then it does the same thing for each branch coming out of the current node, keeping track of the total for each path. It separately calculates the sum of paths on the left side and the right side of the current node, and then adds these sums together to get the collective answer.
> Finally, when it's checked all the paths, it adds up all those totals and gives you the final answer, which is the sum of all the paths from the root to the leaves in the tree.
*/
class Solution {
public:
    // Helper function to recursively traverse the tree and calculate the sum
    int solve(TreeNode* root, int curr) {
        // If the current node is null, return 0
        if (!root) {
            return 0;
        }

        // Update the current value by appending the current node's value
        curr = (curr * 10) + root->val;

        // If the current node is a leaf node (no children), return the current value
        if (root->left == NULL && root->right == NULL) {
            // Leaf node (we found a root-to-leaf path)
            return curr;
        }

        // Recursively calculate the sum of left and right subtrees
        int l = solve(root->left, curr);
        int r = solve(root->right, curr);

        // Return the sum of left and right subtree sums
        return l + r;
    }

    // Main function to calculate the total sum of all root-to-leaf paths
    int sumNumbers(TreeNode* root) {
        // Call the helper function with initial sum 0
        return solve(root, 0);
    }
};
