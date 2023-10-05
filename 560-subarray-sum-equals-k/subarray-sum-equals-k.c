#define SIZE 50000

typedef struct node
{
    int key;
    int value;
} node;

node *Makenode(int key, int value)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->key = key;
    Newnode->value = value;
    return Newnode;
}

int hashCode(int key)
{
    int r = key % SIZE;
    return r < 0 ? r + SIZE : r;
}

node *search(node **hashArr, int key)
{

    // Get the hashCode
    int hashIndex = hashCode(key);

    while (hashArr[hashIndex] != NULL)
    {
        if (hashArr[hashIndex]->key == key)
            return hashArr[hashIndex];
        hashIndex++;
        hashIndex %= SIZE;
    }

    return NULL;
}

void insert(node **hashArr, int key, int value)
{
    node *Newnode = Makenode(key, value);

    int hashIndex = hashCode(key);

    while (hashArr[hashIndex] != NULL && hashArr[hashIndex]->key != key)
    {
        hashIndex++;
        // run in size of table
        hashIndex %= SIZE;
    }
    if (hashArr[hashIndex] == NULL)
    {
        hashArr[hashIndex] = Newnode;
        return;
    }
    else
    hashArr[hashIndex]->value++;
}

// delete function, return deleted node

node *deletee(node **hashArr, int key)
{
    int hashIndex = hashCode(key);
    while (hashArr[hashIndex] != NULL)
    {
        if (hashArr[hashIndex]->key == key)
        {
            node *tmp = hashArr[hashIndex];
            hashArr[hashIndex]->key = -1;
            hashArr[hashIndex]->value = -1;
            return tmp;
        }
        hashIndex++;
        hashIndex %= SIZE;
    }
    return NULL;
}

int subarraySum(int* nums, int numsSize, int m){

    int *prefix = (int *)malloc(numsSize * sizeof(int));
    prefix[0] = nums[0];

    int ans = 0;
    for (int i = 1; i < numsSize; i++)
    {
        prefix[i] = nums[i] + prefix[i - 1];
    }

    node *hashArr[SIZE];
    memset(hashArr, 0, sizeof(hashArr));

    insert(hashArr, 0, 1);

    for (int i = 0; i < numsSize; i++)
    {
        node *k = search(hashArr, prefix[i] - m);
        if (k != NULL) 
        {
            ans += k->value;
        }
        insert(hashArr, prefix[i], 1);
    }
    return ans;
}