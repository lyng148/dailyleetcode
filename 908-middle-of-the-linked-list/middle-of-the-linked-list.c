/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* rua = head;
    struct ListNode* tho = head;
    int i = 0;
    while (tho != NULL && tho->next != NULL)
    {
        i++;
        rua = rua->next;
        tho = tho->next->next;
    }
    
    return rua;
}