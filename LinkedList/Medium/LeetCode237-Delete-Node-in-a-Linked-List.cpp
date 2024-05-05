/*
237. Delete Node in a Linked List

There is a singly-linked list head and we want to delete a node node in it.You are given the node to be deleted node. You will not be given access to the first node of head.

Approach:
> Since we are given access only to the node to be deleted, and not the head of the linked list, we can't directly remove the node by traversing the list from the beginning. Instead, we can manipulate the pointers of the given node and the next node to effectively "remove" the current node.
> Copy and Delete: To delete the given node without having access to the previous node, we can copy the value of the next node into the current node, effectively overwriting the current node's value with the next node's value. Then, we can modify the current node's next pointer to skip the next node, effectively removing it from the linked list.
> Memory Management (Optional): Depending on the specific requirements or constraints of the problem, we may choose to deallocate the memory occupied by the next node that we're effectively removing. However, in a garbage-collected environment or when memory management is handled elsewhere, this step may be unnecessary.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    void deleteNode(ListNode* node) {
        // Store the next node temporarily
        struct ListNode* temp = node->next;
        // Copy the value of the next node to the current node
        node->val = node->next->val;
        // Point the current node to the node after the next node, effectively skipping the next node
        node->next = node->next->next;
        // Deallocate memory for the next node (optional depending on usage)
        // Note: Since this is most likely a singly-linked list, freeing the memory might not be necessary
        // free(temp);
        // Set the temporary pointer to NULL to avoid any dangling pointer issues
        temp = NULL;
    }
};
