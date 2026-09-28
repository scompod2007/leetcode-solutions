#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    // Advance fast pointer n steps ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // If fast reached past the end, head itself is the nth node from the end
    if (!fast) {
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }

    // Move both pointers until fast reaches the last node
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    // Unlink and free the target node
    struct ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    free(toDelete);

    return head;
}