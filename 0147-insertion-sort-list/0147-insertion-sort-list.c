/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* insertionSortList(struct ListNode* head) {
    // Dummy node helps us insert elements at the beginning easily
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* current = head;

    while (current != NULL) {
        // Save the next node before changing current->next
        struct ListNode* nextNode = current->next;

        // Find the correct position in the sorted list
        struct ListNode* prev = &dummy;

        while (prev->next != NULL && prev->next->val < current->val) {
            prev = prev->next;
        }

        // Insert current at the correct position
        current->next = prev->next;
        prev->next = current;

        // Move to the next unsorted node
        current = nextNode;
    }

    return dummy.next;
}