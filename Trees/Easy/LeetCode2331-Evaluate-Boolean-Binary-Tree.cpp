/*
LeetCode 2331. Evaluate Boolean Binary Tree

Approach:
> At each node, it recursively evaluates the right and left subtrees.
> Leaf Node Handling: When the function reaches a leaf node it simply returns the value of that node.
> Logical Operations: For non-leaf nodes, it performs logical operations based on the value of the current node. If the node's value is 2, it performs OR operation between the values of the right and left subtrees. Otherwise, it performs AND operation.
*/

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        // Base case: if the node is a leaf (both left and right children are NULL), return its value
        if(root->right == NULL && root->left == NULL) {
            // Leaf node, return its value
            return root->val;
        }
        
        // Recursively evaluate the right and left subtrees
        int right_value = evaluateTree(root->right);
        int left_value = evaluateTree(root->left);
        
        // If the current node's value is 2, perform bitwise OR operation
        if(root->val == 2) {
            return right_value | left_value;
        }
        // If the current node's value is not 2, perform bitwise AND operation
        return right_value & left_value;
    }
};
