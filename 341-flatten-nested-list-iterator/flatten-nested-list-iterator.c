/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */
typedef struct INT_NODE
{
    struct INT_NODE* next;
    int val;
} INT_NODE;

typedef struct NestedIterator {
    INT_NODE* next;
    INT_NODE* head;
    INT_NODE* tail;
    int val;
} NODE;

void nestedIterCreateInt(struct NestedInteger** nestedList, int nestedListSize, NODE* headNode)
{
    for (int i = 0; i < nestedListSize; i++)
    {
        if (NestedIntegerIsInteger(nestedList[i]))
        {
            INT_NODE* t = malloc(sizeof(INT_NODE));
            t->next = NULL;

            if (headNode->tail)
            {
                headNode->tail->next = t;
                headNode->tail = t;
            }
            else
                headNode->next = headNode->head = headNode->tail = t;

            t->val = NestedIntegerGetInteger(nestedList[i]);
        }
        else
        {
            nestedIterCreateInt(NestedIntegerGetList(nestedList[i]), NestedIntegerGetListSize(nestedList[i]), headNode);
        }
    }
}

struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize) 
{
    NODE * headNode = malloc(sizeof(NODE));
    headNode->next = headNode->head = headNode->tail = NULL;

    nestedIterCreateInt(nestedList, nestedListSize, headNode);
    return headNode;
}

bool nestedIterHasNext(struct NestedIterator *iter) {
    if (iter->next)
    {
        INT_NODE* inode = iter->next;

        iter->val = inode->val;
        iter->next = iter->next->next;
        return true;
    }

    return false;
}

int nestedIterNext(struct NestedIterator *iter) {
    return iter->val;
}

/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter) 
{
    INT_NODE* next;
    for (INT_NODE* curr = iter->head; curr; curr = next)
    {
        next = curr->next;
        free(curr);
    }

    free(iter);
}

/**
 * Your NestedIterator will be called like this:
 * struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize);
 * while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i));
 * nestedIterFree(i);
 */