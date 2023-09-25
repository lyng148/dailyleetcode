/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;
struct ListNode* deleteDuplicates(struct ListNode* head){
    node *start = head;
    if (head == NULL) return head;
    if (head->next != NULL && head->next->val == head->val)
    {
        head->next == NULL;
    } 
    while (head->next != NULL)
    {
        if (head->next->val == head->val)
        {
            head->next = head->next->next;
        }
        else head = head->next;
    }
    return start;    
}