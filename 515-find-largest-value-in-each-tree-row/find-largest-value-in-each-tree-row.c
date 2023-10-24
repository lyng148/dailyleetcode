typedef struct TreeNode TreeNode;

typedef struct Node
{
    TreeNode *treeNode;
    struct Node *next;
    struct Node *prev;
} node;

typedef struct Queue
{
    node *head; // head co nvu giu node dau cua queue (dslk)
    node *tail;
} queue;

node *MakeNode(TreeNode *t)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->treeNode = t;
    Newnode->next = NULL;
    Newnode->prev = NULL;
    return Newnode;
}

queue *initQueue()
{
    queue *Newqueue = (queue *)malloc(sizeof(queue));
    Newqueue->head = NULL;
    Newqueue->tail = NULL;
    return Newqueue;
}

bool queueEmpty(queue *q)
{
    return q->head == NULL && q->tail == NULL;
}

void queuePush(queue *q, TreeNode *TreeNode)
{
    node *node = MakeNode(TreeNode);
    if (queueEmpty(q))
    {
        q->head = node;
        q->tail = node;
    }
    else
    {
        q->tail->next = node;
        node->prev = q->tail; // Minh se noi node moi khi them vao
        q->tail = node;       // vao cuoi cua tail va cap nhat tail
    }
}

node *queuePop(queue *q)
{
    if (queueEmpty(q))
    {
        return NULL;
    }
    node *v = q->head;
    q->head = q->head->next;
    if (q->head == NULL)
        q->tail = NULL;
    return v;
}

int queueSize(queue *q)
{
    node *tmp = q->head;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

void printBFS(TreeNode *root, int *a, int *idx)
{
    queue *q = initQueue();
    queuePush(q, root);
    while (!queueEmpty(q))
    {
        int nodesInCurrentLevel = queueSize(q);
        int sum = 0;
        int max = INT_MIN;
        for (int i = 0; i < nodesInCurrentLevel; i++)
        {
            node *v = queuePop(q);
            // print node data
            if (v->treeNode->val > max) max = v->treeNode->val;

            // add children node to queue
            if (v->treeNode->left != NULL)
            {
                queuePush(q, v->treeNode->left);
            }
            if (v->treeNode->right != NULL)
            {
                queuePush(q, v->treeNode->right);
            }
        }
        a[(*idx)++] = max;
    }
}

int* largestValues(struct TreeNode* root, int* returnSize){
    int *a = (int*)malloc(10001 * sizeof(int));
    int idx = 0;
    if (root == NULL)
    {
        *returnSize = 0;
        return a;
    }
    printBFS(root, a, &idx);
    *returnSize = idx;
    return a;
}