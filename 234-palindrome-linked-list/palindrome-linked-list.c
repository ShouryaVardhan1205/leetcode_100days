/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    // Step 1: Find middle
    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    struct ListNode* secondHalf = reverse(slow->next);

    // Step 3: Compare both halves
    struct ListNode* firstHalf = head;
    struct ListNode* temp = secondHalf;
    
    while (temp != NULL) {
        if (firstHalf->val != temp->val)
            return false;
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    return true;
}