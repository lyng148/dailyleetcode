/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;

bool hasCycle(struct ListNode *head) {
    node* slow = head;
    node* fast = head;
    while (head != NULL && head->next != NULL){
        slow = slow->next;
        head = head->next->next;
        if (head == slow) return true;
    }
    return false;
}