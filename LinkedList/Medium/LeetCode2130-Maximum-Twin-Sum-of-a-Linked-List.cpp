/*
LeetCode 2130. Maximum Twin Sum of a Linked List
Approach:
> Find the Midpoint: Use the slow and fast pointer technique to find the midpoint of the linked list.
> Reverse the Second Half: Reverse the second half of the linked list starting from the midpoint.
> Calculate Twin Sums: Traverse the first half and the reversed second half simultaneously, calculating the sum of corresponding nodes and updating the maximum sum.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // Function to reverse the linked list
    ListNode* reverseList(ListNode* head) {
        // Base case: if head is NULL or there's only one node, return head
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Recursive case: reverse the rest of the list
        ListNode* last = reverseList(head->next);

        // Adjust the pointers for current node
        head->next->next = head;
        head->next = NULL;

        // Return the new head of the reversed list
        return last;
    }

    // Function to find the maximum twin sum in the linked list
    int pairSum(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return 0; // If the list is empty or has only one node, return 0
        }

        // Initialize slow and fast pointers to find the midpoint
        ListNode* slow = head;
        ListNode* fast = head;

        // Move slow pointer one step and fast pointer two steps at a time
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list starting from the midpoint
        ListNode* temphead = reverseList(slow);

        int maxSum = 0;

        // Traverse the first half and the reversed second half simultaneously
        while (temphead != NULL) {
            // Calculate the sum of corresponding nodes
            maxSum = max(maxSum, head->val + temphead->val);
            head = head->next;
            temphead = temphead->next;
        }

        // Return the maximum twin sum
        return maxSum;
    }
};