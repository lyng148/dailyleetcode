/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if (head == NULL || head->next == NULL){
        return head;
    }
    if (left == right) return head;
    int i = 0;
    node* start = head;
    node *prev_left = NULL;
    while (i < left - 1){
        prev_left = head;
        head = head->next;
        i++;
    }
    node *curr = head->next;
    node *prev = head;
    node* head_reverse = head;
    while (i < right - 1){
        node *Nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Nextnode; 
        i++;                 
    }
    if (prev_left != NULL){
        prev_left->next = prev;
    }
    head_reverse->next = curr;
    if (prev_left == NULL) return prev;
    else return start;
}
    