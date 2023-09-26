/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;

struct ListNode* removeElements(struct ListNode* head, int val){
    node *start = head;
    if (head == NULL) return head;
    while(head->val == val && head->next != NULL)
    {
        head = head->next;
        start = head;
    }
    if (head->val == val && head->next == NULL)
    {
        return NULL;
    }

    while (head->next != NULL)
    {
        if (head->next->val == val)
        {
            node *tmp = head->next;
            head->next = head->next->next;
            free(tmp);
        }
        else head = head->next;
    }
    return start;
}