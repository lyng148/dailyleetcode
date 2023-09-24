/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;

node *makenode(int val)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}

struct ListNode* mergeTwoLists(struct ListNode* head1, struct ListNode* head2) {
    node *head = NULL;
    node *tmp = NULL;
    
    while (head1 != NULL && head2 != NULL) {
        if (head1->val <= head2->val) {
            node* next = makenode(head1->val);
            if (tmp == NULL) { //Must check because it's the first node of linked list
                head = next;   //Without could cause runtime error: member access within null pointer
                tmp = head;    // of type 'struct node' [solution.c]
            } else {
                tmp->next = next;
                tmp = tmp->next;
            }
            head1 = head1->next;
        } else {
            node* next = makenode(head2->val);
            if (tmp == NULL) {
                head = next;
                tmp = head;
            } else {
                tmp->next = next;
                tmp = tmp->next;
            }
            head2 = head2->next;
        }
    }

    while (head1 != NULL) {
        node* next = makenode(head1->val);
        if (tmp == NULL) {
            head = next;
            tmp = head;
        } else {
            tmp->next = next;
            tmp = tmp->next;
        }
        head1 = head1->next;
    }

    while (head2 != NULL) {
        node* next = makenode(head2->val);
        if (tmp == NULL) {
            head = next;
            tmp = head;
        } else {
            tmp->next = next;
            tmp = tmp->next;
        }
        head2 = head2->next;
    }

    return head;
}
